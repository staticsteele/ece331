#!/usr/bin/python

#Steele Muchemore-Allen File Parser

import re, sys, fileinput

data = [0] * 6
avdata = [0] * 5

#Opens each file on command line and closes them once done processing
for line in fileinput.input(sys.argv[1:]):

    #makes a list of all occurances of only #'s'
    list = re.findall(r'[0-9]+', line)

    #Adds new found #'s to corresponding array index
    for n in range(len(list)):
        data[n] += int(list[n])

    #increments # of files parsed
    data[5] += 1

#closes sequence as a precaution
fileinput.close()

#Calculates average times converted to ms
for n in range(len(avdata)):
    avdata[n] = (data[n]/data[5])/1000.0

print("Average JPEG Load time: "+str(avdata[0])+" ms")
print("Average Convolve time: "+str(avdata[1])+" ms")
print("Average JPEG Combine time: "+str(avdata[2])+" ms")
print("Average JPEG Save time: "+str(avdata[3])+" ms")
print("Average Overall time: "+str(avdata[4])+" ms")





