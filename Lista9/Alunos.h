#ifndef ALUNOS_H
#define ALUNOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno* CriaAluno(char* nome, char*matricula, float media);
char* retornaNome(Aluno* a);
void ImprimeAluno(Aluno *a);
void DestroiAluno(Aluno *a);
char* retornaMatricula(Aluno* a);


#endif