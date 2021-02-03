#include <stdio.h>
#include <stdlib.h>

int main(){
    srand('a'); //seed para os numeros randomicos
    int n1 = rand(), n2 = rand(), n3 = rand(), n4 = rand(); //os numeros inteiros sao randomizados
    int *p1, *p2, *p3, *p4;

    p1 = &n1; //os ponteiros recebem o endereco de cada variavel inteira
    p2 = &n2;
    p3 = &n3;
    p4 = &n4;


    printf("------------ VALORES ANTES DA MUDANCA NO PONTEIRO ------------\n");
    printf("Valor de n1: %d\n", n1);
    printf("Valor de n2: %d\n", n2);
    printf("Valor de n3: %d\n", n3);
    printf("Valor de n4: %d\n\n", n4);

    *p1 = 1; //Altera o valor das variaveis inteiras, ja que elas estao apontadas para o endereco das variaveis
    *p2 = 2;
    *p3 = 3;
    *p4 = 4;

    printf("------------ VALORES DEPOIS DA MUDANCA NO PONTEIRO ------------\n");
    printf("Valor de n1: %d\n", n1);
    printf("Valor de n2: %d\n", n2);
    printf("Valor de n3: %d\n", n3);
    printf("Valor de n4: %d\n", n4);

    return 0;
}