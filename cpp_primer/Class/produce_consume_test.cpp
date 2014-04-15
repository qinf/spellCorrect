/*
 * produce_consume_test.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: qinf
 */

#include "ConsumeThread.h"
#include "ProduceThread.h"
#include "WorkingQueue.h"

int main(int argc, char **argv) {
	WorkingQueue Q;
	ConsumeThread consumer(&Q);
	ProduceThread producer(&Q);
	producer.start();
	consumer.start();

	producer.run();
	consumer.run();

	producer.jion();
	consumer.jion();
}

