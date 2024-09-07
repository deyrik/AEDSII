#include <stdio.h>
#include <stdlib.h>

/*
    Arvore binaraia
    Gabriel de Pádua
    versão: 0.0.1
    creditos: inpirado em Nivio Ziviani
*/


/*posso alterra a chave que todas as demais funçoes continuarao
funcionando. Cuidado Especifico apenas com Char*/
typedef int chave;

typedef struct no* Apontador_no;
//agora posso fazer ponteiro pra ponteiro sem soar muito estranho : **no fica apontador *no
//apontador daquele tipo tem nome proprio
//redefina TYPEDEF
//este tipo <TIPO>
//para este tipo <TIPO>

typedef struct no{
    long chave;
    Apontador_no esq;
    Apontador_no dir;

}TipoNo;


void Inicializa(Apontador_no *no){
    *no = NULL;
    return;
}

chave Pesquisa(Apontador_no *no,chave x){
    if (*no == NULL){
        printf("registro nao encontrado na arvore\n");
        return;    
    }

    if (x < (*no)->chave){
        Pesquisa(&(*no)->esq,x);
        return;
    }
    
    if (x > (*no)->chave){
        Pesquisa(&(*no)->dir,x);
        return;
    }
    if (x == (*no)->chave)
    {
        return x;
        // printf("chave encontrada: %d",x);
    }
    
}

void Insere(Apontador_no *no,chave x){
    if (*no == NULL){ //se o nó for vazio 

        *no = (Apontador_no)malloc(sizeof(TipoNo));
        (*no)->chave = x;
        (*no)->esq = NULL;
        (*no)->dir = NULL;
        return;
    }
    
    //se o nó nao e vazio, comparo pra ver onde vou inserir
    if (x < (*no)->chave){
        Insere(&(*no)->esq,x);
        return;
    }

    if (x > (*no)->chave){
        Insere(&(*no)->dir,x);
        return;
    }
}


// void Percorre(Apontador_no *no){

//     int valor
//     escolha 1 ou 2
//     1 - largura 
//     2 - altura
// }
void Antecessor(Apontador_no ProprioNo ,Apontador_no *no){
    if ((*no)->dir != NULL)
    {
        Antecessor(ProprioNo,&(*no)->dir);
        return;
    }
    
    ProprioNo->chave = (*no)->chave;
    ProprioNo = *no;
    *no = (*no)->esq;
    free(ProprioNo);
}

void Retira(Apontador_no* no,chave x){

    Apontador_no noAux;

//verifica se arvore existe ou nó e nulo
    if (*no == NULL){
        //printf("Erro: arvore nao possui esse registro");//apagar esse linha nesse exercicio 
    }

/* ::vai "viajando pela arvore,tipo de percorrer a arvore"*/

//a chave esta a esquerda (<) que a deste nó atual
    if (x < (*no)->chave)
    {
        Retira(&(*no)->esq,x);
    }
//a chave esta a direita (>) que a deste nó atual
    if (x > (*no)->chave)
    {
        Retira(&(*no)->dir,x);
    }
    
    if ((*no)->dir == NULL)
    {
        noAux = *no;
        *no = (*no)->esq;
        free(noAux);
    }
    
    //por convessao usaremos o antecessor

    if ((*no)->esq != NULL)
    {
        Antecessor(*no,&(*no)->esq);
        return;
    }
    
    noAux = *no;
    *no = (*no)->esq;
    free(noAux);
}

void Ordem(Apontador_no *no){
  if (*no != NULL) {
    Ordem(&(*no)->esq);
    printf("%ld ", (*no)->chave);
    Ordem(&(*no)->dir);
  }
}

void PreOrdem(Apontador_no *no){

    if (*no != NULL){
        printf("%ld ",(*no)->chave);
        PreOrdem(&(*no)->esq);
        PreOrdem(&(*no)->dir);
    }
}

void PosOrdem(Apontador_no *no){
    if (*no != NULL)
    {
        PosOrdem(&(*no)->esq);
        PosOrdem(&(*no)->dir);
        printf("%ld ",(*no)->chave);

    }
}



//_________________________________________TESTE___________________________________________________________

int main(int argc, char const *argv[]){
    
    TipoNo *arvore1;

    Inicializa(&arvore1);

    printf("\n1\n");

     Insere(&arvore1,5);
     Insere(&arvore1,2);
     Insere(&arvore1,7);

    printf("\n2\n");

    // printf("2");

    Ordem(&arvore1);

printf("\n---------\n");

    PreOrdem(&arvore1);

printf("\n---------\n");

    PosOrdem(&arvore1);
    
printf("\n---------\n");

    Retira(&arvore1,5);

printf("\n---------\n");

    Ordem(&arvore1);

printf("\n---------\n");

    printf("pesquisando numero:2 ... encontrado o numero: %d",Pesquisa(&arvore1,2));

printf("\n---------\n");

    printf("pesquisando numero:8 ... ");
    Pesquisa(&arvore1,8);




    // printf("3");



    return 0;
}





