
simple_log: simple_log.o
	g++ simple_log.o -o simple_log -lboost_system -l boost_log_setup -lboost_log -lboost_date_time -lboost_thread -lpthread

simple_log.o: simple_log.cpp
	g++ simple_log.cpp -c -DBOOST_LOG_DYN_LINK=1

clean:
	rm -rf *.o simple_log

