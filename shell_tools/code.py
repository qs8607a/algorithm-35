#!/usr/bin/python
import urllib
import sys

f=file('query')
o=file('query_code','w')

while True:
	line=f.readline()
	if len(line) == 0:
		break
	o.write('%s\n'%(urllib.quote(line)))

o.close()
f.close()
