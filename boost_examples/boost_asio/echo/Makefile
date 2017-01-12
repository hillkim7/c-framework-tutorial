
TARGETS= async_tcp_echo_server blocking_tcp_echo_client

all: $(TARGETS)

async_tcp_echo_server: async_tcp_echo_server.cpp
	g++ async_tcp_echo_server.cpp -o async_tcp_echo_server -lboost_system -lpthread

blocking_tcp_echo_client: blocking_tcp_echo_client.cpp
	g++ blocking_tcp_echo_client.cpp -o blocking_tcp_echo_client -lboost_system -lboost_thread -lpthread

clean:
	rm -rf $(TARGETS)

