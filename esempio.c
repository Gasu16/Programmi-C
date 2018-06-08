#include <pthread.h>
#include <stdio.h>

void *thread1(void *arg){
	
	printf("A\n");
	printf("B\n");
	printf("C\n");
}

void *thread2 (void *arg){  
  
     printf("X\n");
     printf("Y\n");
     printf("Z\n");
}
int main (int argc, char **argv){
	
	pthread_t t1, t2;
	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	return 0;
	
}


