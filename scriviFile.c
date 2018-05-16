/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   scriviFile.c
 * Author: matteo
 *
 * Created on 15 maggio 2018, 15.45
 */

#include <stdio.h>
#include <stdlib.h>
#define DIM 256

int main(int argc, char** argv) {
    FILE *fp;
    char testo [DIM];

    fp = fopen("/home/matteo/NetBeansProjects/GestioneFile/filen.txt", "w+");

    /* Cambia il path di fopen a seconda del file che vuoi leggere */
    if(fp == NULL){
        printf("File non trovato");
        return 1;
    }
    
    fprintf(fp, "Sicilia\n"); // Scriviamo la stringa sul file indicato da fp
    fseek(fp, 0, SEEK_SET); // Resettiamo il puntatore a 0 per leggere il file dall'inizio
    while(fscanf(fp, "%s", &testo) != EOF){
        /* Quello che andiamo a leggere da file lo metto in "testo" 
         fin quando arrivo a EOF (end of file) */
        printf(" %s", testo);
    }
    fclose(fp);
    return 0;
}

