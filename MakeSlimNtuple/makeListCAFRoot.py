##Create input.txt, a comma separated list of CAF files for slimming 
#!/usr/bin/python
import sys, os 
#basepath = "/export/scratch1/azaman/CAF/VBS_3.25"  ##HARD CODED
#basepath = "/export/scratch1/azaman/CAF/VBS_3.29"  ##HARD CODED
#basepath = "/export/scratch1/azaman/CAF/VBS_3.3"  ##HARD CODED
basepath = "/export/scratch1/azaman/CAF/VBS_4.2"  ##HARD CODED

#basepath = "/sbahead/atlas/local/azaman/CAF/VBS_3.25"  ##HARD CODED

def make_input (dsId, systname):
    fname = "input."+dsId+"."+systname+".txt" #list of files separated by a comma
    fname2 = "list."+dsId+"."+systname+".txt" #list of files separated by newline
    #fname = "input.4.2/input."+dsId+"."+systname+".txt" #list of files separated by a comma
    #fname2 = "input.4.2/list."+dsId+"."+systname+".txt" #list of files separated by newline
    f = open(fname,'w')
    f2 = open(fname2,'w')
        
    nfile =0
    for dirname, dirpath, filenames in os.walk(basepath):
        
        if dirname.find(dsId) != -1:
            #print dirname
            for filename in filenames:
                if filename.find(".root") != -1 and filename.find(systname) != -1:
                    #print os.path.join(dirname, filename)
                    f2.write(os.path.join(dirname, filename)+'\n') #list of files separated by newline
                    #'''
                    if (nfile<970):
                        f.write(os.path.join(dirname, filename)+',') ## there will be a comma at the end of last entry, you should use join instead
                        
                    elif (nfile ==970):
                        #f.write("\n----We have reached 970 files----\n")  #&&&&
                        f.write(os.path.join(dirname, filename)+',')
                        
                    elif (nfile <1900):
                        print "MORE THAN 970 FILENAMES WRITTEN!!! Open a new txt file !!!"
                        f.write(os.path.join(dirname, filename)+',') ## there will be a comma at the end of last entry
                        
                    elif (nfile ==1900):
                        #f.write("\n----We have reached 1900 files----\n")  #&&&&
                        f.write(os.path.join(dirname, filename)+',')
                        
                    else:
                        print "MORE THAN 1900 FILENAMES WRITTEN!!! Open TWO new txt files !!!"
                        f.write(os.path.join(dirname, filename)+',') ## there will be a comma at the end of last entry
                        
                    #'''
                    nfile = nfile+1
    print "Number of files for ", dsId ," is ", nfile 
    f.close()
    f2.close()
    
