# for cross compilation:
# run like following:
# CROSS_COMPILE=arm-linux-gnueabihf- BOOST_DIR=~/src/boost_1_63_0/boost_1_63_0 make

CXX = $(CROSS_COMPILE)g++
CC = $(CROSS_COMPILE)gcc

CFLAGS = -g -Wall
CXXFLAGS = -g -Wall -std=c++11
## remove "error: ‘sleep_for’ is not a member of ‘std::this_thread’"
CXXFLAGS += -D_GLIBCXX_USE_NANOSLEEP

ifneq ($(strip $(BOOST_DIR)),)
INCPATH = -I$(BOOST_DIR)
LDFLAGS = -L$(BOOST_DIR)/stage/lib
endif
LIBS = -lboost_system -lpthread

SRCS := $(wildcard *.cpp)
OBJS := $(subst .cpp,.o,$(SRCS))
TARGETS := $(subst .o,,$(OBJS))

.PHONY: all
$(TARGETS): $(OBJS)
	$(CXX) -o $@ $@.o $(LDFLAGS) $(LIBS)

%.o: %.cpp
	@echo ">> %.o: $@ , $< <<"
	$(CXX) $(CXXFLAGS) $(INCPATH) -o $@ -c $<

%.o: %.c
	@echo ">> %.o: $@ , $< <<"
	$(CC) $(CFLAGS) $(INCPATH)  -o $@ -c $<

all: $(TARGETS)

clean:
	rm -rf $(TARGETS) $(OBJS)
