#include "Arvore.h"

struct arvore{
    Aluno *aluno;
    Arvore* direita;
    Arvore* esquerda;
};


Arvore* CriaArvore(char* nome, char* matricula, float media, Arvore *esquerda, Arvore *direita){
    Arvore *arv;
    arv = (Arvore*)malloc(sizeof(Arvore));
    arv->aluno = CriaAluno(nome, matricula, media);
    arv->esquerda = esquerda;
    arv->direita = direita;

    return arv;
}

int ArvoreVazia(Arvore *arv){
    if(arv == NULL){
        return 1;
    }else{
        return 0;
    }
}


Arvore* DestroiArvore(Arvore *arv){
    if(!ArvoreVazia(arv)){
        DestroiAluno(arv->aluno);
        DestroiArvore(arv->esquerda);
        DestroiArvore(arv->direita);
        free(arv);
    }
    return NULL;
}

int ArvorePertence(Arvore* arv, char* nome){
    if(ArvoreVazia(arv)){
        return 0;
    }else{
        return(!strcmp(retornaNome(arv->aluno), nome)) || 
        ArvorePertence(arv->esquerda, nome) || 
        ArvorePertence(arv->direita, nome);
    }
}

void ImprimeArvore(Arvore* arv, FILE* saida){
    fprintf(saida, "<");
    if(!ArvoreVazia(arv)){
        fprintf(saida, "%s", retornaMatricula(arv->aluno));
        ImprimeArvore(arv->esquerda, saida);
        ImprimeArvore(arv->direita, saida);
    }
    fprintf(saida, ">");
}


void ImprimeArvoreInformacoes(Arvore* arv){
    if(!ArvoreVazia(arv)){
        ImprimeAluno(arv->aluno);
        ImprimeArvoreInformacoes(arv->esquerda);
        ImprimeArvoreInformacoes(arv->direita);
    }
}

Arvore* CriaArvoreVazia(){
    Arvore *arv = NULL;

    return arv;
}



static int maior(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}


int ArvoreAltura(Arvore *arv){
    if(ArvoreVazia(arv)){
        return -1;
    }else{
        return 1 + maior(ArvoreAltura(arv->esquerda), ArvoreAltura(arv->direita));
    }
}

int Ocorrencias(Arvore* arv, char* nome){
    int contador;
    if(ArvoreVazia(arv)){
        return 0;
    }else{
        if(!strcmp(nome, retornaNome(arv->aluno))){
            return (1 + Ocorrencias(arv->esquerda, nome) + Ocorrencias(arv->direita, nome));
        }else{
            return (Ocorrencias(arv->esquerda, nome) + Ocorrencias(arv->direita, nome));
        }
    }
}

int Folhas(Arvore * arv){
    if(ArvoreVazia(arv->esquerda) && ArvoreVazia(arv->direita)){
        return 1;
    }else if(!ArvoreVazia(arv->esquerda) && ArvoreVazia(arv->direita)){
        return Folhas(arv->esquerda);
    }else if(ArvoreVazia(arv->esquerda) && !ArvoreVazia(arv->direita)){
        return Folhas(arv->direita);
    }

    return Folhas(arv->esquerda) + Folhas(arv->direita);
}