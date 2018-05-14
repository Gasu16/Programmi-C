/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main3.c
 * Author: matteo
 *
 * Created on 14 maggio 2018, 14.29
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * CALCOLATRICE
 */

float somma(float a, float b){
    return a+b;
}

float sottrazione(float a, float b){
    return a-b;
}

float moltiplicazione(float a, float b){
    return a*b;
}

float divisione(float a, float b){
    return a/b;
}

void pulisci_buffer(void){
    fflush(stdout);
}

int main(int argc, char** argv) {
    float a, b;
    printf("\nInserisci a: ");
    scanf("%f", &a);
    printf("\nInserisci b: ");
    scanf("%f", &b);
    printf("\nSomma = +\nSottrazione = -\nMoltiplicazione = *\nDivisione = /");
    
    pulisci_buffer();
    char operazione;
    
    do{
        printf("\nChe operazione vuoi fare?: "); // Perche' viene stampato 2 volte?   
        operazione = getchar();
    }while((operazione != '+') && (operazione != '-') && (operazione != '*') && (operazione != '/'));
    
    switch(operazione){
        case '+': printf("La somma e': %.1f", somma(a, b)); break;
        case '-': printf("La sottrazione e': %.1f", sottrazione(a, b)); break;
        case '*': printf("La moltiplicazione e': %.1f", moltiplicazione(a, b)); break;
        case '/': printf("La divisione e': %.1f", divisione(a, b)); break;
    }
    return 0;
}

