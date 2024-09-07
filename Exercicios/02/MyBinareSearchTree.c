#include <stdio.h>
#include <stdlib.h>

/*
    Arvore binaraia
    Gabriel de Pádua
    versão: 0.0.2
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

void Pesquisa(Apontador_no no,chave x){
    if (no == NULL){
        printf("registro nao encontrado na arvore\n");
        return;    
    }
    
    if (x == no->chave)
    {
        return printf("chave encontrada : numero: %d",x);
        //return x;
    }

    if (x < no->chave){
        Pesquisa(no->esq,x);
        return;
    }
    
    if (x > no->chave ){
        Pesquisa(no->dir,x);
        return;
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

/*
void Percorre(Apontador_no *no){
    escolha 1 ou 2
    1 - largura 
    2 - altura
*/

int Altura (Apontador_no no){
    if (no == NULL)
        return -1;//arvore nao existe
    else
    {
        int he = Altura(no->esq);
        int hd = Altura(no->dir);
        if (hd > he)
        {
             return hd + 1;
        }
        else return he + 1;   
    }
}

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

void Retira(Apontador_no *no,chave x){

    Apontador_no noAux;

    //verifica se arvore existe ou nó é nulo
    if (*no == NULL) //valor deste ponteiro <no> é nulo?
    {
        printf("ERRO: registro não esta na Arvore.\n");
        return;
    }

    //viajando pelas sub arvores para achar a chave a se retirar 
    if (x < (*no)->chave)
    {
        Retira(&(*no)->esq,x);
        printf("houve um desvio pra esquerda\n");
        return;
    }

    if (x > (*no)->chave)
    {
        Retira(&(*no)->dir,x);
        printf("houve um desvio pra direita\n");
        return;
    }

/*  if (x == (*no)->chave)
    {
    
        printf("achou o numero\n");
        //caso 1(é Folha, Direita e Esquerda são null)
        if ((*no)->dir == NULL && (*no)->esq == NULL)
        {
            printf("caso 1\n");
            printf("numero que achou pra retirar:%d ",(*no)->chave);
            noAux = *no;
            *no = (*no)->dir;
            free(noAux);
            return;
        }
        
        //caso 2(achar o numero,e endereço da casa a Esquerda ou Direita for vazio)
        //Direita Null
        if ((*no)->dir == NULL && (*no)->esq != NULL)
        {
            printf("caso 2.dir\n");
            noAux = *no; //auxiliador recebe o endereço do nó 
            *no = (*no)->esq;
            free(noAux);
            return; 
        }
        //Esquerda Null
        if ((*no)->esq == NULL && (*no)->dir != NULL);
        {
            printf("caso 2.esq\n");
            noAux = *no;
            *no = (*no)->dir;
            free(noAux);
            return;
        }
        //caso 3(nenhum endereço - Direita nem Esquerda sao vazios de no)
        if ((*no)->dir != NULL && (*no)->esq != NULL){
            printf("caso 3\n");
            Antecessor(*no,&(*no)->esq);
            return;

        }

    }
*/ 
    
    /*se o ponteiro da direita for nulo eu posso so pegar o ponteiro da esquerda independete porque se a esquerda 
    tbm for nulo continua iqual e se tiver valores a arvore nao fica fora de ordem*/
    if ((*no)->dir == NULL) { 
        noAux = *no;  
        *no = (*no)->esq;
        free(noAux);
        return;
    }

    if ((*no)->esq != NULL){
        Antecessor(*no,&(*no)->esq);
        return;
     }

    /*como o auxiliar SEMPRE sera usado, no caso de apont direita == null*/
    noAux = (*no);
    *no = (*no)->dir;
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

    printf("\nquantos registros serão?:");

    int num;
    scanf("%d",&num);

    for (int i = 0; i < num; i++)
    {        
        printf("registo numero %d:",(i+1));
        int registro;
        scanf("%d",&registro);

        Insere(&arvore1,registro);
    }

    printf("\nregistros inseridos com sucesso\n");

    printf("Ordem: ");Ordem(&arvore1);
    
    printf("\n---------\n");

    printf("Pre-Ordem: ");PreOrdem(&arvore1);
  
    printf("\n---------\n");

    printf("Pos-Ordem: ");PosOrdem(&arvore1);;
    
    printf("\n---------\n");

    printf("pesquisar qual numero?");
    int pesq; 
    scanf("%d",&pesq);


    Pesquisa(arvore1,pesq);

    printf("\naltura da arvore: %d\n",Altura(arvore1));

    printf("\nescolha um numero pra retirar: ");
    int reti = scanf("%d",&reti);
    
    Retira(&arvore1,reti);

    printf("Ordem: ");Ordem(&arvore1);

    // printf("3");



    return 0;
}





