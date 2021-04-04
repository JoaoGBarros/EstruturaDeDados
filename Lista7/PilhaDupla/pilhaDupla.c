/*
    PilhaDupla.c - PilhaDupla 
    Exercicio 7 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 02/04/2021
    github: JoaoGBarros
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilhaDupla.h"
#define MaxTam 10

typedef struct indice IndicePilha;

struct indice{
    int topo;
    int base;
};

struct pilhaDupla{
    Alunos* item[MaxTam];
    IndicePilha Pilha1, Pilha2;
};

PilhaDupla* iniciaPilha(){
    PilhaDupla *p;

    p = (PilhaDupla*)malloc(sizeof(PilhaDupla));
    p->Pilha1.base = 0;
    p->Pilha1.topo = -1;
    p->Pilha2.base = MaxTam - 1;
    p->Pilha2.topo = MaxTam;

    return p;
}

void push(PilhaDupla* p, int chave, char* nome, float nota, char* matricula){

    if(chave != 1 && chave != 2) {
        printf("Chave invalida\n");
    }else{
        if(p->Pilha1.topo + 1 != p->Pilha2.topo){
            if(chave == 1){
                p->Pilha1.topo++;
                p->item[p->Pilha1.topo] = CriaAluno(nome, nota, matricula);
            }else{
                p->Pilha2.topo--;
                p->item[p->Pilha2.topo] = CriaAluno(nome, nota, matricula);
            }
        }else{
            printf("Pilha esta cheia\n");
        }
    }


}

Alunos* pop(PilhaDupla *p, int chave){
    Alunos* a;
    if(chave != 1 && chave != 2) {
        printf("Chave invalida\n");
        return NULL;
    }else{
        if(chave == 1){
            if(p->Pilha1.topo == -1){
                printf("Pilha vazia\n");
                return NULL;
            }else{
                a = p->item[p->Pilha1.topo];
                p->Pilha1.topo--;
                return a;
            }
        }else {
            if (p->Pilha2.topo == MaxTam) {
                printf("Pilha vazia");
                return NULL;
            } else {
                a = p->item[p->Pilha2.topo];
                p->Pilha2.topo++;
                return a;
            }
        }
    }
}

void ImprimePilha(PilhaDupla *p, int chave){
    int i;
    if(chave != 1 && chave != 2){
        printf("Chave invalida\n");
    }else{
        if(chave == 1){
            i = p->Pilha1.topo;

            if(i == -1){
                printf("Pilha 1 vazia\n");
            }

            for(i; i >= 0; i--){
                ImprimeAluno(p->item[i]);
            }
        }else{
            i = p->Pilha2.topo;
            
            if(i == MaxTam){
                printf("Pilha 2 vazia\n");
            }

            for(i; i < MaxTam; i++){
                ImprimeAluno(p->item[i]);
            }
        }
    }
    printf("\n");
}

void DestroiPilhaEspecifica(PilhaDupla *p, int chave){
    if(chave != 1 && chave != 2){
        printf("Chave Invalida\n");
    }else{
        if(p){
            if(chave == 1){
                for(int i = p->Pilha1.topo; i >= 0; i--){
                    DestroiAluno(p->item[i]);
                    p->Pilha1.topo--;
                }
            }else{
                for(int i = p->Pilha2.topo; i< MaxTam; i++){
                    DestroiAluno(p->item[i]);
                    p->Pilha2.topo--;
                }
            }
        }
    }
}

void DestroiPilhaToda(PilhaDupla *p){
    if(p){
        for(int i = 1; i <= 2; i++){
            DestroiPilhaEspecifica(p, i);
        }

        free(p);
    }

}