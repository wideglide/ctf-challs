#!/usr/bin/env python2

import mmap
import struct
import sys


def encode(binary, source):
    with open(source, "r") as fs:
        lines = fs.readlines()
        sigs = filter(lambda x: x.startswith('".equ sig'), lines)
        keys = filter(lambda x: x.startswith('".equ key'), lines)
        sigs = [x.strip().split(' ')[-2] for x in sigs]
        sigs = [struct.pack('<I', int(x, 16)) for x in sigs]
        keys = [x.strip().split(' ')[-2] for x in keys]
        keys = [int(x, 16) for x in keys]
        sections = [{'sig': sigs[i], 'key':keys[i]} for i in range(len(sigs))]
    with open(binary, "r+b") as f:
        data = mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_WRITE)
        for section in sections:
            compare = data.find(section['sig'])
            start = data.find(section['sig'], compare+1)
            end = data.find(section['sig'], start+1)
            section['addrs'] = (start, end)
            print("0x%x\t0x%x\t0x%x" % (compare, start, end))
        for section in sections:
            for i in range(section['addrs'][0]+len(section['sig']), section['addrs'][1]):
                new = struct.unpack('<h', data[i:i+2])[0] ^ section['key']
                try:
                    data[i:i+2] = struct.pack('<h', new)
                except:
                    print("error on key: [%x]" % section['key'])
                    break
        data.flush()
        data.close()


if (len(sys.argv) == 3):
    encode(sys.argv[1], sys.argv[2])
