#Dual-purpose code: i) can create input.txt files containing all the CAF files, ii) can run slimming jobs on those CAF inputs.
#!/usr/bin/python
import sys, os
from makeListCAFRoot import make_input

#====================================
#dslist =['185721'] ##TEST
#dslist =['periodA.physics_Egamma'] ##TEST
#systlist =["Nominal"]

#dslist = ['110101','110119','110140','117050','145161','145162','146434','146435','146436','146437','146438','146439','147770','147771','147772','147774','147775','147776','167740','167741','167742','167743','167744','167745','167746','167747','167748','167761','167762','167763','167764','167765','167766','167767','167768','167769','167770','167771','167772','167773','167774','167775','167776','167777','167778','167779','167780','167781','167782','167783','167784','167785','167786','167787','167788','167789','167790','167791','167792','167793','167794','167795','167796','167797','167798','167799','167800','167801','167802','167803','167804','167805','167809','167810','167811','167812','167813','167814','167815','167816','167817','167821','167822','167823','167824','167825','167826','167827','167828','167829','167833','167834','167835','167836','167837','167838','167839','167840','167841','177997','179974','179975','180534','180535','180536','180537','180538','180539','180540','180541','180542','183585','183586','183587','183588','183589','183590','183734','183735','183736','183737','183738','183739'] # 33 samples + 81 pt sliced + 9 pt0 --> total 123 samples

#dslist = ['145161','145162','146434','146435','146436','146437','146438','146439','167740','167741','167742','167743','167744','167745','167746','167747','167748','167761','167762','167763','167764','167765','167766','167767','167768','167769','167770','167771','167772','167773','167774','167775','167776','167777','167778','167779','167780','167781','167782','167783','167784','167785','167786','167787','167788','167789','167790','167791','167792','167793','167794','167795','167796','167797','167798','167799','167800','167801','167802','167803','167804','167805','167809','167810','167811','167812','167813','167814','167815','167816','167817','167821','167822','167823','167824','167825','167826','167827','167828','167829','167833','167834','167835','167836','167837','167838','167839','167840','167841','177997','179974','179975','180534','180535','180536','180537','180538','180539','180540','180541','180542','183585','183586','183587','183588','183589','183590','183734','183735','183736','183737','183738','183739'] # 113 samples (except the 10 big ones)

#dslist= ['110101','110119','110140','147770','147771','147772','147774','147775','147776'] #9 big ones (except 117050 which needs .2)

#dslist =['185721','185722','185723','185724','185725','185726','185727','185728','185729','185730','185731','185732','185733','185734','185735','185736','185737','185738','185739','185740','185741','185742','185743','185744','185745','185746','185747','185748','185749','185750','185751','185752','185753','185754','185755','185756','185757','185758','185759','185760','185761','185762','185763','185764','185765','185766','185767','185768','185769','185770','185771','185772','185773','185774','185775','185776','185777','185778','185779','185780','185781','185782','185783','185784','185785','185786','185787','185788','185789','185790','185791','185792','185793','185794'] #74 signal samples


#dslist=['167740','167741','167742','167743','167744','167745','167746','167747','167748']

#<<<<<<<<<<<<< Data samples >>>>>>>>>>>>>>>>>>
#dslist= ['periodA.physics_Egamma','periodA.physics_Muons','periodB.physics_Egamma','periodB.physics_Muons','periodC.physics_Egamma','periodC.physics_Muons','periodD.physics_Egamma','periodD.physics_Muons','periodE.physics_Egamma','periodE.physics_Muons','periodG.physics_Egamma','periodG.physics_Muons','periodH.physics_Egamma','periodH.physics_Muons','periodI.physics_Egamma','periodI.physics_Muons','periodJ.physics_Egamma','periodJ.physics_Muons','periodL.physics_Egamma','periodL.physics_Muons'] 
#some data samples might have too many files to store in one input.txt file)
#dslist= ['periodB.physics_Muons','periodD.physics_Egamma','periodJ.physics_Egamma','periodJ.physics_Muons']
#dslist= ['periodB.physics_Muons']
#systlist =["Nominal.1","Nominal.2"]
#dslist= ['periodB.physics_Egamma']
#systlist =["Nominal.2","Nominal.3"]

#dslist= ['117050']
#systlist =["JERUp.1","JERUp.2","NP_Special2JESUp.1","NP_Special2JESUp.2","NP_Special3JESUp.1","NP_Special3JESUp.2","NP_Special4JESUp.1","NP_Special4JESUp.2","NP_Special5JESUp.1","NP_Special5JESUp.2","Eta_ModellingJESUp.1","Eta_ModellingJESUp.2","Eta_TotStatJESUp.1","Eta_TotStatJESUp.2","HighPtJESUp.1","HighPtJESUp.2","MuJESUp.1","MuJESUp.2","NPVJESUp.1","NPVJESUp.2","PilePtJESUp.1","PilePtJESUp.2","PileRhoJESUp.1","PileRhoJESUp.2","FlavCompJESUp.1","FlavCompJESUp.2","FlavRespJESUp.1","FlavRespJESUp.2","bJESUp.1","bJESUp.2"]

#systlist =["NP_Special1JESDown.1","NP_Special1JESDown.2","NP_Special2JESDown.1","NP_Special2JESDown.2","NP_Special3JESDown.1","NP_Special3JESDown.2","NP_Special4JESDown.1","NP_Special4JESDown.2","NP_Special5JESDown.1","NP_Special5JESDown.2","Eta_ModellingJESDown.1","Eta_ModellingJESDown.2","Eta_TotStatJESDown.1","Eta_TotStatJESDown.2","HighPtJESDown.1","HighPtJESDown.2","MuJESDown.1","MuJESDown.2","NPVJESDown.1","NPVJESDown.2","PilePtJESDown.1","PilePtJESDown.2","PileRhoJESDown.1","PileRhoJESDown.2","FlavCompJESDown.1","FlavCompJESDown.2","FlavRespJESDown.1","FlavRespJESDown.2","bJESDown.1","bJESDown.2"]

#######################################################
###batch VBS_3.25 
#dslist =[ '145161', '145162', '146434', '146435', '146436', '146437', '146438', '146439', '147770', '147771', '147772',  '167740','167741','167742','167743','167744','167745','167746','167747','167748','167761', '167762', '167763', '167764', '167765', '167766', '167767', '167768', '167769', '167770', '167771', '167772', '167773', '167774', '167775', '167776', '167777', '167778', '167779','167780', '167781', '167782', '167783', '167784', '167785', '167786', '167787', '167788', '167789', '167790', '167791', '167792', '167793', '167794', '167795', '167796', '167797', '167798', '167799', '167800', '167801', '167802', '167803', '167804', '167805', '167809', '167810', '167811', '167812', '167813', '167814', '167815', '167816', '167817', '167821', '167822', '167823', '167824', '167825', '167826', '167827', '167828', '167829', '167833', '167834', '167835', '167836', '167837', '167838', '167839', '167840', '167841', '177997', '179974', '179975', '180534', '180535', '180536', '180537', '180538', '180539', '180540', '180541', '180542', '180544', '180546', '180547', '180548', '180550', '183585', '183586', '183587', '183588', '183589', '183590', '183734', '183735', '183736', '183737', '183738', '183739']
#dslist = ['110101', '110119', '110140', '185721', '185722', '185723', '185724', '185725', '185726', '185727', '185728', '185729', '185730', '185731', '185732', '185733', '185734', '185735', '185736', '185737', '185738', '185739', '185740', '185741', '185742', '185743', '185744', '185745', '185746', '185747', '185748', '185749', '185750', '185751', '185752', '185753', '185754', '185755', '185756', '185757', '185758', '185759', '185760', '185761', '185762', '185763', '185764', '185765', '185766', '185767', '185768', '185769', '185770', '185771', '185772', '185773', '185774', '185775', '185776', '185777', '185778', '185779', '185780', '185781', '185782', '185783', '185784', '185785', '185786', '185787', '185788', '185789', '185790', '185791', '185792', '185793', '185794', 'periodA.physics_Egamma', 'periodA.physics_Muons',  'periodC.physics_Egamma', 'periodC.physics_Muons',  'periodD.physics_Muons', 'periodE.physics_Egamma', 'periodE.physics_Muons', 'periodG.physics_Egamma', 'periodG.physics_Muons', 'periodH.physics_Egamma', 'periodH.physics_Muons', 'periodI.physics_Egamma', 'periodI.physics_Muons',  'periodL.physics_Egamma', 'periodL.physics_Muons']
#dslist = ['117050','periodB.physics_Egamma', 'periodB.physics_Muons','periodD.physics_Egamma','periodJ.physics_Egamma', 'periodJ.physics_Muons'] #["Nominal.1","Nominal.2"]

#dslist = ['185741']




###################
##batch 4.1
##on sbahead =====
#dslist =['145161', '145162','146435','146436','146437','146438','146439','167740', '167741', '167742', '167743', '167744', '167745', '167746', '167747', '167748', '167749', '167750', '167751', '167752', '167753', '167754', '167755', '167756', '167757', '167761', '167762', '167763', '167764', '167765', '167766', '167767', '167768', '167769', '167770', '167771', '167772', '167773', '167774', '167775', '167776', '167777', '167778', '167779', '167780', '167781', '167782', '167783', '167784', '167785', '167786', '167787','167788', '167789', '167790', '167791', '167792', '167793', '167794', '167795', '167796', '167797', '167798', '167799','167800', '167801', '167802', '167803', '167804', '167805', '167809', '167810', '167811', '167812', '167813', '167814', '167815', '167816', '167817', '167821', '167822', '167823', '167824', '167825', '167826', '167827', '167828', '167829', '167833', '167834', '167835', '167836', '167837', '167838','167839', '167840', '167841',  '177997', '179974', '179975', '180534', '180535', '180536', '180537', '180538','180539', '180540', '180541', '180542', '183585', '183586', '183587', '183588', '183589', '183590', '183734', '183735', '183736', '183737', '183738', '183739','185721', '185753' ]

#dslist=['185722','185724','185726','185733','185750','185751','185754','185756','185757','185758','185759','185761','185763','185770','185787','185788','185790','185791','185793','185794']

#dslist =['110101', '110119', '110140','periodA.physics_Egamma', 'periodA.physics_Muons', 'periodC.physics_Egamma', 'periodC.physics_Muons',  'periodD.physics_Muons', 'periodE.physics_Egamma', 'periodE.physics_Muons', 'periodG.physics_Egamma', 'periodG.physics_Muons', 'periodH.physics_Egamma', 'periodH.physics_Muons', 'periodI.physics_Egamma', 'periodI.physics_Muons', 'periodL.physics_Egamma', 'periodL.physics_Muons']

#dslist= ['117050'] #["Nominal.1","Nominal.2"]
#dslist= ['117050','periodB.physics_Egamma','periodB.physics_Muons','periodJ.physics_Egamma','periodJ.physics_Muons','periodD.physics_Egamma']  #["Nominal.1","Nominal.2"]

## These were downloaded to scratch1 =====

#dslist=['185723', '185725', '185727', '185728', '185729', '185730', '185731', '185732', '185734', '185735', '185736', '185737', '185738', '185739', '185740', '185742', '185743', '185744', '185745', '185746', '185747', '185748', '185749', '185752', '185755', '185760', '185762', '185764', '185765', '185766', '185767', '185768', '185769', '185771', '185772', '185773', '185774', '185775', '185776', '185777', '185778', '185779', '185780', '185781', '185782', '185783', '185784', '185785', '185786', '185789', '185792', '207266', '207267', '207268', '207269', '207270', '207271', '207272', '207273', '207274', '207275', '207276', '207277', '207278', '207279', '207280', '207281']
####=====
#systlist =["Nominal"]
#systlist =["Nominal.1","Nominal.2"]



###################
##batch 4.2
## These were downloaded to scratch1 =====
#dslist =['periodA.physics_Egamma', 'periodA.physics_Muons', 'periodC.physics_Egamma', 'periodC.physics_Muons',  'periodE.physics_Egamma', 'periodE.physics_Muons', 'periodG.physics_Egamma', 'periodG.physics_Muons', 'periodH.physics_Egamma', 'periodH.physics_Muons', 'periodI.physics_Egamma', 'periodI.physics_Muons', 'periodL.physics_Egamma', 'periodL.physics_Muons']
#systlist =["Nominal"]
#dslist= ['periodB.physics_Muons','periodD.physics_Egamma','periodD.physics_Muons','periodJ.physics_Egamma','periodJ.physics_Muons']
#systlist =["Nominal.1","Nominal.2"]
#dslist= ['periodB.physics_Egamma']
#systlist =["Nominal.1","Nominal.2","Nominal.3"]


####################################################
##batch 3.32 for  fat jet systematics studies
#dslist=['183735']
#dslist=['110101', '110119', '110140', '117050', '145161', '145162', '146435', '146436', '146437', '146438', '146439', '147770', '147771', '147772', '167740', '167741', '167742', '167743', '167744', '167745', '167746', '167747', '167748', '167761', '167762', '167763', '167764', '167765', '167766', '167767', '167768', '167769', '167770', '167771', '167772', '167773', '167774', '167775', '167776', '167777', '167778', '167779', '167780', '167781', '167782', '167783', '167784', '167785', '167786', '167787', '167788', '167789', '167790', '167791', '167792', '167793', '167794', '167795', '167796', '167797', '167798', '167799', '167800', '167801', '167802', '167803', '167804', '167805', '167809', '167810', '167811', '167812', '167813', '167814', '167815', '167816', '167817', '167821', '167822', '167823', '167824', '167825', '167826', '167827', '167828', '167829', '167833', '167834', '167835', '167836', '167837', '167838', '167839', '167840', '167841', '177997', '179974', '179975', '180534', '180535', '180536', '180537', '180538', '180539', '180540', '180541', '180542', '183585', '183586', '183587', '183588', '183589', '183590', '183734', '183735', '183736', '183737', '183738', '183739']

#systlist =["FatJESUp","FatJMRUp","FatJPTRUp","JMSUp"]

###############

#dslist =['129915','129916','129917']
#systlist =["Nominal"]

#systlist =["JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"]

#systlist =["NP_Special1JESDown","NP_Special2JESDown","NP_Special3JESDown","NP_Special4JESDown","NP_Special5JESDown","Eta_ModellingJESDown","Eta_TotStatJESDown","HighPtJESDown","MuJESDown","NPVJESDown","PilePtJESDown","PileRhoJESDown","FlavCompJESDown","FlavRespJESDown","bJESDown"]

#systlist =["FatJESUp", "JMSUp", "FatJPTRUp", "FatJMRUp" ,   "ElecScaleUp","ElecResolutionUp","MSUP","IDUP",  "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard"]
#systlist =["FatJESUp","ElecScaleUp"]


#============================================

command =""

for dsId in dslist:
    for systname in systlist:
        #make_input(dsId,systname) # prepare the input...txt files
        #os.system("echo "+dsId+"; ls input."+dsId+".*.txt | wc -l")
        #os.system("ls input."+dsId+".*.txt | wc -l")
        #os.system("cp -p input.list.3.25/list."+dsId+".Nominal.txt input.list.3.25_sbahead/")
        if dsId.find("period") is not -1: #Data
            command = "./SkimSlimLvqqNtuple 0 "+dsId+" "+systname #for data
            #print command
        else:
            command = "./SkimSlimLvqqNtuple 1 "+dsId+" "+systname #for MC
            #print command
        #command+="for file in `ls -R user.auzaman.147771.Sherpa_CT10_Zmumu.VBS_3.291_outputFile.tar.25644586/*`; do xrdcp  -d 1 $file root://sbahead.physics.sunysb.edu//atlas/local/azaman/user/auzaman/147771/$file >> copy.log  2>&1 ; done;"
        
        #print command
        os.system(command) #Once you prepare the input...txt files, run slimming jobs
        pass

