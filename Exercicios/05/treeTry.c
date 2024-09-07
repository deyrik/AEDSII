// Programa C para demonstrar Árvore de Busca Ternária (TST)
// Inserção, travessia e busca

// Bibliotecas padrão de entrada e saída, alocação de memória
#include <stdio.h> 
#include <stdlib.h> 

// Define o tamanho máximo da palavra
#define MAX 50 

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

  
// Programa principal para testar as funções acima
int main() {
struct No* root = NULL; // Cria uma Árvore de Busca Ternária vazia

insert(&root, "gato"); // Insere a palavra "gato" na TST
insert(&root, "gatos"); // Insere a palavra "gatos" na TST
insert(&root, "cima");  // Insere a palavra "cima" na TST (substituído "up" por "cima" para exemplo)
insert(&root, "inseto"); // Insere a palavra "inseto" na TST (substituído "bug" por "inseto" para exemplo)

printf("Imprimindo a Árvore de Busca Ternária:\n"); // Mensagem informativa
traverseTST(root); // Percorre a TST e imprime as palavras armazenadas

printf("\nBuscando pelas palavras 'gatos', 'inse' e 'gato':\n"); // Mensagem informativa
searchTST(root, "gatos") ? printf("Encontrado\n") : printf("Não encontrado\n"); // Busca "gatos"
searchTST(root, "inse") ? printf("Encontrado\n") : printf("Não encontrado\n");  // Busca "inse" (não encontrada)
searchTST(root, "gato") ? printf("Encontrado\n") : printf("Não encontrado\n");  // Busca "gato"

return 0;
}