#./bin/main:
#	g++ -o ./bin/main -g ./src/MutexLock.cpp ./src/Condition.cpp ./src/Thread.cpp ./src/WorkThread.cpp ./src/ThreadPool.cpp -lpthread

./bin/server:
	g++ -o ./bin/server ./src/Server.cpp ./src/server_client_func.cpp
./bin/client:
	g++ -o ./bin/client ./src/Client.cpp ./src/server_client_func.cpp
