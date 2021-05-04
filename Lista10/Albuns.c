#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Albuns.h"




struct album{
    char* artista;
    char* nome;
    int streaming;
};

Album* CriaAlbum(char* artista, char* nome, int streaming){
    Album* a;
    a = (Album*)malloc(sizeof(Album));
    a->artista = strdup(artista);
    a->nome = strdup(nome);
    a->streaming = streaming;

    return a;
}

void ImprimeAlbum(Album* album){
    printf("Nome:%s   ", album->nome);
    printf("Artista: %s   ", album->artista);
    printf("Streaming:%d\n", album->streaming);
}

int RetornaStreaming(Album *alb){
    return alb->streaming;
}

char* RetornaArtista(Album *alb){
    return alb->artista;
}

char* RetornaNome(Album *alb){
    return alb->nome;
}

void DestroiAlbum(Album *a){
    free(a->artista);
    free(a->nome);
    free(a);
}

