#ifndef ARVORE_H
#define ARVORE_H

#include "Albuns.h"
typedef struct arvore Arvore;

Arvore* CriaArvoreVazia();
Arvore* InsereArvore(Arvore* a, Album* album, int* id);
void DestroiArvore(Arvore* a);
void ImprimeArvore(Arvore* a);
void ImprimeGrafico(Arvore* a, int* contador, FILE* dot, int* id);
Arvore* RetiraArvore(Arvore *a, int streaming, int* id, int* contador);

#endif