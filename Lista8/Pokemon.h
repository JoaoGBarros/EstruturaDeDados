
/*
    Pokemon.h
    Exercicio 8 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 10/04/2021
    github: JoaoGBarros
*/


#ifndef POKEMON_H
#define POKEMON_H

typedef struct pokemon Pokemon;

Pokemon* CadastraPokemon(char* nome, int numero_pokedex_jogador, char* tipo1, char* tipo2);
void NicknamePokemon(Pokemon* p, char* nickname);
void DestroiPokemon(Pokemon* p);
char* retornaNomePokemon(Pokemon *p);
void ImprimePokemon(Pokemon* p);

#endif