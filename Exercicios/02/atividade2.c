#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
    Arvore binaraia
    Gabriel de Pádua
    versão: 0.0.1
    creditos: inpirado em Nivio Ziviani
*/


/*posso alterra a chave que todas as demais funçoes continuarao
funcionando. Cuidado Especifico apenas com Char*/
typedef char chave;

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
        printf("%c",(*no)->chave);

    }
}

// void ReconstrutorPreOrdem(char vetor[],int tamanhoString){
//     //primeiro termo é a raiz

//     int contaTermo = 0;
//     char vetorInceres[tamanhoString];

//     vetorInceres[0] = vetor[contaTermo];
//     contaTermo ++; 

//     if ()
//     {
//         /* code */
//     }
    

// }

// void ReconstruirPreOrdem(char vetor[], int tam,Apontador_no *no) {
//   // Pilha para armazenar os índices dos elementos da árvore
//   Apontador_no pilha[tam];
//   int topo = -1;

//   // Índice do caractere atual na string
//   int i = 0;

//   // Percorre a string
//   while (i < tam) {
//     // Se o caractere for um dígito
//     if (isdigit(vetor[i])) {
//       // Insere o caractere na árvore
//       Insere(&no, vetor[i] - '0');

//       // Empilha o índice do caractere
//       pilha[++topo] = i;

//       // Avança para o próximo caractere
//       i++;
//     } else {
//       // Se o caractere for um operador
//       if (topo > 0) {
//         // Desempilha o índice do filho direito
//         int dir = pilha[topo--];

//         // Desempilha o índice do filho esquerdo
//         int esq = pilha[topo--];

//         // Reconstrói a subárvore com a raiz atual
//         ReconstruirPreOrdem(vetor, dir - 1);
//         ReconstruirPreOrdem(vetor, esq - 1);

//         // Atualiza o índice do caractere atual
//         i = dir;
//       } else {
//         // Erro: a string não representa uma árvore binária válida
//         printf("Erro: a string não representa uma árvore binária válida\n");
//         return;
//       }
//     }
//   }

//   // Se a pilha não estiver vazia, a string não representa uma árvore binária válida
//   if (topo != -1) {
//     printf("Erro: a string não representa uma árvore binária válida\n");
//     return;
//   }
// }


int main(int argc, char const *argv[])
{
    char string1[50]; 
    char string2[50];

    scanf("%s %s",&string1,&string2);

    //printf("String 1:%s String 2%s",string1,string2); 

    //tamanho das strings 
    int tamStg1 = strlen(&string1); 
    int tamStg2 = strlen(&string2);

    char vetor1[tamStg1];
    char vetor2[tamStg2];

    //printf("%d ----%d",tamStg1,tamStg2);

    for (int i = 0; i < tamStg1; i++)
    {
        vetor1[i] = string1[i];
        vetor2[i] = string2[i];
    }

    // for (int i = 0; i < tamStg2; i++)
    // {
    //     printf("%c --- %c\n",vetor1[i],vetor2[i]);
    // }

    //criando e inserindo na arvore

    Apontador_no *arvore;
    //char vetorResultante[tamStg1];

    Inicializa(&arvore);
    
    for (int i = 0; i <tamStg1; i++)
    {
        Insere(&arvore,vetor1[i]);
    }
    

    PosOrdem(&arvore);

        
    
    

    //algoritmo pra saber qual é a incerção.
    //primeiro elemento da pré-ordem e sempre a raiz
    //os dois seguintes sao sempre os proximos a serem adicionados



    return 0;
}
