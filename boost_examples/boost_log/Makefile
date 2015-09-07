
CPPFLAGS = -DBOOST_LOG_DYN_LINK=1 -g
all: simple_log custom_sink


simple_log: simple_log.o
	g++ simple_log.o -o $@ -lboost_system -l boost_log_setup -lboost_log -lboost_date_time -lboost_thread -lpthread
	
custom_sink: custom_sink.o
	g++ custom_sink.o -o $@ -lboost_system -l boost_log_setup -lboost_log -lboost_date_time -lboost_thread -lpthread


clean:
	rm -rf *.o simple_log custom_sink *.log

