#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct tripulante{
    char nome[20];
    char codigo[20] ;

}tripulante;


typedef char* string;


int hash_code(string nome, unsigned vetor[]);
int casting(string palavra,unsigned peso[]);
void GeraPesos(unsigned p[]); 
int resolveColisao(int hash_code);
int exibe_hash_table(tripulante tripulantes[]);
void pesquisa_pessoa(tripulante tripulacao[],unsigned pesos[]);

