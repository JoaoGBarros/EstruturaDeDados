/*
    alunos.c
    Exercicio 7 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 02/04/2021
    github: JoaoGBarros
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alunos.h"

struct alunos{
    char *nome;
    float nota;
    char* matricula;
};


Alunos* CriaAluno(char *nome, float nota, char* matricula){
    Alunos* a;
    a = (Alunos*)malloc(sizeof(Alunos));

    a->nome = strdup(nome);
    a->matricula = strdup(matricula);
    a->nota = nota;


    return a;
}


void ImprimeAluno(Alunos* a){
    if(a){
        printf("Nome: %s  ", a->nome);
        printf("Nota: %.2f  ", a->nota);
        printf("Matricula: %s", a->matricula);
        printf("\n");
    }
}



void DestroiAluno(Alunos* a){
    free(a->matricula);
    free(a->nome);
    free(a);
}