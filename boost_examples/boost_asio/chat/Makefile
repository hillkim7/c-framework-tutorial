
TARGETS= chat_server chat_client

all: $(TARGETS)

chat_server: chat_server.cpp
	g++ chat_server.cpp -o chat_server -lboost_system -lpthread

chat_client: chat_client.cpp
	g++ chat_client.cpp -o chat_client -lboost_system -lboost_thread -lpthread

clean:
	rm -rf $(TARGETS)

