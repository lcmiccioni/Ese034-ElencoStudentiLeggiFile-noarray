#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente{
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    studente alunno;
    char fileName[MAX_STRLEN+1];
    FILE *puntaFile;
    
    // Codice per la richiesta del nome del file
    printf("Inserisci il nome del file da leggere: ");
    scanf("%s", fileName);
    
    // Codice per l'apertura del file, la lettura e la stampa a schermo
    puntaFile = fopen(fileName, "rb");
    
    if(puntaFile) {
        fread(&alunno, sizeof(studente), 1, puntaFile);
        while(!feof(puntaFile)){
            printf("\n%s; %s; %d; %s", alunno.nome, alunno.cognome, alunno.eta, alunno.classe);
            fread(&alunno ,sizeof(studente), 1, puntaFile);
        }
    }else {
        printf("Non e' possibile aprire il file!");
    }
    
    fclose(puntaFile);
    
    return (EXIT_SUCCESS);
}