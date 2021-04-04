/*
    main.c - PilhaDupla 
    Exercicio 7 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 02/04/2021
    github: JoaoGBarros
*/



#include <stdio.h>
#include <stdlib.h>
#include "pilhaDupla.h"


int main(){
    PilhaDupla *pilha, *pilha2;

    pilha = iniciaPilha();

    push(pilha, 2, "joao", 10, "1"); //A chave(1/2) serve para saber qual parte da pilha deve ser colocada as informacoes
    push(pilha, 2, "roberto", 9.5, "2");
    push(pilha, 2, "keko", 8.9, "3");
    push(pilha, 2, "estevao", 10, "4");

    ImprimePilha(pilha, 1); //Deve imprimir "pilha 1 vazia" -> Elementos de pilha foram armazenados na pilha 2
    ImprimePilha(pilha, 2);

    ImprimeAluno(pop(pilha,1)); //Deve imprimir pilha vazia, ja que esta acessando a pilha 1, quando os alunos foram incluidos na 2
    printf("\n");

    ImprimePilha(pilha, 3); //Deve imprimir chave invalida, ja que a pilha possui apenas 2 chaves possiveis
    printf("\n");


    pilha2 = iniciaPilha();

    push(pilha2, 1, "joao", 10, "1");
    push(pilha2, 1, "roberto", 9.5, "2");
    push(pilha2, 1, "keko", 8.9, "3");
    push(pilha2, 1, "estevao", 10, "4");

    ImprimePilha(pilha2, 1);

    DestroiPilhaEspecifica(pilha, 1);

    DestroiPilhaToda(pilha);
    DestroiPilhaToda(pilha2);



    return 0;
}