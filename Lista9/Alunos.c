#include "Alunos.h"


struct aluno{
    char* nome;
    char* matricula;
    float media;
};


Aluno* CriaAluno(char* nome, char*matricula, float media){
    Aluno* p;

    p = (Aluno*)malloc(sizeof(Aluno));
    p->nome = strdup(nome);
    p->matricula = strdup(matricula);
    p->media = media;

    return p;
}

char* retornaNome(Aluno* a){
    return a->nome;
}

char* retornaMatricula(Aluno* a){
    return a->matricula;
}

void ImprimeAluno(Aluno *a){
    printf("Nome: %s\n", a->nome);
    printf("Matricula: %s\n", a->matricula);
    printf("Media: %.2f\n", a->media);
}

void DestroiAluno(Aluno *a){
    free(a->nome);
    free(a->matricula);
    free(a);
}

