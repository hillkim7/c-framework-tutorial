OMNIIDL := omniidl 
DEPENDFLAGS := -g 
CXX := g++
CXXFLAGS := $(DEPENDFLAGS) -Wall -Werror -ansi
LDFLAGS := -lomniORB4 -lomnithread

# variable to hold the list of idl files,
# and then use a substitution reference to get the list of object files:
IDLS := $(wildcard *.idl)
OMNI_OBJS := $(wildcard *SK.o)

all: $(IDLS:%.idl=%SK.o) stringified_server stringified_client

stringified_server: stringified_server.o $(OMNI_OBJS)
	$(CXX) stringified_server.o $(OMNI_OBJS) $(LDFLAGS) -o $@

stringified_client: stringified_client.o $(OMNI_OBJS)
	$(CXX) stringified_client.o $(OMNI_OBJS) $(LDFLAGS) -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o : %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.hh %SK.cc : %.idl
	$(OMNIIDL) -bcxx $<

clean :
	rm -rf *.o

