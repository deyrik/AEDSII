#include "../leitura/leitura.h"


int main() {
    pont_capsula vetor_de_heads[M] = {NULL};
    pont_capsula* hash = vetor_de_heads;
    int pesos[100];
    GeraPesos(pesos);

    // Incializando patricia
    Apontador raiz = NULL;

    lerArquivos(hash, pesos, &raiz);

    CalcularRelevanciaHash(vetor_de_heads, "bezoar", pesos, 15);

    imprimeAllCapsulas(hash, 23);

    return 0;
}
