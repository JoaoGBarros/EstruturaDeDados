#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaAvatar.h"




struct ciclo{
    Avatar *avatar;
    Ciclo *sucessor;
    Ciclo *antecessor;
};

Ciclo *iniciaCiclo(){
    return NULL;
}

Ciclo* insereAvatar(Ciclo *c, Avatar *a){
    Ciclo *novo;

    novo = (Ciclo*)malloc(sizeof(Ciclo));

    novo->avatar = a;
    novo->antecessor = NULL;
    novo->sucessor = c;

    if(c != NULL){
        c->antecessor = novo;
    }

    return novo;
}

void pergaminhoDoCiclo(Ciclo *c){
    printf("========= CICLO AVATAR ===========\n");
    Ciclo *p;

    for(p = c; p != NULL; p = p->sucessor){
        mostraAvatar(p->avatar);
    }

    printf("\n");

}

static Ciclo *busca(Ciclo *c, char* nome){
    Ciclo *p;

    for(p = c; p != NULL; p->sucessor){
        if(strcmp(retornaNome(p->avatar), nome) == 0){
            return p;
        }
    }
    return NULL;
}

Ciclo *destroiCiclo(Ciclo *c, char* nome){
    Ciclo *p;

    for(p = c; strcmp(retornaNome(p->avatar), nome); p = p->sucessor){
        p = removeLista(p, retornaNome(p->avatar));
    }

    return p;
}

Ciclo *removeLista(Ciclo *c, char*nome){
    Ciclo *p;
    p = busca(c, nome);

    if(p == NULL){
        return c;
    }

    if(c == p){
        c = p->sucessor;
    }else{
        p->antecessor->sucessor = p->sucessor;
    }

    if(p->sucessor != NULL){
        p->sucessor->antecessor = p->antecessor;
    }

    free(p);

    return c;
}

void apagaCiclo(Ciclo *c){
    Ciclo *p = c;
    Ciclo *aux;
    while(p != NULL) {
        aux = p->antecessor; // A lista de sucessores foi apagada na funcao destroiOCiclo
        free(p);
        p = aux;
    }
}
