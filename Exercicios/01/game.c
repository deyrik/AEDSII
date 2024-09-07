#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pacotes {

  int posicao;
  char nome[50];

} pacotes;

int buscaBinaria(pacotes *vetorPAcotes, int num, char *buscador);

void selectionSortPacotes(pacotes *vetorPAcotes, int num);


int main(int argc, char const *argv[])
{
 // ---------------Entrada------------------

  int num;
  scanf("%d", &num);

  pacotes vetorPAcotes[num];

  for (int i = 0; i < num; i++) {
    scanf("%s", vetorPAcotes[i].nome);
    vetorPAcotes[i].posicao = i + 1;
  }

  char buscador[50];
  scanf("%s", buscador);

  selectionSortPacotes(vetorPAcotes,num);

  // for (int i = 0; i < num; i++)
// {
//     printf("NOME: %s, POSI:%d",vetorPAcotes[i].nome,vetorPAcotes[i].posicao);
    
// }

  // ---------------Pesquisa------------------

//   int verifica;
//   int contador = 0;

//BUSCA USANDO PERCURSO DO VETOR ATRAVES DE INTENTAÇÂO  

//   while (verifica != 0) {
//     verifica = strcmp(buscador, vetorPAcotes[contador].nome);
//     contador++;

//     // if (contador == num) {
//     //   printf("\nPacote não encontrado\n");
//     //   break;
//     // }

//     if (verifica == 0) {
//     printf("\nPosição : %d\n", vetorPAcotes[contador - 1].posicao);
//     } else {
//     printf("\nPacote não encontrado\n");
//     }
//   }

//BUSCA BINARIA

int posicaoPacote = buscaBinaria(vetorPAcotes,num,buscador);


 // ---------------Saída------------------

if (posicaoPacote == -1) {
  printf("\nPacote não encontrado\n");
} else {
  printf("\nPosição: %d\n", posicaoPacote);
}





//   if (verifica == 0) {
//     printf("\nPosição : %d\n", vetorPAcotes[contador - 1].posicao);
//   } else {
//     printf("\nPacote não encontrado\n");
//   }   
    return 0;
}



// -----------------Funções-----------------------

// int buscaBinaria(pacotes *vetorPAcotes, int num, char *buscador) {
//   // Início e fim da busca
//   int inicio = 0;
//   int fim = num - 1;

//   // Loop de busca
//   while (inicio <= fim) {
//     // Meio do vetor
//     int meio = (inicio + fim) / 2;

//     // Comparação com o nome do meio
//     int comparacao = strcmp(buscador, vetorPAcotes[meio].nome);

//     // Se o nome for encontrado
//     if (comparacao == 0) {
//       // Retorna a posição do pacote
//       return vetorPAcotes[meio].posicao;
//     } else if (comparacao < 0) {
//       // Busca na metade inferior
//       fim = meio - 1;
//     } else {
//       // Busca na metade superior
//       inicio = meio + 1;
//     }
//   }

//   // Retorna -1 se o pacote não for encontrado
//   return -1;
// }

int buscaBinaria(pacotes *vetorPAcotes, int num, char *buscador) {
  // Início e fim da busca
  int inicio = 0;
  int fim = num - 1;

  // Loop de busca
  while (inicio <= fim) {
    // Meio do vetor
    int meio = (inicio + fim) / 2;

    // Comparação com o nome do meio
    int comparacao = strcmp(buscador, vetorPAcotes[meio].nome);

    // Se o nome for encontrado
    if (comparacao == 0) {
      // Retorna a posição do pacote
      return vetorPAcotes[meio].posicao;
    } else if (comparacao > 0) {
      // Busca na metade superior
      inicio = meio + 1;
    } else {
      // Busca na metade inferior
      fim = meio - 1;
    }
  }

  // Retorna -1 se o pacote não for encontrado
  if (inicio > fim) {
    return -1;
  }
  
}

void selectionSortPacotes(pacotes *vetorPAcotes, int num) {
  int i, j, menor;

  for (i = 0; i < num - 1; i++) {
    menor = i;
    for (j = i + 1; j < num; j++) {
      if (strcmp(vetorPAcotes[menor].nome, vetorPAcotes[j].nome) > 0) {
        menor = j;
      }
    }

    // Troca os elementos
    if (menor != i) {
      pacotes aux = vetorPAcotes[i];
      vetorPAcotes[i] = vetorPAcotes[menor];
      vetorPAcotes[menor] = aux;
    }
  }
}
