#include "leitura/leitura.h"
#define M 23

void MostrarMenu() {
    printf("\nMenu de Opções:\n");
    printf("1 - Pesquisar termos\n");
    printf("2 - Mostrar qtd/iddoc de todas as palavras\n");
    printf("3 - Executar calculo de relevância\n");
    printf("4 - Vericar quantidade de inserções\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    pont_capsula vetor_de_heads[M] = {NULL};
    pont_capsula* hash = vetor_de_heads;
    int pesos[100];
    GeraPesos(pesos);

    // Incializando patricia
    Apontador raiz = NULL;

    lerArquivos(hash, pesos, &raiz);

    int op = 100;
    int processo;
    printf("Escolha entre \n\t1)HASH\n\t2)PATRICIA\n\t3)COMPARAR EFICIÊNCIAS\n");
    scanf("%d", &processo);

    switch (processo) {
        /* HASH */
        case 1:
            while (op != 0) {
                printf("\n\nEntrou na seção da HASH\n");

                MostrarMenu();
                scanf("%d", &op);

                switch (op) {
                    case 1:
                        char termo[100];
                        printf("digite o(s) termo(s) que deseja buscar na tabela hash:\n");
                        scanf(" %[^\n]", termo);
                        // printf("%s", termo);
                        busca(vetor_de_heads, termo, pesos);
                        break;

                    case 2:
                        imprimeAllCapsulas(hash, 23);
                        break;

                    case 3:
                        printf("digite o(s) termo(s) para calcular a relevancia:\n");
                        // scanf("%s", termo);
                        CalcularRelevanciaHash(vetor_de_heads, termo, pesos, 15);
                        break;
                    case 4:
                        printf("Quantidade de vezes que foi inserida uma palavra na hash %d\n", compInsercaoHash);
                    case 0:
                        printf("Voce saiu da hash\n");
                    default:
                        break;
                }
            }
            break;
        case 2:
            /* Patricia */
            while (op != 0) {
                printf("\n\nEntrou na seção da PATRICIA\n");

                MostrarMenu();
                scanf("%d", &op);

                switch (op) {
                    case 1:
                        char t[100];
                        printf("digite o(s) termo(s) de busca:\n");
                        scanf(" %[^\n]", t);
                        qtd_iddoc(15, raiz, t);
                        compBuscaPatricia = 0;
                        break;

                    case 2:
                        ImprimirPalavras(raiz);
                        break;

                    case 3:
                        printf("digite o(s) termo(s) para calcular a relevancia:\n");
                        scanf(" %[^\n]", t);
                        CalcularRelevanciaPatricia(15, raiz, t);
                        break;
                    case 4:
                        printf("Quantidade de vezes que foi inserida uma palavra na hash %d\n", compInsercaoPatricia);
                        break;
                    case 0:
                        printf("Voce saiu da Patricia\n");
                    default:
                        break;
                }
            }
        // case 3:
        //     printf("O mais eficiente para adicionar as palavras:\n");
        //     if (compInsercaoHash > compInsercaoPatricia){
        //         printf("A Hash adiciona com mais eficiencia.\nPOIS COMPARA MENOS VEZES\nComparações: HASH = %d | PATRICIA = %d\n", compInsercaoHash, compInsercaoPatricia);
		// 	}
        //     else{
        //         printf("A Patricia adiciona com mais eficiencia.\nPOIS COMPARA MENOS VEZES\nComparações: HASH = %d | PATRICIA = %d\n", compInsercaoHash, compInsercaoPatricia);
		// 	}

        //     break;
        default:
            break;
    }

    printf("Conclui-se que a estrutura mais eficiente tanto para adicionar quanto para pesquisar é a Hash:\n");
    if (compInsercaoHash < compInsercaoPatricia)
        printf("A Hash adiciona com mais eficiencia.\nPOIS COMPARA MENOS VEZES\nComparações: HASH = %d | PATRICIA = %d\n", compInsercaoHash, compInsercaoPatricia);
    else
        printf("A Patricia adiciona com mais eficiencia.\nPOIS COMPARA MENOS VEZES\nComparações: HASH = %d | PATRICIA = %d\n", compInsercaoHash, compInsercaoPatricia);

	printf("-----------------------HASH: %d, patricia %d ---------------------",compInsercaoHash, compInsercaoPatricia);
    return 0;
}
