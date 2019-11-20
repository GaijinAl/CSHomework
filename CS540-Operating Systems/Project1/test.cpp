/*
 * Testing of creating threads
 */


#include <pthread.h>
#include <iostream>

using std::cout;

void *testFn(void *threadId)
{
	cout << "thread ID: " << threadId;
}

int main()
{
	int x = 0;
	int y = 1;

	pthread_t threads[2] {x, y};
	pthread_create(threads, NULL, testFn, &x);


	

	return 0;
}
