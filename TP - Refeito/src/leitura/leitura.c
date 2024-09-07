#include "leitura.h"

// Remover caracteres especiais, acentuação e pontuação
void LerPalavra(char *p) {
    int len = strlen(p);

    // Remover caracteres especiais, acentuação e pontuação
    p[strcspn(p, ".")] = '\0';
    p[strcspn(p, ";")] = '\0';

    for (int i = 0; i < len; i++) {
        p[i] = tolower((unsigned char)p[i]);
    }
}

void Minuscula(char *p) {
    int len = strlen(p);

    for (int i = 0; i < len; i++) {
        p[i] = tolower((unsigned char)p[i]);
    }
}

void lerArquivos(pont_capsula head[], unsigned pesos[], Apontador *t) {

    FILE *file = fopen("entrada.txt", "r");
    char palavrasRecebidas[TAM];
    char nomesArquivos[TAM];
    char linha1[TAM_LINHA];
    char linha2[TAM_LINHA];
    char linha3[TAM_LINHA];
    int numFile = 0;

    if (file == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return;
    }

    fscanf(file, "%d", &numFile); /* Ler primeira linha */

    for (int i = 0; i < numFile; i++) {
        char arquivoCompleto[TAM] = "ArquivosEntrada/";
        int qtde = 0;
        int idDoc = 0;

        fscanf(file, "%s", nomesArquivos);
        strcat(arquivoCompleto, nomesArquivos);

        FILE *f = fopen(arquivoCompleto, "r");

        if (f == NULL) {
            perror("Erro ao abrir o arquivo");
            continue;  // Ir para o próximo arquivo na lista
        }

        /* Lendo a primeira linha */
        if (fgets(linha1, TAM_LINHA, f) == NULL) {
            perror("Erro ao ler a primeira linha");
            fclose(f);
            continue;
        }

        /* Lendo a segunda linha */
        if (fgets(linha2, TAM_LINHA, f) == NULL) {
            perror("Erro ao ler a segunda linha");
            fclose(f);
            continue;
        }

        /* Lendo a segunda linha */
        if (fgets(linha3, TAM_LINHA, f) == NULL) {
            perror("Erro ao ler a terceira linha");
            fclose(f);
            continue;
        }

        LerPalavra(linha1);
        Minuscula(linha3);

        linha2[strcspn(linha2, "\n")] = '\0';  // Remove o '\n' no final
        char *token = strtok(linha2, ";");

        while (token != NULL) {
            while (*token == ' ') token++;
            char *end = token + strlen(token) - 1;
            while (end > token && *end == ' ') end--;
            *(end + 1) = '\0';

            LerPalavra(token);

            int idDoc = i + 1;

            qtde++;

            if (strstr(linha1, token) != NULL) {
                qtde++;
            }

            if (strstr(linha3, token) != NULL) {
                qtde++;
            }

			//INSERINDO NA HASH:
            int codeHash = Hash_code(token, pesos);
            insereCapsula(&(head[codeHash]), token, idDoc, qtde);

			// INSERINDO NA PATRICIA:
            *t = InserePatricia(token, t, idDoc, qtde);

            // printf("%s: <%d, %d>\n", token, idDoc, qtde);
            token = strtok(NULL, ";");

            qtde = 0;
        }

        fclose(f);
    }
    fclose(file);
}

// void lerArquivosTest(pont_capsula head[], unsigned pesos[], Apontador *t){

//     FILE *file = fopen("entrada.txt", "r");
//     char palavrasRecebidas[TAM];
//     char nomesArquivos[TAM];
//     char linha1[TAM_LINHA];
//     char linha2[TAM_LINHA];
//     char linha3[TAM_LINHA];
//     int numFile = 0;

//     if (file == NULL) {
//         perror("Erro ao abrir o arquivo de entrada");
//         return;
//     }

//     fscanf(file, "%d", &numFile); /* Ler primeira linha */

//     for (int i = 0; i < numFile; i++) {
//         char arquivoCompleto[TAM] = "ArquivosEntrada/";
//         int qtde = 0;
//         int idDoc = 0;

//         fscanf(file, "%s", nomesArquivos);
//         strcat(arquivoCompleto, nomesArquivos);

//         FILE *f = fopen(arquivoCompleto, "r");

//         if (f == NULL) {
//             perror("Erro ao abrir o arquivo");
//             continue;  // Ir para o próximo arquivo na lista
//         }

//         /* Lendo a primeira linha */
//         if (fgets(linha1, TAM_LINHA, f) == NULL) {
//             perror("Erro ao ler a primeira linha");
//             fclose(f);
//             continue;
//         }

//         /* Lendo a segunda linha */
//         if (fgets(linha2, TAM_LINHA, f) == NULL) {
//             perror("Erro ao ler a segunda linha");
//             fclose(f);
//             continue;
//         }

//         /* Lendo a segunda linha */
//         if (fgets(linha3, TAM_LINHA, f) == NULL) {
//             perror("Erro ao ler a terceira linha");
//             fclose(f);
//             continue;
//         }

//         LerPalavra(linha1);
//         Minuscula(linha3);

//         linha2[strcspn(linha2, "\n")] = '\0';  // Remove o '\n' no final
//         char *token = strtok(linha2, ";");

//         while (token != NULL) {
//             while (*token == ' ') token++;
//             char *end = token + strlen(token) - 1;
//             while (end > token && *end == ' ') end--;
//             *(end + 1) = '\0';

//             LerPalavra(token);

//             int idDoc = i + 1;

//             qtde++;

//             if (strstr(linha1, token) != NULL) {
//                 qtde++;
//             }

//             if (strstr(linha3, token) != NULL) {
//                 qtde++;
//             }

// 			//INSERINDO NA HASH:
//             // int codeHash = Hash_code(token, pesos);
//             // insereCapsula(&(head[codeHash]), token, idDoc, qtde);

// 			// INSERINDO NA PATRICIA:
//             // *t = InserePatricia(token, t, idDoc, qtde);

//             printf("%s: <%d, %d>\n", token, idDoc, qtde);
//             token = strtok(NULL, ";");

//             qtde = 0;
//         }

//         fclose(f);
//     }
//     fclose(file);
// }