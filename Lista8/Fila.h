
/*
    Fila.h
    Exercicio 8 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 10/04/2021
    github: JoaoGBarros
*/



#ifndef FILA_H
#define FILA_H
#include "ListaComSentinela.h"

typedef struct fila FilaLista;
typedef struct filaV FilaVetor;

FilaLista* IniciaFilaLista();
void InsereFilaLista(FilaLista *f, char* nome, int numero_pokedex_jogador, char* tipo1, char* tipo2);
Pokemon* RetiraFilaLista(FilaLista* f);
void ImprimeFilaLista(FilaLista *f);
void DestroiFilaLista(FilaLista *f);
void InsereFilaListaPokemon(FilaLista *f, Pokemon *p);



FilaVetor *IniciaFilaVetor();
void InsereFilaVetor(FilaVetor *f, Pokemon* p);
Pokemon* RetiraFilaVetor(FilaVetor *f);
void ImprimeFilaVetor(FilaVetor *f);
void DestroiFilaVetor(FilaVetor *f);

#endif