/*
 * Autor: Gabriel de pádua 
 * Data: 01/08
 * Versão: 1.0.1
 * Descrição: criação e teste 
 * 
 * Histórico:
 *  -- -- --
 */

#include "../lista/lista.h"

int main() {
    pont_lista lista = NULL;

    // Inserir alguns elementos na lista
    insere(&lista, 1, 5);
    insere(&lista, 2, 10);
    insere(&lista, 3, 15);

    // Imprimir a lista
    printf("Conteúdo da lista:\n");
    imprimeLista(lista);

    // Verificar se a lista está vazia
    if (vaziaounao(lista)) {
        printf("A lista está vazia.\n");
    } else {
        printf("A lista não está vazia.\n");
    }

    return 0;
}
