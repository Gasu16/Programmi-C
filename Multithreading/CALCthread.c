// Calcolatrice con i thread

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct{
    int a; // Primo parametro
    int b; // Secondo parametro
    int risultato;
} var;

void *somma(void *arg){
    // Ora catturiamo il parametro arg (v) e lo mettiamo in v2;
    var *v2;
    v2 = (var*) arg;
    v2->risultato = v2->a + v2->b;
    // Ora effettuiamo il casting per passare da var a int
    int Int_ris;
    Int_ris = (int*) v2->risultato;
    printf("%d", Int_ris);
}

/*
 void *sottrazione(void *arg){
 
 }
 
 void *moltiplicazione(void *arg){
 
 }
 
 void *divisione(void *arg){
 
 }*/

int main(int argc, char** argv) {
    pthread_t som, sott, molt, div;
    var *v;
    v = malloc(sizeof(var));
    v->a = 2;
    v->b = 2;
    pthread_create(&som, NULL, somma, v);
    //    pthread_create(&sott, NULL, sottrazione, v);
    //    pthread_create(&molt, NULL, moltiplicazione, v);
    //    pthread_create(&div, NULL, divisione, v);
    pthread_join(som, NULL);
    //    pthread_join(sott, NULL);
    //    pthread_join(molt, NULL);
    //    pthread_join(div, NULL);
    return 0;
}

