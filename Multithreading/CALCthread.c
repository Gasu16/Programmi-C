/* Calcolatrice con i thread
 * File:   CALCthread.c
 * Author: matteo
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct{
    float a; // Primo parametro
    float b; // Secondo parametro
    float risultato;
} var;

void *somma(void *arg){
    // Ora catturiamo il parametro arg (v) e lo mettiamo in v2;
    var *v2;
    v2 = (var*) arg;
    v2->risultato = v2->a + v2->b;
    printf("Somma: %.1f\n", v2->risultato);
    pthread_exit(0);
}


void *sottrazione(void *arg){
    var *v2;
    v2 = (var*) arg;
    v2->risultato = v2->a - v2->b;
    printf("Sottrazione: %.1f\n", v2->risultato);
    pthread_exit(0);
}

void *moltiplicazione(void *arg){
    var *v2;
    v2 = (var*) arg;
    v2->risultato = v2->a * v2->b;
    printf("Moltiplicazione: %.1f\n", v2->risultato);
    pthread_exit(0);
}

void *divisione(void *arg){
    var *v2;
    v2 = (var*) arg;
    v2->risultato = v2->a / v2->b;
    printf("Divisione: %.1f\n", v2->risultato);
    pthread_exit(0);
}

int main(int argc, char** argv) {
    pthread_t som, sott, molt, div;
    var *v;
    v = malloc(sizeof(var));
    v->a = 3;
    v->b = 2;
    pthread_create(&som, NULL, somma, v);
    pthread_create(&sott, NULL, sottrazione, v);
    pthread_create(&molt, NULL, moltiplicazione, v);
    pthread_create(&div, NULL, divisione, v);
    pthread_join(som, NULL);
    pthread_join(sott, NULL);
    pthread_join(molt, NULL);
    pthread_join(div, NULL);
    return 0;
}

