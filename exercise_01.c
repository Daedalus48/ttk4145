#include <pthread.h>
#include <stdio.h>

int i = 0;

// Note the return type: void*
void* incrementingThreadFunction() {
	// TODO: increment i 1_000_000 times
	for (int c = 0; c < 1000000; c = c++) {
		i = i++;
	}
	return NULL;
}

void* decrementingThreadFunction() {
	// TODO: decrement i 1_000_000 times
	for (int c = 0; c < 1000000; c = c++) {
		i = i--;
	}
	return NULL;
}


int main() {
	// TODO: declare incrementingThread and decrementingThread (hint: google pthread_create)
	pthread_t thread_1;
	pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
	pthread_t thread_2;
	pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);

	pthread_join(incrementingThread, NULL);
	pthread_join(decrementingThread, NULL);

	printf("The magic number is: %d\n", i);
	return 0;
}