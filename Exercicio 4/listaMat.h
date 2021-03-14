

/*
    listaMat.c
    Exercicio 4 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 10/03/2021
    github: JoaoGBarros
*/


#ifndef LISTA_MAT_H
#define LISTA_MAT_H

#include "matriz.h"

typedef struct celula Celula;
typedef struct lista Lista;



Lista *iniciaLista();
void insereLista(Lista *l, Matriz *m);
void imprimeLista(Lista *l);
Matriz *retiraElemento(Lista *l, Matriz *m);
void liberaLista(Lista *l);


#endif