
/*
    pilhaDupla.h - PilhaDupla 
    Exercicio 7 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 02/04/2021
    github: JoaoGBarros
*/


#ifndef PILHA_H
#define PILHA_H
#include "alunos.h"

typedef struct pilhaDupla PilhaDupla;

PilhaDupla* iniciaPilha();
void push(PilhaDupla* p, int chave, char* nome, float nota, char* matricula);
Alunos* pop(PilhaDupla *p, int chave);
void ImprimePilha(PilhaDupla *p, int chave);
void DestroiPilhaEspecifica(PilhaDupla *p, int chave);
void DestroiPilhaToda(PilhaDupla *p);

#endif