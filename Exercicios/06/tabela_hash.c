#include "tabela_hash.h"

int hash_code(string nome,unsigned vetor[]){
    
    //code = k % 7
    int code = casting(nome,vetor) % 7;

    return code;

}

int casting(string palavra,unsigned peso[]){

    int valor = 0;
    int i = 0;

    while (palavra[i]!= '\0')
    {
        valor = valor + ((int)palavra[i]) * peso[i];
        i++;
    }

    return valor;
}

/*peso sera passado na main, para garantir pesos distindo a cada chamada*/ 
void GeraPesos(unsigned p[]){
  /* -Gera valores randomicos entre 1 e 10.000- */
  int i; 
  struct timeval semente;

  /* Utilizar o tempo como semente para a funcao srand() */
  gettimeofday(&semente,NULL); 
  srand((int)(semente.tv_sec + 1000000 * semente.tv_usec));

  for (i = 0; i < 11; i++)
     p[i] = 1 + (int) (10000.0 * rand()/(RAND_MAX + 1.0));
}

int resolveColisao(int hash_code){

    int new_hash_code;
    new_hash_code = (hash_code + 1) % 7;
    return new_hash_code;    
} 

int exibe_hash_table(tripulante tripulantes[]){

    for (int l = 0; l < 7; l++)    
    {
        printf("tripulantes: %s, codigo de voo: %s\n",tripulantes[l].nome,tripulantes[l].codigo);
    }
    printf("\n");
}

void pesquisa_pessoa(tripulante tripulacao[], unsigned pesos[]) {
    printf("Digite o nome que procura: ");
    char pessoa[20];
    scanf("%s", pessoa);

    int codigo_hash = hash_code(pessoa, pesos);
    int seekings = 0; // Contador de seekings

    for (int i = 0; i < 7; i++) {
        seekings++; // Incrementa o contador a cada iteração
        int index = (codigo_hash + i) % 7; // Para lidar com colisões
        if (strcmp(tripulacao[index].nome, pessoa) == 0) {
            printf("Pessoa encontrada:\n\tnome: %s\n\tcodigo: %s\n", tripulacao[index].nome, tripulacao[index].codigo);
            printf("Número de seekings: %d\n", seekings);
            return;
        }
    }

    printf("Pessoa não encontrada\n");
    printf("Número de seekings: %d\n", seekings);
}