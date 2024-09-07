#include <stdio.h>
#include <stdlib.h>

//--------------------Struct de livro----------------

typedef struct livro
{
    int etiqueta;
    int posicao;
    char nome [50];

}livro;

void ordenador(livro *array, int size);

int buscador(livro vetor[], int valor, int tamanhoVetor);


void main(){

// --------------------entrada---------------------


    int num;
    scanf("%d",&num); //numero de livros a ser registrado



    livro vetorDeLivros[num];



    //scanf("%d %c[^\n]", &numero, string);

    for (int i = 0; i < num; i++){

        scanf("%d %[^\n]",&vetorDeLivros[i].etiqueta,&vetorDeLivros[i].nome); //%[^\n] significa q o 2º termo pode receber qualquer string ate que se pule uma linha (enter) 
        vetorDeLivros[i].posicao = i;
        //printf("\n%d %s",vetorDeLivros[i].etiqueta,vetorDeLivros[i].nome);

    }


    int buscador; //numero de busca 
    scanf ("%d",&buscador);

    ordenador(vetorDeLivros,num);

    // for (int i = 0; i < num; i++){
    //     //scanf("%d %s",&vetorDeLivros[i].etiqueta,&vetorDeLivros[i].nome);
    //     //vetorDeLivros[num].posicao = i;
    //     printf("\n%d %s   POSI:%d",vetorDeLivros[i].etiqueta,vetorDeLivros[i].nome,vetorDeLivros[i].posicao);

    // }

    printf("\n");

    buscar(vetorDeLivros,buscador,num);

}


//---------------------Funções-------------------------------



//selectionSort
void ordenador(livro *array, int size) {
  int i, j, minIndex;

  // Percorrer cada elemento do array
  for (i = 0; i < size - 1; i++) {
    // Encontrar o índice do menor elemento no subarray restante
    minIndex = i;
    for (j = i + 1; j < size; j++) {
        if (array[j].etiqueta < array[minIndex].etiqueta){
      //if (array[j] < array[minIndex]) {
        minIndex = j;
      }
    }

    // Trocar o menor elemento encontrado com o elemento na posição atual
    if (minIndex != i) {
      int temp = array[i].etiqueta;
      array[i] = array[minIndex];
      array[minIndex].etiqueta = temp;
    }
  }
}

//usando busca binaria 
void buscar(livro vetor[], int valor, int tamanhoVetor) {
  int esquerda = 0;
  int direita = tamanhoVetor - 1;

  while (esquerda <= direita) {

    int meio = (esquerda + direita) / 2;

    if (vetor[meio].etiqueta == valor) {
    
      printf("Posição: %d, Livro: %s ",vetor[meio].posicao + 1,vetor[meio].nome);
      break;
      //return meio;
    } else if (vetor[meio].etiqueta < valor) {
      esquerda = meio + 1;
    } else {
      direita = meio - 1;
    }

  }


    return;

}