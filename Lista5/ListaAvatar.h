#ifndef LISTA_AVATAR_H
#define LISTA_AVATAR_H

#include "avatar.h"

typedef struct ciclo Ciclo;

Ciclo *iniciaCiclo();
Ciclo *insereAvatar(Ciclo *c, Avatar *a);
void pergaminhoDoCiclo(Ciclo *c);
Ciclo *destroiCiclo(Ciclo *c, char* nome);
Ciclo *removeLista(Ciclo *c, char*nome);
void apagaCiclo(Ciclo *c);
#endif