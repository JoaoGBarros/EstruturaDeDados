/*
    pilhaMultipla.h - pilhaMultipla 
    Exercicio 7 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 02/04/2021
    github: JoaoGBarros
*/



#ifndef PILHA_H
#define PILHA_H
#include "alunos.h"

typedef struct pilhaMultipla PilhaMultipla;


PilhaMultipla* iniciaPilha();
void push(PilhaMultipla* p, int chave, char* nome, float nota, int matricula);
Alunos* pop(PilhaMultipla *p, int chave);
void ImprimePilha(PilhaMultipla *p, int chave);
void DestroiPilhaEspecifica(PilhaMultipla *p, int chave);
void DestroiTodaPilha(PilhaMultipla *p);
void ImprimeTodaPilha(PilhaMultipla *p);

#endif