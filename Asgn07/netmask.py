#!/usr/bin/python

import re, sys

try:
	x=re.split(r'\.',sys.argv[1])
	if (len(x)>4):
		raise
	v=re.sub(r'0b',"",bin(int(x[0]))+bin(int(x[1]))+bin(int(x[2]))+bin(int(x[3])))
	if (len(re.split(r'1+',v))>2):
		raise
 	print "/{}".format(len(re.split(r'1',v))-1)
except:
	print "invalid netmask\nUsage: ",sys.argv[0],"netmask"
