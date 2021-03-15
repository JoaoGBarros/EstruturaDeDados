/*
    main.c
    Exercicio 5 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 13/03/2021
    github: JoaoGBarros
*/


#include <stdio.h>
#include "ListaAvatar.h"




int main(){
    /*
     * Codigo possui spoilers de Avatar A Lenda de Korra e Avatar A Lenda de Aang
     * Siga com cuidado caso nao tenha visto. Informacoes sobre Avatar
     *
     *  Sobre o Avatar:
     *
     *  Após a morte, o Espírito Avatar faz com que o Avatar reencarne na próxima nação, ditada pela ordem cíclica:
     *  fogo, ar, água e terra. Espelhando a ordem em que o primeiro Avatar, Wan, aprendeu os elementos, esta é também
     *  a ordem tradicional em que qualquer encarnação é dominar os elementos, começando com a arte de Dobra da nação
     *  de nascimento do Avatar.
     *
     *  Sobre a funcao destroiOCiclo:
     *
     *  O Avatar também é capaz de lembrar memórias de vidas passadas. Esta habilidade, entretanto, pode ser ferida ou
     *  mesmo completamente cortada. Avatar Aang involuntariamente enfraqueceu sua conexão com todas as suas vidas
     *  passadas que vieram antes de Avatar Roku quando ele interrompeu seu relacionamento com o Avatar da Nação do Fogo,
     *  embora ele conseguiu restaurar a conexão. Quando Raava foi arrancada de Avatar Korra por Vaatu
     *  e subsequentemente destruída, o elo de Korra a suas vidas passadas via Raava foi completamente cortado apesar
     *  da ressurreição do espírito da luz.
     *
     */
    Avatar *korra, *aang, *roku, *kyoshi, *kuruk, *yangchen, *szeto, *salai, *wan;
    Ciclo *cicloAvatar;

    korra = criaAvatar("Korra", "Tribo Da Agua Do Sul");
    aang = criaAvatar("Aang", "Templo do Ar do Sul");
    roku = criaAvatar("Roku", "Nacao do Fogo");
    kyoshi = criaAvatar("Kyoshi", "Reino da Terra");
    kuruk = criaAvatar("Kuruk", "Tribo da Agua do Norte");
    yangchen = criaAvatar("Yangchen", "Templo do Ar do Oeste");
    szeto = criaAvatar("Szeto", "Nacao do Fogo");
    salai = criaAvatar("Salai", "Desconhecido");
    wan = criaAvatar("Wan", "Tartaruga Leao do Fogo");

    cicloAvatar = iniciaCiclo();

    cicloAvatar = insereAvatar(cicloAvatar, korra);
    cicloAvatar = insereAvatar(cicloAvatar, aang);
    cicloAvatar = insereAvatar(cicloAvatar, roku);
    cicloAvatar = insereAvatar(cicloAvatar, kyoshi);
    cicloAvatar = insereAvatar(cicloAvatar, kuruk);
    cicloAvatar = insereAvatar(cicloAvatar, yangchen);
    cicloAvatar = insereAvatar(cicloAvatar, szeto);
    cicloAvatar = insereAvatar(cicloAvatar, salai);
    cicloAvatar = insereAvatar(cicloAvatar, wan);

    pergaminhoDoCiclo(cicloAvatar);

    cicloAvatar = destroiCiclo(cicloAvatar, "Korra"); //Apaga da Lista todos os antecessores do Avatar em questao.

    printf("\n======APOS ACONTECIMENTOS DA 2 TEMPORADA DE A LENDA DE KORRA======\n\n");

    pergaminhoDoCiclo(cicloAvatar);


    apagaCiclo(cicloAvatar);

    apagaAvatar(korra);
    apagaAvatar(aang);
    apagaAvatar(roku);
    apagaAvatar(kyoshi);
    apagaAvatar(kuruk);
    apagaAvatar(yangchen);
    apagaAvatar(szeto);
    apagaAvatar(salai);
    apagaAvatar(wan);



    return 0;
}
