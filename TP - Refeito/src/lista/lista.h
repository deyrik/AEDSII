/*
 * Autor: Gabriel de Pádua
 * Data: 01/08
 * Versão: 2.0.0
 * Descrição: criação e teste
 *
 * Histórico:
 *  -- -- --
 */

#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista {
    int idDoc;              // identificação do documento
    int qtde;               // quantidade de vezes que a palavra aparece
    struct Lista* proxDoc;  // ponteiro para o próximo nó da lista
} Lista;

typedef Lista* pont_lista;

pont_lista criaNo(int id_doc, int qtd_aparecicao);
int vaziaounao(pont_lista Lista);
void imprimeLista(pont_lista Lista);
void insere(pont_lista* Lista, int idDoc, int qtde);

#endif  // LISTA_H
