/*
    testador.c
    Exercicio 4 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 10/03/2021
    github: JoaoGBarros
*/

#include <stdio.h>
#include <stdlib.h>
#include "listaMat.h"
#include "matriz.h"
#define linha_padrao 4
#define coluna_padrao 4


void modificaValor(Matriz *a, int k){
    for(int i = 0; i < linha_padrao; i++){
        for(int j = 0; j < coluna_padrao; j++){
            modificaElemento(a, i, j, k+j);
        }
    }
}

int main(){
    Matriz *m1, *m2, *m3, *m4;
    Matriz *t1, *t2, *t3, *t4;
    Lista *l1, *l2;


    m1 = inicializaMatriz(linha_padrao, coluna_padrao);
    m2 = inicializaMatriz(linha_padrao, coluna_padrao);
    m3 = inicializaMatriz(linha_padrao, coluna_padrao);
    m4 = inicializaMatriz(linha_padrao, coluna_padrao);



    modificaValor(m1, rand() % 10);
    modificaValor(m2, rand() % 10);
    modificaValor(m3, rand() % 10);
    modificaValor(m4, rand() % 10);

    l1 = iniciaLista();

    insereLista(l1, m1);
    insereLista(l1, m2);
    insereLista(l1, m3);
    insereLista(l1, m4);

    l2 = iniciaLista();

    t1 = transposta(m1);
    t2 = transposta(m2);
    t3 = transposta(m3);
    t4 = transposta(m4);

    insereLista(l2, t1);
    insereLista(l2, t2);
    insereLista(l2, t3);
    insereLista(l2, t4);

    imprimeLista(l1);
    imprimeLista(l2);

    Matriz *retirado1 = retiraElemento(l1, m4); // Retira o elemento da primeira posicao
    Matriz *retirado2 = retiraElemento(l1, m1); // Retira o elemento da ultima posicao
    Matriz *retirado3 = retiraElemento(l1, m2); // Retira um elemento comum


    imprimeLista(l1);

    insereLista(l1, retirado1);
    imprimeLista(l1);

    insereLista(l1, retirado2);
    imprimeLista(l1);

    insereLista(l1, retirado3);
    imprimeLista(l1);

    liberaLista(l1);
    liberaLista(l2);

    destroiMatriz(m1);
    destroiMatriz(m2);
    destroiMatriz(m3);
    destroiMatriz(m4);
    destroiMatriz(t1);
    destroiMatriz(t2);
    destroiMatriz(t3);
    destroiMatriz(t4);




    return 0;
}