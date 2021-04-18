#include <stdlib.h>
#include <stdio.h>
#include "Arvore.h"


int main(){
    Arvore *turma1, *turma2;
    FILE* saida;

    saida = fopen("arvore.txt", "w"); //Arquivo de saida com a notacao textual da arvore

    turma1 = CriaArvore("Pedro", "1", 5, 
                CriaArvore("Joao", "2", 7,
                    CriaArvore("Gabriel", "3", 4, CriaArvoreVazia(), CriaArvoreVazia()),
                    CriaArvore("Roberto", "4", 8.6, CriaArvoreVazia(), CriaArvoreVazia())
                ),
                CriaArvore("Caio", "5", 9.8,
                    CriaArvore("Joao", "6", 6.7, CriaArvoreVazia(), CriaArvoreVazia()),
                    CriaArvore("Sther", "7", 10, CriaArvoreVazia(), CriaArvoreVazia())
                )
            );
    
    turma2 = CriaArvore("Keko", "8", 9.6,
                CriaArvore("Beta", "9", 10, CriaArvoreVazia(), CriaArvoreVazia()),
                CriaArvore("Mariguana", "10", 8.5,
                    CriaArvore("Victor", "11", 8.9,
                        CriaArvore("Igor", "12", 9, CriaArvoreVazia(), CriaArvoreVazia()),
                        CriaArvore("Liz", "13", 9.5, CriaArvoreVazia(), CriaArvoreVazia()) 
                    ),
                CriaArvoreVazia())
            );

    printf("Turma1\n");
    ImprimeArvoreInformacoes(turma1); //Printa as informacoes dos alunos da arvore turma1
    ImprimeArvore(turma1, saida); //Imprime no arquivo de saida a arvore turma1
    fprintf(saida, "\n"); //Pular linha dentro do arquivo
    printf("\n");
    printf("Turma2\n");
    ImprimeArvoreInformacoes(turma2);//Printa as informacoes dos alunos da arvore turma2
    ImprimeArvore(turma2, saida); //Imprime no arquivo de saida a arvore turma2
    fprintf(saida, "\n");
    printf("O nome %s ocorreu %d vezes na turma 1\n","Joao", Ocorrencias(turma1, "Joao"));
    printf("O nome %s ocorreu %d vezes na turma 2\n", "Keko", Ocorrencias(turma2, "Keko"));
    printf("Numero de folhas da arvore turma1: %d\n", Folhas(turma1));
    printf("Numero de folhas da arvore turma2: %d\n", Folhas(turma2));
    printf("A altura da arvore da turma 1 eh de: %d\n", ArvoreAltura(turma1));
    printf("A altura da arvore da turma 2 eh de: %d\n", ArvoreAltura(turma2));

    fclose(saida); //Fecha o arquivo
    DestroiArvore(turma1); //Desaloca as arvores
    DestroiArvore(turma2);
}