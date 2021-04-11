/*
    FilaComVetor.c
    Exercicio 8 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 10/04/2021
    github: JoaoGBarros
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"
#define TAM 10



struct filaV{
    int ini;
    int n;
    Pokemon *exintos[TAM];
};

FilaVetor *IniciaFilaVetor(){
    FilaVetor *f;
    f = (FilaVetor*)malloc(sizeof(FilaVetor));
    f->ini = 0;
    f->n = 0;

    return f;
}

void InsereFilaVetor(FilaVetor *f, Pokemon* p){
    if(!f || f->n >= TAM){
        printf("Fila invalida ou cheia!\n");
        return;
    }

    int pos = (f->ini + f->n) % TAM;

    f->exintos[pos] = p;
    f->n++;
}

Pokemon* RetiraFilaVetor(FilaVetor *f){
    Pokemon *p;
    if(!f || f->n == 0){
        printf("Fila invalida ou vazia!\n");
        return NULL;
    }

    p = f->exintos[f->ini];

    f->ini = (f->ini + 1) % TAM;
    f->n--;

    return p;
}

void ImprimeFilaVetor(FilaVetor *f){
    int pos = 0;
    if(!f){
        return;
    }

    for(int i = 0; i < f->n; i++){
        pos = (f->ini + i) % TAM;
        ImprimePokemon(f->exintos[pos]);
    }
}


void DestroiFilaVetor(FilaVetor *f){
    int pos = 0;
    if(!f){
        return;
    }

    for(int i = 0; i < f->n; i++){
        pos = (f->ini + i) % TAM;
        DestroiPokemon(f->exintos[pos]);
    }
    free(f);
}

