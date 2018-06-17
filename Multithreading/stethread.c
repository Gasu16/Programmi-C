
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
#include <semaphore.h>

typedef struct {
    int valore;
} Semaforo;

void *wait(void *arg){
    Semaforo *S1;
    S1 = (Semaforo*) arg;
    while(S1->valore <= 0){
        //semaforo rosso
    }
    S1->valore--;
    printf("Wait: %d \n", S1->valore);
}

void *signal(void *arg){
    Semaforo *S2;
    S2 = (Semaforo*) arg;
    S2->valore++;
    // Semaforo verde
    printf("Signal: %d \n", S2->valore);
}

int main(int argc, char** argv) {
    Semaforo *S;
    S->valore = 2;
    printf("Valore: %d\n", S->valore);
    pthread_t T1, T2;
    pthread_create(&T1, NULL, wait, S);
    pthread_create(&T2, NULL, signal, S);
    pthread_join(T1, NULL);
    pthread_join(T2, NULL);
    return 0;
}
















