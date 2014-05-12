./bin/client:
	g++ -o ./bin/client ./src/Client.cpp ./src/EncodingConverter.cpp ./src/Log.cpp ./src/MutexLock.cpp ./src/server_client_func.cpp -I./include -lpthread

clean:
	rm ./bin/client
