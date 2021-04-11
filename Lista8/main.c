/*
    main.c
    Exercicio 8 - Estrutura de Dados UFES 2020/2 - Patricia Dockhorn Costa
    Aluno: Joao Gabriel de Barros Rocha
    Matricula: 2019107717
    Data: 10/04/2021
    github: JoaoGBarros
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"


int main(){
    FilaLista *f1; // Lista de pokemon vivos.
    FilaVetor *f2; // Vetor de pokemon extintos.

    f1 = IniciaFilaLista();
    InsereFilaLista(f1, "Omanyte", 138, "Rock", "Water");
    InsereFilaLista(f1, "Omastar", 139, "Rock", "Water");
    InsereFilaLista(f1, "Kabuto", 140, "Rock", "Water");
    InsereFilaLista(f1, "Kabutops", 141, "Rock", "Water");
    InsereFilaLista(f1, "Aerodactyl", 142, "Rock", "Flying");
    InsereFilaLista(f1, "Lillep", 345, "Rock", "Grass");
    InsereFilaLista(f1, "Cradily", 346, "Rock", "Grass");
    InsereFilaLista(f1, "Anorith", 347, "Rock", "Bug");
    InsereFilaLista(f1, "Armaldo", 348, "Rock", "Bug");
    printf(" ========= POKEMONS DA IDADE DA PEDRA =========\n");
    ImprimeFilaLista(f1);

    f2 = IniciaFilaVetor();
    //Retiro os Pokemons ja inseridos na lista e coloco eles na fila 2, dedicada apenas aos pokemon extintos.
    InsereFilaVetor(f2, RetiraFilaLista(f1)); //Omanyte
    InsereFilaVetor(f2, RetiraFilaLista(f1)); //Omastar
    InsereFilaVetor(f2, RetiraFilaLista(f1)); //Kabuto
    InsereFilaVetor(f2, RetiraFilaLista(f1)); //Kabutops
    InsereFilaVetor(f2, RetiraFilaLista(f1)); //Aerodactyl
    InsereFilaVetor(f2, RetiraFilaLista(f1)); //Lillep
    InsereFilaVetor(f2, RetiraFilaLista(f1)); //Cradily
    InsereFilaVetor(f2, RetiraFilaLista(f1)); //Anorith
    InsereFilaVetor(f2, RetiraFilaLista(f1)); //Armaldo

    //Dentro da Fila Lista vazia, eu coloco novos pokemons, esses nao foram extintos e estao presente na natureza ate hoje.
    printf(" ========= POKEMONS DA ERA MODERNA  =========\n");
    InsereFilaLista(f1, "Treecko", 252, "Grass", "None");
    InsereFilaLista(f1, "Grovyle", 253, "Grass", "None");
    InsereFilaLista(f1, "Sceptile", 254, "Grass", "None");
    InsereFilaLista(f1, "Torchic", 255, "Fire", "None");
    InsereFilaLista(f1, "Combusken", 256, "Fire", "Fighting");
    InsereFilaLista(f1, "Blaziken", 257, "Fire", "Fighting");
    InsereFilaLista(f1, "Mudkip", 258, "Water", "None");
    InsereFilaLista(f1, "Marshtomp", 259, "Water", "Ground");
    InsereFilaLista(f1, "Swampert", 260, "Water", "Ground");
    ImprimeFilaLista(f1);

    // Imprime a Fila Vetor, apenas para demonstrar que esta funcionando -> Mesmo resultado do primeiro print da ImprimeFilaLista(f1).
    printf(" ========= POKEMONS ESTUDADOS NA ERA MODERNA POR PALEONTOLOGOS =========\n");
    ImprimeFilaVetor(f2); 

    printf("APOS DIVERSOS ANOS DE ESTUDO,\nOS CIENTISTAS DO MUNDO POKEMON CONSEGUIRAM, COM SUCESSO,\nREVIVER ALGUMAS DESSAS ESPECIES DE POKEMON EXTINTOS...\n\n");
    
    //Adiciona alguns pokemons que estavam no vetor na lista, ja que foram revividos com sucesso e fazem parte da era moderna.
    InsereFilaListaPokemon(f1, RetiraFilaVetor(f2));
    InsereFilaListaPokemon(f1, RetiraFilaVetor(f2));
    InsereFilaListaPokemon(f1, RetiraFilaVetor(f2));
    InsereFilaListaPokemon(f1, RetiraFilaVetor(f2));
    InsereFilaListaPokemon(f1, RetiraFilaVetor(f2));

    ImprimeFilaLista(f1);

    DestroiFilaLista(f1);
    DestroiFilaVetor(f2);
    
    return 0;
}