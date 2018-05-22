#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char ** argv){
    char *stringa;
    stringa = (char *) malloc(15); // Allochiamo 15 byte a stringa
    strcpy(stringa, "ciao");
    printf("valore: %s, indirizzo: %p", stringa, stringa);
    free(stringa);
    return 0;
}