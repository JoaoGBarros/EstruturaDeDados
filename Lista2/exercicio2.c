
/*
    exercicio2.c
    Exercicio 2 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha 
    Matricula: 2019107717
    Data: 11/02/2021
    github: JoaoGBarros
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char *nome;
    int matricula;
    float p1;
    float p2;
    float p3;
}Aluno;


void imprime_aprovados (int n, Aluno** turma){
    float media;
    printf("------------- Alunos Aprovados -------------\n");
    for(int i = 0; i < n; i++){
        media = turma[i]->p1 + turma[i]->p2 + turma[i]->p3;
        media = media / 3;
        if(media >= 5){
            printf("Nome: %s\n", turma[i]->nome);
            printf("Matricula: %d\n\n", turma[i]->matricula);
        }
    }
}

float media_turma (int n, Aluno** turma){
    float soma = 0, media_T, media;

    for(int i = 0; i < n; i++){
        media = turma[i]->p1 + turma[i]->p2 + turma[i]->p3;
        media = media / 3;
        soma = soma + media; //Soma da media da turma
    }
    
    media_T = soma / n; //soma das medias divida pela quantidade alunos

    return media_T;
}

int main(){
    int n, i;
    char nombre[100];
    Aluno **turma;
    printf("Informe o numero de alunos na turma: ");
    scanf("%d", &n);

    turma = (Aluno**)malloc(sizeof(Aluno*) * n); 

    for(int i = 0; i < n; i++){
        turma[i] = (Aluno*)malloc(sizeof(Aluno));

    }

    for(i = 0; i < n; i++){
        printf("Informe os dados do aluno\n");
        printf("Nome: ");
        scanf("%s", nombre); //Forneco a string para uma varival name que armazena ate 99 caracteres.
        turma[i]->nome = (char*)malloc(sizeof(char) * strlen(nombre) + 1);
        // Faco a alocacao dinanmica de char utilizando o tamanho da string dada anteriormente. Somar 1 devido ao \0
        turma[i]->nome = strcpy(turma[i]->nome, nombre);
        // Copio o conteudo de da variavel name para o, ja alocado, elemento nome da estrutura 
        printf("\n");
        printf("Matricula: ");
        scanf("%d", &turma[i]->matricula);
        printf("\n");
        printf("Informa as notas da p1, p2 e p3 respectivamente: ");
        scanf("%f %f %f", &turma[i]->p1, &turma[i]->p2, &turma[i]->p3);
        printf("\n");
    }


    for(i = 0; i < n; i++){
        printf("Matricula: %d\n", turma[i]->matricula);
        printf("Nome: %s\n", turma[i]->nome);
        printf("P1: %.2f\n", turma[i]->p1);
        printf("P2: %.2f\n", turma[i]->p2);
        printf("P3: %.2f\n", turma[i]->p3);
        printf("\n\n");
    }

    imprime_aprovados(n, turma);
    printf("A media da turma foi de: %.2f\n", media_turma(n, turma));
    for(i = 0; i < n; i++){
        free(turma[i]->nome); //Libera a memoria alocada pelo nome 
        free(turma[i]); // Libera a memoria alocada pelo aluno
    }
    free(turma); //Libera a memoria alocada pela turma
    
   return 0;
}