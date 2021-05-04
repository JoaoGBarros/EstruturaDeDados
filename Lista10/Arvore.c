#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arvore.h"
#define MAX 100


struct arvore{
    Album* album;
    int id;
    Arvore* esquerda;
    Arvore* direita;
};

Arvore* CriaArvoreVazia(){
    Arvore* arvore;
   
    arvore = NULL;

    return arvore;
}

Arvore* InsereArvore(Arvore* a, Album* album, int* id){
    if(a == NULL){
        a = malloc(sizeof(Arvore));
        a->album = album;
        a->esquerda = NULL;
        a->direita = NULL;
        a->id = *id;
        *id = *id + 1;
    }else if(RetornaStreaming(album) < RetornaStreaming(a->album)){
        a->esquerda = InsereArvore(a->esquerda, album, id);
    }else{
        a->direita = InsereArvore(a->direita, album, id);
    }

    return a;
}

void ImprimeArvore(Arvore* a){
    if(a){
        ImprimeAlbum(a->album);
        ImprimeArvore(a->esquerda);
        ImprimeArvore(a->direita);
    }
}

void DestroiArvore(Arvore* a){
    if(a){
        DestroiAlbum(a->album);
        DestroiArvore(a->esquerda);
        DestroiArvore(a->direita);
        free(a);
    }
}

void ImprimeGrafico(Arvore* a, int* contador, FILE* dot, int* id){
    if(*contador == 0){
            fprintf(dot, "strict graph {\n");
            *contador += 1;
    }
    if(a){
        fprintf(dot, "no%d[label=%c%s%c];\n", a->id, '"', RetornaNome(a->album), '"');
      
        if(a->esquerda){
            fprintf(dot, "no%d--no%d;\n", a->id, a->esquerda->id);
            ImprimeGrafico(a->esquerda, contador, dot, id);
            *contador += 1;
        }

        if(a->direita){
            fprintf(dot, "no%d--no%d;\n", a->id, a->direita->id);
            ImprimeGrafico(a->direita, contador, dot, id);
            *contador += 1;
        }

        if(*contador >= *id-1){
            fprintf(dot, "}\n");
        }
    }
}


Arvore* RetiraArvore(Arvore *a, int streaming, int* id, int* contador){
    int c = 0;
    if(a == NULL){
        return NULL;
    }

    if(RetornaStreaming(a->album) > streaming){
        a->esquerda = RetiraArvore(a->esquerda, streaming, id, contador);
    }else if(RetornaStreaming(a->album) < streaming){
        a->direita = RetiraArvore(a->direita, streaming, id, contador);
    }else{
        if(a->direita == NULL && a->esquerda == NULL){
            DestroiArvore(a);
            *id = *id - 1;
            a = NULL;
        }else if(a->esquerda == NULL){
            Arvore* aux;
            aux = a;
            *id = *id - 1;
            a = a->direita;
            DestroiAlbum(aux->album);
            free(aux);
        }else if(a->direita == NULL){
            Arvore* aux;
            aux = a;
            *id = *id - 1;
            a = a->esquerda;
            DestroiAlbum(aux->album);
            free(aux);
        }else{
            Arvore* aux;
            aux = a->esquerda;
            while(aux->direita != NULL){
                aux = aux->direita;
                Album* t;
                t = a->album;
                a->album = aux->album;
                aux->album = t;
                c += 1;
                a->esquerda = RetiraArvore(a->esquerda, streaming, id, contador);
            }
        }
    }
    *id = *id - c;
    *contador = 0;
    return a;
}

