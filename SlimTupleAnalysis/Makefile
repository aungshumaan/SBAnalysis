##########################################################################
# root variables
ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --libs) -lMinuit -lEG  #-lg2c 

# Programs
CXX          := g++
F77          = f77
CXXFLAGS     = -g -ggdb -Wall -fPIC -Wno-deprecated 
MY_CXXFLAGS  = -static
LDFLAGS      = -g 
SOFLAGS      = -shared 

# do yourself a favor, use gcc for linking, and not ld
LD           = CXX

# local Includes
INCDIR       = -Iinclude

# Assign or Add variables
CXXFLAGS    += $(ROOTCFLAGS)
CXXFLAGS    += $(INCDIR)
LIBS        += $(ROOTLIBS) 


SOURCES   = $(wildcard src/*.cxx)
OBJECTSRC = $(patsubst %.cxx, %.o, $(SOURCES)) 
OBJFINAL  = $(wildcard lib/*.o) $(OBJECTSRC) $(OBJOUTER)


hbb :  clean $(OBJECTSRC)
	$(CXX) $(OBJFINAL) -o bin/minihbb $(LDFLAGS) $(LIBS)


%.o : %.cxx
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $*.o 


.PHONY: clean cln print xemacs backup clnPM

clean :
	rm -f src/*.o bin/*
