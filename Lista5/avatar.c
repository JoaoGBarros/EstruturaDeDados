#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avatar.h"


struct avatar{
    char* nome;
    char* origem;
};


Avatar* criaAvatar(char* nome, char* origem){
    Avatar *hm;

    hm = (Avatar*)malloc(sizeof(Avatar));
    hm->nome = strdup(nome);
    hm->origem = strdup(origem);

    return hm;
}

void mostraAvatar(Avatar *a){
    printf("Avatar %s\t\t", a->nome);
    printf("Origem: %s\n", a->origem);
}

char* retornaNome(Avatar *a){
    return a->nome;
}

void apagaAvatar(Avatar *a){
    free(a->nome);
    free(a->origem);
    free(a);
}