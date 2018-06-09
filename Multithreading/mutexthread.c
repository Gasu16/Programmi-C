/* Sincronizzazione thread con i semafori mutex;
 * Thread 1 incrementa il valore di una variabile
 * Thread 2 decrementa il valore di una variabile 
 * File:   mutexthread.c
 * Author: matteo
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *incrementa(void *arg){
    pthread_mutex_lock(&mutex);
    int a = 0;
    while(a < 10){
        sleep(rand()%2);
        printf("Thread 1: %d\n", a);
        a++;
    }
    
    pthread_mutex_unlock(&mutex);
}

void *decrementa(void *arg){
    pthread_mutex_lock(&mutex);
    int b = 10;
    while(b > 0){
        sleep(rand()%2);
        printf("Thread 2: %d\n", b);
        b--;
    }
    
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char** argv) {
    pthread_t th1, th2;
    pthread_create(&th1, NULL, incrementa, NULL);
    pthread_create(&th2, NULL, decrementa, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return 0;
}

