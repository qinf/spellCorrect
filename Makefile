lock:
	g++ -c ./src/MutexLock.cpp ./src/Condition.cpp ./src/Thread.cpp ./src/WorkThread.cpp ./src/ThreadPool.cpp -lpthread
