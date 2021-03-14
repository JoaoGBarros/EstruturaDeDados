/*
    matriz.c
    Exercicio 3 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 26/02/2021
    github: JoaoGBarros
*/

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


struct matriz{
    int linha;
    int coluna;
    int **mat;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz *m;

    m = (Matriz*)malloc(sizeof(Matriz));
    m->linha = nlinhas;
    m->coluna =  ncolunas;
    m->mat = (int**)malloc(nlinhas * sizeof(int*));

    for(int i = 0; i < nlinhas; i++){
        m->mat[i] = (int*)malloc(ncolunas * sizeof(int));
    }

    return m;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->mat[linha][coluna] = elem;
}

void imprimeMatriz(Matriz* mat){
    for(int i = 0; i < mat->linha; i++){
        for(int j = 0; j < mat->coluna; j++){
            printf("%d ", mat->mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Matriz* transposta (Matriz* mat){
    Matriz *tr;

    tr = inicializaMatriz(mat->coluna, mat->linha);

    for(int i = 0; i < tr->linha; i++){
        for(int j = 0; j < tr->coluna; j++){
            tr->mat[i][j] = mat->mat[j][i];
        }
    }

    return tr;
}

void destroiMatriz(Matriz* mat){
    for(int i = 0; i < mat->linha; i++){
        free(mat->mat[i]);
    }
    free(mat->mat);
    free(mat);
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    int soma = 0;
    Matriz *mult;

    mult = inicializaMatriz(mat1->linha, mat2->coluna);

    for(int i = 0; i < mult->linha; i++){
        for(int j = 0; j < mult->coluna; j++) {
            for(int k = 0; k < mat1->coluna; k++){
                soma += mat1->mat[i][k] * mat2->mat[k][j];
            }
            mult->mat[i][j] = soma;
            soma = 0;
        }


    }

    return mult;
}

int recuperaNLinhas (Matriz* mat){
    return mat->linha;
}
int recuperaNColunas (Matriz* mat){
    return mat->coluna;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->mat[linha][coluna];
}
