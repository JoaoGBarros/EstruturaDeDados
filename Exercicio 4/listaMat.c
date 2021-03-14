/*
    listaMat.c
    Exercicio 4 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 10/03/2021
    github: JoaoGBarros
*/




#include <stdio.h>
#include <stdlib.h>
#include "listaMat.h"
#include "matriz.h"


struct celula{
    Matriz *matriz;
    Celula *prox;
};

struct lista{
    Celula *first;
    Celula *last;
};


Lista *iniciaLista(){
    Lista *a;
    a = (Lista*)malloc(sizeof(Lista));

    a->first = NULL;
    a->last = NULL;

    return a;
}

void insereLista(Lista *l, Matriz *m){
    Celula *n;

    n = (Celula*)malloc(sizeof(Celula));

    n->matriz = m;
    n->prox = l->first;
    l->first = n;

    if(!l->last){
        l->last = n;
    }
}



void imprimeLista(Lista *l){
    Celula *p;
    printf("========LISTA============\n");
    for(p = l->first; p; p = p->prox){
        imprimeMatriz(p->matriz);
    }
}


Matriz *retiraElemento(Lista *l, Matriz *m){
    Celula *p = l->first;
    Matriz *mat;
    Celula *prev = NULL;

    while(p && p->matriz != m){
        prev = p;
        p = p->prox;
    }

    if(!p){
        return NULL;
    }

    mat = m;


    if(p == l->first && p == l->last){
        l->first = NULL;
        l->last = NULL;
    }else if(p == l->first){
        l->first = p->prox;
    }else if(p == l->last){
        l->last = prev;
        l->last->prox = NULL;
    }else{
        prev->prox = p->prox;
    }
    free(p);
    return mat;

}



void liberaLista(Lista *l){
    Celula *p = l->first;
    Celula *aux;
    while(p != NULL){
        aux = p->prox;
        free(p);
        p = aux;
    }
    free(l);
}