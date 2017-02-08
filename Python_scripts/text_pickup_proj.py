#!/usr/bin/python

import os
import re
import sys
import string

src_dir = "/home/prasadk27/Desktop/ECE_611/project/output_files_all/"			#Provide path here
filelist = os.listdir(src_dir)
data = []

for file in filelist:
	path = os.path.join(src_dir,file)
	data.append(file)
	f = open(path,"r")
	extr_tuple = re.findall(r'(IPC:)\s+([\d.]+)',f.read())
	for m in extr_tuple:
		ext = m[1]
		data.append(ext)
	f.close()

out_file = os.path.join(src_dir,"summary.txt")
outf = open(out_file,'w')
for i in data:
	outf.write("%s\n" % i)
outf.close()
		
