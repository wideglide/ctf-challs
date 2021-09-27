## shrek solution

### method #1
decrypt the obsfucated code interactively in IDA.

General IDA Python decrypt script for a (section, key) pair

```python
ea = get_name_ea(BADADDR,'loc_8048A96')   
stop = pack('<L',0x0B501E7E)  
key = pack('<H',0x1EE7)  
while get_many_bytes(ea,4) != stop:  
  buf = get_many_bytes(ea,2)  
  b1 = chr(ord(buf[0]) ^ ord(key[0]))  
  b2 = chr(ord(buf[1]) ^ ord(key[1]))  
  buf = b1+b2  
  patch_many_bytes(ea, buf)  
  ea += 1  
```

IDA Python script to extract the key once the code is de-obsfucated:

```python
ea = get_name_ea(BADADDR,'auth')
l = []
while (ea < 0x8048b50):
  ea = idc.NextHead(ea)
  if GetMnem(ea) == "cmp" and GetOpnd(ea,0) == "al":
    print "%x" % GetOperandValue(ea,1),
    l.append( chr(GetOperandValue(ea,1)) )
print
print pack('>L',ea).encode("hex")
print ''.join(l)
```

### method #2
radare?
