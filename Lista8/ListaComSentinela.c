/*
    ListaComSEntina.c
    Exercicio 8 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 10/04/2021
    github: JoaoGBarros
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaComSentinela.h"




struct celula{
    Pokemon *pokemon;
    Celula* prox;
};

struct lista{
    Celula* prim;
    Celula* ult;
};


Lista* CriaLista(){
    Lista *a;
    a = (Lista*)malloc(sizeof(Lista));

    a->prim = NULL;
    a->ult = NULL;

    return a;
}


void InsereLista(Lista *l, char* nome, int numero_pokedex_jogador, char* tipo1, char* tipo2){
    Celula *c;
    c = (Celula*)malloc(sizeof(Celula));
    c->pokemon = CadastraPokemon(nome, numero_pokedex_jogador, tipo1, tipo2);
    c->prox = NULL;

    if(l->ult == NULL){
        l->prim = l->ult = c;
        return;
    }

    l->ult->prox = c;
    l->ult = c;
}


Pokemon* RetiraLista(Lista* l){
    Celula *c = l->prim;
    Celula *v = c->prox;
    Pokemon *p;
    if(c){
        if(v == NULL){ //Se so tiver apenas 1 elemento na lista
            l->prim = NULL;
            l->ult = NULL;
        }else{
            l->prim = v;
        }
        p = c->pokemon;
        free(c);
        return p;
    }else{
        return NULL;
    }
    
}


void ImprimeLista(Lista* l){
    Celula* c;
    for(c = l->prim; c != NULL; c = c->prox){
        ImprimePokemon(c->pokemon);
    }
}


void DestroiLista(Lista* l){
    Celula *c = l->prim;
    Celula *aux;

    while(c){
        aux = c->prox;
        DestroiPokemon(c->pokemon);
        free(c);
        c = aux;
    }

    free(l);
}

void InsereListaPokemons(Lista *l, Pokemon* p){
    Celula *c;
    c = (Celula*)malloc(sizeof(Celula));
    c->pokemon = p;
    c->prox = NULL;

    if(l->ult == NULL){
        l->prim = l->ult = c;
        return;
    }

    l->ult->prox = c;
    l->ult = c;
}