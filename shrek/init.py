#!/usr/bin/env python

tmp = 'abcdefghijklmnopqrstuvwxyzABCDEF'
flag = 'flag{_On10ns_aRe_a_ta57y_tR3a7_}'

with open('template.c', 'r') as f:
    text = f.read()
    for i in range(len(flag)):
        text = text.replace("'_"+tmp[i] + "_'", "'"+flag[i]+"'")

with open('shrek.c', 'w') as f:
    f.write(text)
