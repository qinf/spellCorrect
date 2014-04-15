/*
 * C_Producer_Consumer.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: qinf
 */

#include <iostream>
#include <pthread.h>
#include <string>
#include <queue>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

queue<int> Q;
pthread_mutex_t mutex;
pthread_cond_t cond;

void *produce(void *arg) {
	while (1) {
		//produce sth
		pthread_mutex_lock(&mutex);
		srand(time(NULL));
		int tmp = rand() % 100;
		Q.push(tmp);
		sleep(2);
		cout << "push a number: " << tmp << endl;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}

	return NULL;
}

void *consume(void *arg) {
	while (1) {
		pthread_mutex_lock(&mutex);
		while (Q.empty())
			pthread_cond_wait(&cond, &mutex);
		sleep(1);
		int ival = Q.front();
		cout << "get a num: " << ival << endl;
		Q.pop();
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main(int argc, char **argv) {

	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);

	pthread_t pid1, pid2;
	pthread_create(&pid1, NULL, produce, NULL);
	pthread_create(&pid2, NULL, consume, NULL);

	pthread_join(pid1, NULL);
	pthread_join(pid2, NULL);

	return NULL;
}

