./bin/main:
	g++ -o ./bin/main -g ./src/main_test.cpp ./src/Cache.cpp ./src/UDPServer.cpp ./src/Tools.cpp  ./src/Log.cpp ./src/Task.cpp ./src/dirct.cpp ./src/EditDistance.cpp ./src/ThreadPool.cpp ./src/server_client_func.cpp ./src/Condition.cpp ./src/WorkThread.cpp ./src/Thread.cpp ./src/EncodingConverter.cpp -I./include -lpthread -std=c++11

clean:
	rm ./bin/main
