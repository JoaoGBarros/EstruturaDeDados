/*
    pilhaMultipla.c - pilhaMultipla 
    Exercicio 7 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 02/04/2021
    github: JoaoGBarros
*/


#include <stdio.h>
#include <stdlib.h>
#include "pilhaMultipla.h"
#define MaxTam 100
#define N 10

typedef struct indice IndicePilha;

struct indice{
    int topo;
    int base;
};

struct pilhaMultipla{
    Alunos* Item[MaxTam];
    IndicePilha Pilha[N];
};

PilhaMultipla* iniciaPilha(){

    PilhaMultipla *p;


    p = (PilhaMultipla*)malloc(sizeof(PilhaMultipla));
    for(int i = 0, tam = 0; i < N; i++, tam += MaxTam/N){
        p->Pilha[i].base = tam; // 0 - 8; 9 - 18; 19 - 28; 29 - 38; 39 - 48; 49-58 ....
        p->Pilha[i].topo = tam-1; //i = 0 -> tam = 0; i = 1 -> tam = 10; i = 2 -> tam = 20
    }

    return p;
}

void push(PilhaMultipla* p, int chave, char* nome, float nota, int matricula){
    if(chave > N-1 || chave < 0) {
        printf("Chave invalida\n");
    }else{
        if(chave == N-1 && p->Pilha[chave].topo != MaxTam-1){
            p->Pilha[chave].topo++;
            p->Item[p->Pilha[chave].topo] = CriaAluno(nome, nota, matricula);
        }else if(p->Pilha[chave].topo + 1 != p->Pilha[chave+1].base){
            p->Pilha[chave].topo++;
            p->Item[p->Pilha[chave].topo] = CriaAluno(nome, nota, matricula);
        }else{
            printf("Lista cheia");
        }
    }


}

Alunos* pop(PilhaMultipla *p, int chave){
    Alunos* a;
    if(chave > N-1 || chave < 0) {
        printf("Chave invalida\n");
        return NULL;
    }else{
        printf("topo da pilha: %d, base da pilha: %d\n", p->Pilha[chave].topo, p->Pilha[chave].base);
        if(p->Pilha[chave].topo == p->Pilha[chave].base-1){
            printf("A pilha %d esta vazia", chave);
            return NULL;
        }
        a = p->Item[p->Pilha[chave].topo];
        p->Item[p->Pilha[chave].topo] = NULL;
        p->Pilha[chave].topo--;
    }

    return a;
}

void ImprimePilha(PilhaMultipla *p, int chave){
    int i;
    if(chave > N-1 || chave < 0){
        printf("Chave invalida\n");
    }else{
        if(p->Pilha[chave].topo == p->Pilha[chave].base-1){
            printf("A pilha %d esta vazia", chave);
            return;
        } 
        for(i = p->Pilha[chave].topo; i >= p->Pilha[chave].base; i--){
            ImprimeAluno(p->Item[i]);
        }
    
    printf("\n");
    }
}

void DestroiPilhaEspecifica(PilhaMultipla *p, int chave){
    if(chave > N-1 || chave < 0){
        printf("Chave Invalida\n");
    }else{
        if(p){
            for(int i = p->Pilha[chave].topo; i >= p->Pilha[chave].base; i--){
                if(p->Item[i]){
                    DestroiAluno(p->Item[i]);
                    p->Pilha[chave].topo--;
                }
            }
        }
    }
}

void DestroiTodaPilha(PilhaMultipla *p){
    if(p){
        for(int i = 0; i < N; i++){
            DestroiPilhaEspecifica(p, i);
        }
        free(p);
    }
}

void ImprimeTodaPilha(PilhaMultipla *p){
    for(int i = 0; i < N; i++){
        ImprimePilha(p, i);
        printf("\n");
    }
}