#ifndef LEITURA_H
#define LEITURA_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../hash/hash.h"
#include "../patricia/patricia.h"

#define TAM 256
#define TAM_LINHA 3000

void LerPalavra(char *p);
void Minuscula(char *p);
void lerArquivos(pont_capsula head[], unsigned pesos[], Apontador *t);
void lerArquivosTest(pont_capsula head[], unsigned pesos[], Apontador *t)

#endif  // LEITURA_H
