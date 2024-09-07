#include "patricia.h"

int compInsercaoPatricia = 0;
int compBuscaPatricia = 0;

char Caractere(int i, String k) {
    return k[i];
}

short EExterno(Apontador p) {
    return p->TNo == Externo;
}

short EInterno(Apontador p) {
    return p->TNo == Interno;
}

Apontador CriaNoInt(int i, Apontador *Esq, Apontador *Dir, char Caractere) {
    Apontador p;
    p = (Apontador)malloc(sizeof(TipoPatNo));
    p->TNo = Interno;
    p->NO.NInterno.Esq = *Esq;
    p->NO.NInterno.Dir = *Dir;
    p->NO.NInterno.Index = i;
    p->NO.NInterno.caractere = Caractere;
    return p;
}

Apontador CriaNoExt(String k, Apontador *t, int idDoc, int repeticao) {
    Apontador p;
    p = (Apontador)malloc(sizeof(TipoPatNo));
    p->TNo = Externo;
    p->NO.NExterno.Chave = (String)malloc((strlen(k) + 1) * sizeof(char));
    strcpy(p->NO.NExterno.Chave, k);

    p->NO.NExterno.indice_invertido = criaNo(idDoc, repeticao);

    return p;
}

Apontador InsereEntre(String k, Apontador *t, int i, char diff, int idDoc, int repeticao) {
    Apontador p;
    if (EExterno(*t)) {
        p = CriaNoExt(k, &p, idDoc, repeticao);
        if (strcmp((*t)->NO.NExterno.Chave, k) < 0) {
            return (CriaNoInt(i, t, &p, diff));
        } else {
            return (CriaNoInt(i, &p, t, diff));
        }
    } else if (i < (*t)->NO.NInterno.Index) {
        p = CriaNoExt(k, &p, idDoc, repeticao);
        if (k[i] < diff) {
            return (CriaNoInt(i, &p, t, diff));
        } else {
            return (CriaNoInt(i, t, &p, diff));
        }
    } else {
        int index = (*t)->NO.NInterno.Index;
        if (Caractere(index, k) >= (*t)->NO.NInterno.caractere) {
            (*t)->NO.NInterno.Dir = InsereEntre(k, &(*t)->NO.NInterno.Dir, i, diff, idDoc, repeticao);
        } else {
            (*t)->NO.NInterno.Esq = InsereEntre(k, &(*t)->NO.NInterno.Esq, i, diff, idDoc, repeticao);
        }
    }
    return (*t);
}

Apontador InserePatricia(String k, Apontador *t, int idDoc, int repeticao) {
    Apontador p;
    int i;
    char caractere;
    char charDiff;

    if (strlen(k) < 3) {
        return (*t);
    }

    if (*t == NULL) {
        return (CriaNoExt(k, &p, idDoc, repeticao));
    } else {
        p = *t;
        while (!EExterno(p)) {
            if (p->NO.NInterno.Index > strlen(k)) {
                caractere = k[strlen(k)];
            } else {
                caractere = Caractere(p->NO.NInterno.Index, k);
            }
            compInsercaoPatricia++;  // Contador de comparações
            if (caractere < p->NO.NInterno.caractere) {
                p = p->NO.NInterno.Esq;
            } else {
                p = p->NO.NInterno.Dir;
            }
        }
        if (strcasecmp(k, p->NO.NExterno.Chave) == 0) {
            if (p->NO.NExterno.indice_invertido->idDoc != idDoc) {
                insere(&p->NO.NExterno.indice_invertido, idDoc, repeticao);
            }
            return (*t);
        } else {
            i = 0;
            while (i < strlen(k) && tolower(Caractere(i, k)) == tolower(Caractere(i, p->NO.NExterno.Chave))) {
                i++;
                compInsercaoPatricia++;  // Contador de comparações
            }
            if (i < strlen(k)) {
                if (tolower(Caractere(i, k)) > tolower(Caractere(i, p->NO.NExterno.Chave))) {
                    charDiff = k[i];
                } else {
                    charDiff = p->NO.NExterno.Chave[i];
                }
                compInsercaoPatricia++;  // Contador de comparações
            } else {
                charDiff = '\0';
            }
            return InsereEntre(k, t, i, charDiff, idDoc, repeticao);
        }
    }
}
void Pesquisa(String k, Apontador t) {
    if (t == NULL) {
        printf("A árvore está vazia!!!\n");
        return;
    }
    if (EExterno(t)) {
        if (strncasecmp(k, t->NO.NExterno.Chave, strlen(k)) == 0) {
            printf("Palavra %s encontrada:\n", t->NO.NExterno.Chave);
            imprimeLista(t->NO.NExterno.indice_invertido);
            printf("\n");
        }
    } else {
        // Contagem de comparações para a busca
        int index = t->NO.NInterno.Index;
        compInsercaoPatricia++;  // Contador de comparações
        if (Caractere(index, k) >= t->NO.NInterno.caractere) {
            Pesquisa(k, t->NO.NInterno.Dir);
        } else {
            Pesquisa(k, t->NO.NInterno.Esq);
        }
    }
}

void ImprimirPalavras(Apontador t) {
    if (t == NULL) {
        return;
    }
    if (EExterno(t)) {
        printf("Palavra: %s ", t->NO.NExterno.Chave);
        imprimeLista(t->NO.NExterno.indice_invertido);
        printf("\n");
    } else {
        ImprimirPalavras(t->NO.NInterno.Esq);
        ImprimirPalavras(t->NO.NInterno.Dir);
    }
}

void qtd_iddoc(int numDocumentos, Apontador t, String termo) {
    if (t == NULL) {
        printf("A árvore está vazia!!!\n");
        return;
    }
    Apontador p = t;
    while (!EExterno(p)) {
        int index = p->NO.NInterno.Index;
        if (Caractere(index, termo) >= p->NO.NInterno.caractere) {
            p = p->NO.NInterno.Dir;
            compBuscaPatricia++;
        } else {
            p = p->NO.NInterno.Esq;
            compBuscaPatricia++;
        }
    }
    if (strncasecmp(termo, p->NO.NExterno.Chave, strlen(termo)) == 0) {
        printf("Termo '%s' encontrado:\n", p->NO.NExterno.Chave);
        imprimeLista(p->NO.NExterno.indice_invertido);
        printf("\n");
    } else {
        printf("Termo '%s' não encontrado na árvore.\n", termo);
    }
}

void CalcularRelevanciaPatricia(int numDocumentos, Apontador t, String termo) {
    if (t == NULL) {
        printf("A árvore está vazia!!!\n");
        return;
    }
    int q = strlen(termo);
    int N = numDocumentos;
    Apontador p = t;
    while (!EExterno(p)) {
        int index = p->NO.NInterno.Index;
        if (Caractere(index, termo) >= p->NO.NInterno.caractere) {
            p = p->NO.NInterno.Dir;
        } else {
            p = p->NO.NInterno.Esq;
        }
    }
    if (strncasecmp(termo, p->NO.NExterno.Chave, strlen(termo)) == 0) {
        printf("Termo '%s' encontrado:\n", p->NO.NExterno.Chave);
        Lista *atual = p->NO.NExterno.indice_invertido;
        while (atual != NULL) {
            int f = atual->qtde;
            double w = (f > 0) ? f * log10((double)N / f) / q : 0;
            if (f > 0) {
                printf("Documento %d: relevância %.2f\n", atual->idDoc, w);
            }
            atual = atual->proxDoc;
        }
    } else {
        printf("Termo '%s' não encontrado na árvore.\n", termo);
    }
}