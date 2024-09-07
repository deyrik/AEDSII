#include <stdio.h>
#include <stdlib.h>
// Define o tamanho máximo da palavra
#define MAX 50 


/*Gabriel De Pádua
  try retida do geeksforgeks porem com modificaçoes
  version: 0.1 
*/



// Estrutura de um nó da Árvore de Busca Ternária
struct No {
  char data; // Armazena o caractere do nó

  // Flag (0 ou 1) indicando se esse caractere é o último caractere de uma palavra
  unsigned isEndOfString : 1;  

  struct No *left, *eq, *right; // Ponteiros para os filhos esquerdo, central e direito
};

// Função auxiliar para criar um novo nó na TST
struct No* newNode(char data) {
  struct No* temp = (struct No*)malloc(sizeof(struct No)); // Aloca memória para o nó
  temp->data = data;
  temp->isEndOfString = 0;
  temp->left = temp->eq = temp->right = NULL; // Inicializa ponteiros dos filhos como NULL
  return temp;
}

// Função para inserir uma nova palavra na Árvore de Busca Ternária
void insert(struct No** root, char* word) {
  // Caso base: Árvore vazia
  if (!(*root))
    *root = newNode(*word);

  // Se o caractere atual da palavra for menor que o caractere do nó raiz,
  // insere a palavra na subárvore esquerda
  if ((*word) < (*root)->data)
    insert(&((*root)->left), word);

  // Se o caractere atual da palavra for maior que o caractere do nó raiz,
  // insere a palavra na subárvore direita
  else if ((*word) > (*root)->data)
    insert(&((*root)->right), word);

  // Se o caractere atual da palavra for igual ao caractere do nó raiz
  else {
    if (*(word + 1)) // Se ainda há caracteres restantes na palavra
      insert(&((*root)->eq), word + 1); // Insere os caracteres restantes na subárvore central

    // Se for o último caractere da palavra, marca o flag 'isEndOfString'
    else
      (*root)->isEndOfString = 1;
  }
}

// Função recursiva para percorrer a Árvore de Busca Ternária
void traverseTSTUtil(struct No* root, char* buffer, int depth) {
  if (root) {
    // Primeiro percorre a subárvore esquerda
    traverseTSTUtil(root->left, buffer, depth);

    // Armazena o caractere do nó atual no buffer
    buffer[depth] = root->data;
    if (root->isEndOfString) {
      buffer[depth + 1] = '\0'; // Marca o final da palavra no buffer
      printf("%s\n", buffer); // Imprime a palavra completa
    }

    // Percorre a subárvore central (filho do meio)
    traverseTSTUtil(root->eq, buffer, depth + 1);

    // Por fim, percorre a subárvore direita
    traverseTSTUtil(root->right, buffer, depth);
  }
}

// Função principal para percorrer a Árvore de Busca Ternária
void traverseTST(struct No* root) {
  char buffer[MAX];
  traverseTSTUtil(root, buffer, 0);
}

// Função para buscar uma palavra específica na TST
int searchTST(struct No* root, char* word) {
  if (!root)
    return 0; // Não encontrado

  if (*word < (root)->data)
    return searchTST(root->left, word); // Busca na subárvore esquerda

  else if (*word > (root)->data)
    return searchTST(root->right, word); // Busca na subárvore direita

  else {
    if (*(word + 1) == '\0') // Se for o último caractere da palavra
      return root->isEndOfString; // Retorna o flag 'isEndOfString'

    return searchTST(root->eq, word + 1); // Continua buscando na subárvore central
  }
}


/*A secretária de uma empresa está organizando a agenda de reuniões de um dos gerentes, 
e ele gostaria de verificar se uma determinada pessoa irá participar da reunião ou não. 
Para isso, a secretária pede sua ajuda, em que você deverá desenvolver uma implementação 
que verifique o número de pessoas em uma reunião, seus nomes, e retornar se uma determinada 
pessoa estará ou não na reunião.


Entrada

Cada caso de teste contém o número de nomes na reunião mais duas linhas. 
A primeira linha contém um número N que representa o número de pessoas a participarem da reunião. 
As próximas N linhas possuem um nome cada. Ao final, será digitado um nome, 
representando a pessoa buscada na reunião.


Saída

Os casos de teste se encerram quando for digitado 0 no valor N. 
Deve ser impresso “Pessoa Encontrada”, quando a pessoa buscada estiver na lista, 
e “Pessoa Não Encontrada”, caso contrário.*/

//__________________________________MAIN_____________________________



int main(int argc, char const *argv[])
{
 
int num = -1;

// //criando uma arvore
// struct No* arvorePessoas = NULL;
//estava dando errado pois a arvore estava guardando, ja que todos os dados estava sempre numa mesma arvore, em ves de toda hora 
//está se refazendo.



    while (num != 0)
    {
      //criando uma arvore a cada while rodado uma nova arvore surge 
      struct No* arvorePessoas = NULL;

      int num;//numero de pessoas a partcipar 
      scanf("%d",&num);

      if (num == 0)
      {
          break;
      }
        
        
      //inserindo pessoa por pessoa
      for (int i = 0; i < num; i++)
      {
            char nome[20];
            scanf("%s",nome); 
            insert(&arvorePessoas,nome);
      }
      
    char verificaPessoa[20];
    scanf("%s",verificaPessoa);

    int guardaFlag;

    guardaFlag = searchTST(arvorePessoas,verificaPessoa);

    if (guardaFlag == 0)
    {
      printf("Pessoa Não Encontrada\n");//se a funçao  de procura nao encontrar 
    
    }

    else if (guardaFlag != 0)
    {
      printf("Pessoa Encontrada\n");//se a funçao de procura tiver encontrado printa nome da pessoa
    }
    
    }  
  return 0;
}
 