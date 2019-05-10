#!/usr/bin/python

#Script finds word lengths in dictionary and plots their frequencies

from collections import Counter
import numpy as np
import matplotlib
matplotlib.use('GTKAgg') #Enables the correct backend to display figure
import matplotlib.pyplot as plt

lengths = []

#Reads lines in from words file and strips newlines
with open("/usr/share/dict/words") as f:
    content = f.readlines()
    content = [x.strip() for x in content]

#creates list of lengths of words above
for n in content:
    lengths.append(len(n))

#Finds one of the words with max length in lines retrieved
long = max(content, key=len)
print ("A word with the longest number of letters is "+long+".")

#Counter finds frequency of values in given list
labels, values = zip(*Counter(lengths).items())

#Makes in-order indexes based on home many word lengths we have
indexes = np.arange(len(labels))

width = 1

#Formats and plots histogram
plt.bar(indexes, values, width)
plt.xticks(indexes + width * 0.5, labels)
plt.ylabel('Number of words')
plt.xlabel('Length of words')
plt.title('Histogram of lengths of words in /usr/share/dict/words')
plt.show()
