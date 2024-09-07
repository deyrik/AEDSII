#ifndef PATRICIA_H
#define PATRICIA_H

#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lista/lista.h"

#define tam 200
#define MAX_ARQUIVOS 50

extern int compInsercaoPatricia;
extern int compBuscaPatricia;

typedef char *String;
typedef struct TipoPatNo *Apontador;
typedef unsigned char TipoIndexAmp;

typedef enum {
    Interno,
    Externo
} TipoNo;

typedef struct TipoPatNo {
    TipoNo TNo;
    union {
        struct {
            TipoIndexAmp Index;
            char caractere;
            Apontador Esq, Dir;
        } NInterno;
        struct {
            String Chave;
            Lista *indice_invertido;
        } NExterno;
    } NO;
} TipoPatNo;

char Caractere(int i, String k);
short EExterno(Apontador p);
short EInterno(Apontador p);
Apontador CriaNoInt(int i, Apontador *Esq, Apontador *Dir, char Caractere);
Apontador CriaNoExt(String k, Apontador *t, int idDoc, int repeticao);
Apontador InsereEntre(String k, Apontador *t, int i, char diff, int idDoc, int repeticao);
Apontador InserePatricia(String k, Apontador *t, int idDoc, int repeticao);
void Pesquisa(String k, Apontador t);
void ImprimirPalavras(Apontador t);
void qtd_iddoc(int numDocumentos, Apontador t, String termo);
void CalcularRelevanciaPatricia(int numDocumentos, Apontador t, String termo);

#endif  // PATRICIA_H
