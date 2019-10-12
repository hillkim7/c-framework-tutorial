# for cross compilation:
# run like following:
# CROSS_COMPILE=arm-linux-gnueabihf- BOOST_DIR=~/src/boost_1_63_0/boost_1_63_0 make
## install 
# sudo apt-get install libcurl4-openssl-dev

CXX = $(CROSS_COMPILE)g++

TARGETS= asiohiper

CFLAGS = -g -Wall

ifneq ($(strip $(BOOST_DIR)),)
INCPATH = -I$(BOOST_DIR)
LDFLAGS = -L$(BOOST_DIR)/stage/lib
CFLAGS += $(INCPATH)
## remove "error: ‘sleep_for’ is not a member of ‘std::this_thread’"
CFLAGS += -D_GLIBCXX_USE_NANOSLEEP
endif
CURL_LIB = -lcurl
LOG_LIB = -lboost_atomic -lboost_chrono -lboost_date_time -lboost_regex -lboost_filesystem -lboost_thread -lboost_log

all: $(TARGETS)

asiohiper: asiohiper.cpp
	$(CXX) $(CFLAGS) asiohiper.cpp -o $@ $(LDFLAGS) $(CURL_LIB) -lboost_system -lpthread


clean:
	rm -rf *.o $(TARGETS)

