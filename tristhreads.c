/* Semplice gioco gestito con i threads 
 * File:   tristhreads.c
 * Author: matteo
 *
 * Created on 9 giugno 2018, 19.37
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#define DIM 3

int matrix[DIM][DIM];
int rg, rc, cg, cc; // righe e colonne di giocatore e computer
int turni = 9;


void matrice(){
    int i, j;
    for(i = 0; i < DIM; i++){
        printf("\n");
        for(j = 0; j < DIM; j++){
            printf(" %d ", matrix[i][j]);
        }
    }
}

void *giocatore(void *arg){    
    system("clear");
    rg = rand()%DIM;
    cg = rand()%DIM;
    /*
     printf("Riga giocatore: %d\n", rg);
     printf("Colonna giocatore: %d\n", cg);
     printf("Turno giocatore: %d\n", turni);
     */
    matrix[rg][cg] = 1;
    pthread_exit(0);
}

void *computer(void *arg){    
    system("clear");
    rc = rand()%DIM;
    cc = rand()%DIM;
    /*
     printf("Riga computer: %d\n", rc);
     printf("Colonna computer: %d\n", cc);
     printf("Turno computer: %d\n", turni);
     */
    matrix[rc][cc] = 2;
    pthread_exit(0);
}



int main(int argc, char** argv) {
    srand(time(NULL)); // Ci serve a non generare gli stessi numeri casuali ogni volta
    pthread_t player, cpu;
    int i;
    while(turni > 0){
        pthread_create(&cpu, NULL, computer, NULL);
        pthread_create(&player, NULL, giocatore, NULL);
        pthread_join(cpu, NULL);
        pthread_join(player, NULL);
        for(i = 0; i < DIM; i++){
            if((matrix[i][i] == matrix[i+1][i+1]) && (matrix[i+1][i+1] == matrix[i+2][i+2])){
                if(matrix[i][i] == 1){printf("Ha vinto il giocatore!\n");break;}
                if(matrix[i][i] == 2){printf("Ha vinto il computer!\n");break;}
                //return 0;
            }
            if((matrix[i][0] == matrix[i][1]) && (matrix[i][1] == matrix[i][2])){
                if(matrix[i][0] == 1){printf("Ha vinto il giocatore!\n");break;}
                if(matrix[i][0] == 2){printf("Ha vinto il computer!\n");break;}
                //return 0;
            }
            if((matrix[0][i] == matrix[1][i]) && (matrix[1][i] == matrix[2][i])){
                if(matrix[0][i] == 1){printf("Ha vinto il giocatore!\n");break;}
                if(matrix[0][i] == 2){printf("Ha vinto il computer!\n");break;}
                //return 0;
            }
            else{printf("Non ha vinto nessuno!\n");break;}
        }
        turni--;
    }
    matrice();
    return 0;
}

