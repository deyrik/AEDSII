#include <stdio.h>
#include <stdlib.h>


//_________________________________TAD ARVORE_____________________________________________
/*
    Arvore binaraia
    Gabriel de Pádua
    versão: 0.0.1
    creditos: inpirado em Nivio Ziviani
*/


/*posso alterra a chave que todas as demais funçoes continuarao
funcionando. Cuidado Especifico apenas com Char*/
typedef int chave;

typedef struct no  *Apontador_no;
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



//TENHO QUE REVER (ponteiros errados ainda)

// chave Pesquisa(Apontador_no *no,chave x){
//     if (*no ==NULL){
//         printf("registro nao encontrado na arvore\n");
//         return;    
//     }

//     if (x < (*no)->chave){
//         Pesquisa(x,&(*no)->esq);
//         return;
//     }
    
//     if (x > (*no)->chave){
//         Pesquisa(x,&(*no)->dir);
//         return;
//     }
// }

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


//____________________________________ATIVIDADE 01________________________________


int main(int argc, char const *argv[]){

    
    int num;
    scanf("%d", &num);

    int vetor[num];

    for (int i = 0; i < num; i++){
        scanf("%d", &vetor[i]);
    }
    
    /*
    Teste:
    for (int i = 0; i < num; i++){
        printf("%d ", vetor[i]);
    }
    
    */

   TipoNo *arvore;

   Inicializa(&arvore);


   for (int i = 0; i < num; i++){
    Insere(&arvore,vetor[i]);
   }

    printf("Pré-Ordem: ");
    PreOrdem(&arvore);
   
    printf("\n");

    printf("Em Ordem: ");
    Ordem(&arvore);

    printf("\n");

    printf("Pós-Ordem: ");
    PosOrdem(&arvore);

    return 0;
   
}

// int main() {
//   int num, i, n;

//   // Lê a quantidade de entradas
//   printf("Digite a quantidade de números: ");
//   scanf("%d", &n);

//   // Lê cada número e armazena em um array
//   int numeros[n];
//   for (i = 0; i < n; i++) {
//     scanf("%d", &numeros[i]);
//   }

//   // Exibe os números lidos
//   for (i = 0; i < n; i++) {
//     printf("%d ", numeros[i]);
//   }

//   printf("\n");

//   return 0;
// }