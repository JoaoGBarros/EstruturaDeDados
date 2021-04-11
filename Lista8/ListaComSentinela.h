
/*
    FilaComSentinela.h
    Exercicio 8 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 10/04/2021
    github: JoaoGBarros
*/

#ifndef LISTA_COM_SENTINELA
#define LISTA_COM_SENTINELA
#include "Pokemon.h"
typedef struct celula Celula;
typedef struct lista Lista;

Lista* CriaLista();

void InsereLista(Lista *l, char* nome, int numero_pokedex_jogador, char* tipo1, char* tipo2);

Pokemon* RetiraLista(Lista* l);

void ImprimeLista(Lista* l);

void DestroiLista(Lista* l);

void InsereListaPokemons(Lista *l, Pokemon* p);


#endif