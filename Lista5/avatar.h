#ifndef AVATAR_H
#define AVATAR_H

typedef struct avatar Avatar;

Avatar* criaAvatar(char* nome, char* origem);
void mostraAvatar(Avatar *a);
char* retornaNome(Avatar *a);
void apagaAvatar(Avatar *a);

#endif
