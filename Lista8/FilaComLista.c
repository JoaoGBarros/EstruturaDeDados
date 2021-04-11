/*
    FilaComLista.c
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



struct fila{
    Lista *lista;
};

FilaLista* IniciaFilaLista(){
    FilaLista *f;
    f = (FilaLista*)malloc(sizeof(FilaLista));
    f->lista = CriaLista();
    return f;
}

void InsereFilaLista(FilaLista *f, char* nome, int numero_pokedex_jogador, char* tipo1, char* tipo2){
    InsereLista(f->lista, nome, numero_pokedex_jogador, tipo1, tipo2);
}

void InsereFilaListaPokemon(FilaLista *f, Pokemon *p){
    InsereListaPokemons(f->lista, p);
}

Pokemon* RetiraFilaLista(FilaLista* f){
    return RetiraLista(f->lista);
}

void ImprimeFilaLista(FilaLista *f){
    ImprimeLista(f->lista);
}

void DestroiFilaLista(FilaLista *f){
    DestroiLista(f->lista);
    free(f);
}