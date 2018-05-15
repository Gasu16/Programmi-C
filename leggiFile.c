/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   leggiFile.c
 * Author: matteo
 *
 * Created on 15 maggio 2018, 15.45
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *fp;
    char testo [100];
    char line [80];
    fp = fopen("/home/matteo/NetBeansProjects/GestioneFile/filen.txt", "r");
    /* Cambia il path di fopen a seconda del file che vuoi leggere */
    if(fp == NULL){
        printf("File non trovato");
    }
    while(fscanf(fp, "%s", &testo) != EOF){
        /* Quello che andiamo a leggere da file lo metto in "testo" 
         fin quando arrivo a EOF (end of file) */
        printf(" %s", testo);
    }
    fclose(fp);
    return (EXIT_SUCCESS);
}

