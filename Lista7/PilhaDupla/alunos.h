/*
    alunos.h
    Exercicio 7 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 02/04/2021
    github: JoaoGBarros
*/

#ifndef ALUNOS_H
#define ALUNOS_H

typedef struct alunos Alunos;
Alunos* CriaAluno(char *nome, float nota, char* matricula);
void DestroiAluno(Alunos* a);
void ImprimeAluno(Alunos* a);

#endif