ROOTCFLAGS    = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --libs)
ROOTGLIBS     = $(shell root-config --glibs)

CXX           = g++
CXXFLAGS      =-I$(ROOTSYS)/include -O -Wall -fPIC -D__USE_XOPEN2K8
LD            = g++
LDFLAGS       = -g
SOFLAGS       = -shared

CXXFLAGS     += $(ROOTCFLAGS)
LIBS          = $(ROOTLIBS)
GLIBS         = $(ROOTGLIBS)

OBJS          = SkimSlimLvqqNtuple.o

SkimSlimLvqqNtuple: $(OBJS)
	$(CXX) -o $@ $(OBJS) $(CXXFLAGS) $(LIBS)

# suffix rule
.cc.o:
	$(CXX) -c $(CXXFLAGS) $(GDBFLAGS) $<

# clean
clean:
	rm -f  SkimSlimLvqqNtuple  *~ *.o *.o~ 
