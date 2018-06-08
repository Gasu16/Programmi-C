#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Creiamo due threads, uno che scrive A, e un altro che scrive B

void *printA(void *arg){
    while(1){
        sleep(rand()%2);
        printf("A\n");
    }
    
}

void *printB(void *arg){
    while(1){
        sleep(rand()%2);
        printf("B\n");
    }
}

int main(int argc, char** argv) {
    pthread_t th1, th2; // ID che serviranno per la gestione dei threads
    pthread_create(&th1, NULL, printA, NULL); // Creiamo il primo thread
    pthread_create(&th2, NULL, printB, NULL); // Creiamo il secondo thread
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return 0;
}

