/*  Gabriel Santos Ferreira de Pádua
    matricula : 4705
    versao: 1.0
*/

#include "tabela_hash.h"

int main(int argc, char const *argv[])
{
    
    FILE *arquivo = NULL;
    arquivo = fopen("tripulacao.txt","r");
    if (arquivo != NULL)
    {
        printf("aquivo aberto com sucesso\n\n");
    }
    else{
         printf ("erro ao abrir arquivo\n\n");
    }
       
    //vetores de buffer pra guardar leitura momentania do arquivo;
    char nome_lido[20];
    char codigo_lido[20];
    int codigo_do_hash;
    char aux = 'H';//valor qualquer pra inicir variavel;
    unsigned pesos[11];
    GeraPesos(pesos);

    /*Criar vetor de structs para ser minha tabela hash
    e inicia todos os campos como string "VAZIO"*/
    tripulante tripulantes[7];
    for (int t = 0; t < 7; t++)
    {
        strcpy(tripulantes[t].nome,"VAZIO");
        strcpy(tripulantes[t].codigo,"VAZIO");
        
        //printf("tripulante %d: nome:%s codigo: %s\n",t,tripulantes[t].nome,tripulantes[t].codigo);
    }


    //o laço com for percorre as linhas do arquivo
    //o laço com while le a linha atual e separa a string em 2 partes
    for (int k = 0; k < 7; k++)
    {
        int i = 0;
        int j = 0;

        /*le o arquivo ate um espaço, prox linha ou final dele e no final da leitura
        coloca um </0> final de string*/
        while ((aux = fgetc(arquivo)) != ' ' && aux != '\n' && aux != EOF)
        {
            nome_lido[i] = aux;
            i++;
        }
        nome_lido[i] = '\0'; 



        /*vai le até o fim da linha ou o fim do arquivo, coloca um <\0> quando termina e salva 
        tbm dentro de um buffer*/
        while ((aux = fgetc(arquivo)) != '\n' && aux != EOF)
        {
            codigo_lido[j] = aux;
            j++;
        }
        codigo_lido[j] = '\0'; 



        /*indexar o que foi lido dentro da tabela hash usando hash code adquirido pelo nome */
        codigo_do_hash = hash_code(nome_lido,pesos);


        /*quantas veses rash foi mudado*/    
        int seeking = 1;

        //enquanto eu nao achar uma posição vazia pra add, hash code atualiza
        while ((strcmp(tripulantes[codigo_do_hash].nome,"VAZIO")) != 0)
        {
            codigo_do_hash = ((codigo_do_hash + 1) % 7);
            seeking ++;
        }
        
        //achou vazio, salva la dentro
        if (strcmp(tripulantes[codigo_do_hash].nome,"VAZIO") == 0)
        {
            strcpy(tripulantes[codigo_do_hash].nome, nome_lido);
            strcpy(tripulantes[codigo_do_hash].codigo, codigo_lido);
        }
        
        printf("para iniserir o nome que se encontra na linha %d(%s) , foram precisos %d seekings\n", k+1, nome_lido, seeking);
    }
    printf("\n");
    //motrando no terminal a tabela hash toda

    exibe_hash_table(tripulantes);

    pesquisa_pessoa(tripulantes,pesos);
    
    
    fclose(arquivo);

    return 0;
}