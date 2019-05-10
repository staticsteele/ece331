#!/usr/bin/python

#Script fetches webpage and writes it to file

import urllib, sys

#checks command line arguements
if len(sys.argv) != 2:
    sys.exit("Usage: "+sys.argv[0]+" url")

#Retrieves webpage and writes it to test.txt
urllib.urlretrieve(sys.argv[1],"test.txt")


