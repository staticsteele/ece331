#!/usr/bin/python

#Steele Muchemore-Allen ECE 331 Decoder
#New to python, most likely not the best way to handle problem

import sys
import re


str = sys.stdin.readline()

#Returns error if str is less than 16(1 char) or not evenly divisible by 4
if ((len(str)-1)%4 != 0) or ((len(str)-1) < 16):
    sys.exit("Can not decode string (length)")

newstr = ''

#Loops for 1/4 of the length of encoded string
for x in range(len(str)/4):


    #If the first 4 bits match, remove them from string
    #and add the orginal corresponding decoded bits to a new string
    if re.match(r'1010',str):
        str = re.sub(r'^1010',"",str)
        newstr += "00"

    elif re.match(r'0101',str):
        str = re.sub(r'^0101',"",str)
        newstr += "01"

    elif re.match(r'1001',str):
        str = re.sub(r'^1001',"",str)
        newstr += "10"

    elif re.match(r'0110',str):
        str = re.sub(r'^0110',"",str)
        newstr += "11"
    else:
        sys.exit("Can not decode string (undefined patterns).")

#Splits new decoded binary string into 8 bit chunks
#Converts these chunks to ASCII values and them combines
#them all back into one string when complete
x =''.join(chr(int(newstr[i:i+8],2)) for i in xrange(0, len(newstr), 8))

print x

