/*
    main.c - pilhaMultipla 
    Exercicio 7 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 02/04/2021
    github: JoaoGBarros
*/


#include <stdio.h>
#include <stdlib.h>
#include "pilhaMultipla.h"


int main(){
    PilhaMultipla *pilha;

    pilha = iniciaPilha();

    push(pilha, 0, "joao", 10, 1);
    push(pilha, 0, "estevao", 10, 2);
    push(pilha, 1, "marcelo", 9, 3);
    push(pilha, 1, "marcella", 7.3, 4);
    push(pilha, 2, "ander", 7.8, 5);
    push(pilha, 2, "marina", 6.8, 6);
    push(pilha, 3, "romario", 5.6, 7);
    push(pilha, 3, "rodrigo", 7.6, 8);
    push(pilha, 4, "rogerio", 8.9, 9);
    push(pilha, 4, "roberto", 6.7, 10);
    push(pilha, 5, "felipe", 9.6, 11);
    push(pilha, 5, "ricardo", 6.5, 20);
    push(pilha, 6, "yan", 8.5, 12);
    push(pilha, 6, "sther", 7.8, 13);
    push(pilha, 7, "matheus", 9.0, 14);
    push(pilha, 7, "maria", 3.6, 15);
    push(pilha, 8, "pedro", 1.5, 16);
    push(pilha, 8, "vitor", 8.6, 17);
    push(pilha, 9, "enzo", 8.4, 18);
    push(pilha, 9, "manuela", 7.9, 19);
    

    ImprimeTodaPilha(pilha);
    ImprimePilha(pilha, 0);
    Alunos* a = pop(pilha, 5);
    ImprimeAluno(a);
    DestroiAluno(a);
    
    DestroiPilhaEspecifica(pilha, 5);
    

    DestroiTodaPilha(pilha);

    return 0;
}