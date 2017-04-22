# for cross compilation:
# run like following:
# CROSS_COMPILE=arm-linux-gnueabihf- BOOST_DIR=~/src/boost_1_63_0/boost_1_63_0 make

CXX = $(CROSS_COMPILE)g++

TARGETS= shared_ptr_test thread1 daytime3 daytime2 daytime1 timer4 timer3 timer2 ref simple_log logging_filter steady_timer

CFLAGS = -g -Wall

ifneq ($(strip $(BOOST_DIR)),)
INCPATH = -I$(BOOST_DIR)
LDFLAGS = -L$(BOOST_DIR)/stage/lib
CFLAGS += $(INCPATH)
## remove "error: ‘sleep_for’ is not a member of ‘std::this_thread’"
CFLAGS += -D_GLIBCXX_USE_NANOSLEEP
endif

LOG_LIB = -lboost_atomic -lboost_chrono -lboost_date_time -lboost_regex -lboost_filesystem -lboost_thread -lboost_log

all: $(TARGETS)

shared_ptr_test: shared_ptr_test.cpp
	$(CXX) -std=c++11 $(CFLAGS) shared_ptr_test.cpp -o $@

steady_timer: steady_timer.cpp
	$(CXX) -std=c++11 $(CFLAGS) steady_timer.cpp -o $@ -lboost_system

thread1: thread1.cpp
	$(CXX) $(CFLAGS) thread1.cpp -o $@ $(LDFLAGS) -lboost_system -lboost_thread

daytime3: daytime3.cpp
	$(CXX) $(CFLAGS) daytime3.cpp -o $@ $(LDFLAGS) -lboost_system -lpthread

daytime2: daytime2.cpp
	$(CXX) $(CFLAGS) daytime2.cpp -o $@ $(LDFLAGS) -lboost_system -lpthread

daytime1: daytime1.cpp
	$(CXX) $(CFLAGS) daytime1.cpp -o $@ $(LDFLAGS) -lboost_system -lpthread

timer4: timer4.cpp
	$(CXX) $(CFLAGS) timer4.cpp -o $@ $(LDFLAGS) -lboost_system -lpthread

timer3: timer3.cpp
	$(CXX) $(CFLAGS) timer3.cpp -o $@ $(LDFLAGS) -lboost_system -lpthread

timer2: timer2.cpp
	$(CXX) $(CFLAGS) timer2.cpp -o $@ $(LDFLAGS) -lboost_system -lpthread

ref: ref.cpp
	$(CXX) $(CFLAGS) ref.cpp -o $@ $(LDFLAGS) -lboost_system

simple_log: simple_log.cpp
	$(CXX) $(CFLAGS) -std=c++11 -DBOOST_LOG_DYN_LINK=1 simple_log.cpp -o $@ $(LDFLAGS) -lboost_system -lpthread $(LOG_LIB)

logging_filter: logging_filter.cpp
	$(CXX) $(CFLAGS) -DBOOST_LOG_DYN_LINK=1 logging_filter.cpp -o $@ $(LDFLAGS) -lboost_system -lpthread $(LOG_LIB)

clean:
	rm -rf *.o $(TARGETS)

