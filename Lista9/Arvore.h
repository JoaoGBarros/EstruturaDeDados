#ifndef ARVORE_H
#define ARVORE_H

#include "Alunos.h"

typedef struct arvore Arvore;
Arvore* CriaArvore(char* nome, char* matricula, float media, Arvore *esquerda, Arvore *direita);
int ArvoreVazia(Arvore *arv);
Arvore* DestroiArvore(Arvore *arv);
int ArvorePertence(Arvore* arv, char* nome);
void ImprimeArvoreInformacoes(Arvore* arv);
Arvore* CriaArvoreVazia();
int ArvoreAltura(Arvore *arv);
int Ocorrencias(Arvore* arv, char* nome);
int Folhas(Arvore * arv);
void ImprimeArvore(Arvore* arv, FILE* saida);

#endif