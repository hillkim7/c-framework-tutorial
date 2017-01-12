TARGETS= shared_ptr_test thread1 daytime3 daytime2 daytime1 timer4 timer3 timer2 ref logging_filter

all: $(TARGETS)

simple_log: simple_log.cpp
	g++ -std=c++11 simple_log.cpp -o $@ -DBOOST_LOG_DYN_LINK=1 -lboost_system -lboost_thread

shared_ptr_test: shared_ptr_test.cpp
	g++ shared_ptr_test.cpp -o $@

thread1: thread1.cpp
	g++ thread1.cpp -o $@ -lboost_system -lboost_thread

daytime3: daytime3.cpp
	g++ daytime3.cpp -o $@ -l boost_system -lpthread

daytime2: daytime2.cpp
	g++ daytime2.cpp -o $@ -l boost_system -lpthread

daytime1: daytime1.cpp
	g++ daytime1.cpp -o $@ -l boost_system -lpthread

timer4: timer4.cpp
	g++ timer4.cpp -o $@ -l boost_system

timer3: timer3.cpp
	g++ timer3.cpp -o $@ -l boost_system

timer2: timer2.cpp
	g++ timer2.cpp -o $@ -l boost_system

ref: ref.cpp
	g++ ref.cpp -o $@ -l boost_system

logging_filter: logging_filter.cpp
	g++ logging_filter.cpp -o $@ -DBOOST_LOG_DYN_LINK=1 -l boost_system -l boost_log -l boost_thread -lpthread

clean:
	rm -rf *.o $(TARGETS)

