#!/usr/bin/python
import sys, os
import re
from optparse import OptionParser



parser = OptionParser()
parser.add_option ('--inDS', action='store', type="string",dest='inputDS', help="Input datasets name")
parser.add_option ('-s', '--submit',  action='store_true', dest='submit', help="Option to submit")
(options, args) = parser.parse_args()

print options
print args

inputDS = options.inputDS

doMC=1

#tag="lhf02"
#tag="az"
#tag="az02" #Ntup_common for Alpgen-Pythia W+jets 
#tag="az03" #after adding bad lepton correction in slimming code on July 11
#tag="az3.3" #changed slimming code for new ntuples. Added jet_MV1 and ttbarWeight
#tag="az3.42" #3.4 and 3.5: Brian added some code for truth studies for signal samples (9/1/14)
#tag="az3.6" #more truth code. first svn version (10/1/14)
tag="az3.83t" # 3/2/15


outputDS=inputDS.strip("/").replace("group.phys-higgs.","")
outputDS=outputDS.replace("user.auzaman.","")
outputDS=outputDS.replace("_HWWSkimmedNTUP_lvqq.root","")

#print "inputDS = ", inputDS
#print "proto-outputDS = ", outputDS

#outputDS = re.sub(r"\.e.*_p[0-9]*", "", outputDS)



print outputDS
if outputDS.startswith("period") : doMC=0


#outputDS="user.haifeng." + str(outputDS) + "." + tag
outputDS="user.auzaman." + str(outputDS) + "." + tag
      
print "------------------------------------------------------"
print "inputDS      : ", inputDS
print "outputDS     : ", outputDS



Options = "--match \"*HWWSkimmedNTUP_lvqq.root*\"  --nGBPerJob=MAX   --outputs=lvqqMiniNtuple.root --noBuild --mergeOutput"
#BExe     = "--bexec \"make clean; make\""
Exec     = "make clean; make; echo %IN > input.txt; " + "./SkimSlimLvqqNtuple %d"%(doMC)
athenaTag = "--athenaTag=17.6.0.4,AtlasProduction,slc5,gcc43"
excludeFile = "--excludeFile=input.txt"
#excludeSite = "--excludedSite=FZU,IHEP,IFAE,BHAM_SL6,WEIZMANN-CREAM,DESY-ZN"
#excludeSite = "--excludedSite=FZU,IHEP,IFAE,BHAM_SL6,WEIZMANN-CREAM,DESY-ZN,ANALY_SHEF_SL6"
excludeSite = ""
command = " ".join(["prun", "--exec \"%s\""%(Exec), Options, athenaTag, excludeFile, excludeSite, "--inDS=%s"%(inputDS), "--outDS=%s"%(outputDS) ])

print "command      : ", command
print "------------------------------------------------------"



if not options.submit :
    print "You need to use -s --submit option"
    sys.exit()
else :    
    os.system(command)
    print "Job has been submitted "
        

    
