/*
    Pokemon.c
    Exercicio 8 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 10/04/2021
    github: JoaoGBarros
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pokemon.h"


struct pokemon{
    char* nome;
    int numero_pokedex_jogador;
    char* tipo1;
    char* tipo2;
};

Pokemon* CadastraPokemon(char* nome, int numero_pokedex_jogador, char* tipo1, char* tipo2){
    Pokemon* p;
    p = (Pokemon*)malloc(sizeof(Pokemon));
    p->nome = strdup(nome);
    p->numero_pokedex_jogador = numero_pokedex_jogador;
    p->tipo1 = strdup(tipo1);
    p->tipo2 = strdup(tipo2);

    return p;
}


void DestroiPokemon(Pokemon* p){
    free(p->nome);
    free(p->tipo1);
    free(p->tipo2);
    free(p);
}

void ImprimePokemon(Pokemon* p){
    printf("Pokemon: %s\n", p->nome);
    printf("Tipo: %s\n", p->tipo1);
    if(strcmp(p->tipo2, "None")){
        printf("Tipo: %s\n", p->tipo2);
    }
    printf("\n");
}

char* retornaNomePokemon(Pokemon *p){
    return p->nome;
}