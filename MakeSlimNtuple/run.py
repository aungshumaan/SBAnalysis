#!/usr/bin/python
import sys, os


#open a file for 'r'eading
#f = open('lvqqSampleList_2.21_VBFCPS-AFII.txt', 'r')
#f = open('lvqqSampleList_2.21.FinalProduction.txt', 'r')
#f = open('lvqqSampleList_2.21.FinalProduction_one.txt', 'r')
f = open('lvqqSampleList_run.txt', 'r')

content = f.readlines()   #returns a list containing all the lines in f
goodcontent=[]
#print "size of lines : ", len(content)

processedLine=1

for line in content:
   oneline=line.strip()   #strips whitespace from the line
   if not( oneline.startswith("#") or len(oneline) is 0):#lines that are empty or starting with '#' to be ignored
      goodcontent.append(oneline)

print "size of lines : ", len(goodcontent)
for line in goodcontent:
   print "\n Starting ", processedLine, " / ", len(goodcontent) , "\n"
   print "inDS : ", line
   os.system("python gridSubmit.py --submit --inDS="+line)
   processedLine=processedLine+1
   
