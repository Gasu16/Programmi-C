// Passiamo un parametro condiviso a 2 thread

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct{
    int a;
} tipo;

void *threadUNO(void *arg){
    tipo *T1;
    T1 = (tipo*) arg;
    printf("ThreadUNO: %d\n", T1->a);
    pthread_exit(0);
}

void *threadDUE(void *arg){
    tipo *T2;
    T2 = (tipo*) arg;
    printf("ThreadDUE: %d\n", T2->a);
    pthread_exit(0);
}

int main(int argc, char** argv) {
    tipo *T;
    T->a = 5;
    pthread_t threadID, threadID2; // Definiamo l'ID dei thread
    pthread_create(&threadID, NULL, threadUNO, T);
    pthread_create(&threadID2, NULL, threadDUE, T);
    pthread_join(threadID, NULL);
    pthread_join(threadID2, NULL);
    return (EXIT_SUCCESS);
}

