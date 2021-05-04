#ifndef ALBUNS_H
#define ALBUNS_H

typedef struct album Album;

Album* CriaAlbum(char* artista, char* nome, int streaming);
int RetornaStreaming(Album *alb);
char* RetornaArtista(Album *alb);
char* RetornaNome(Album *alb);
void ImprimeAlbum(Album* album);
void DestroiAlbum(Album *a);
#endif