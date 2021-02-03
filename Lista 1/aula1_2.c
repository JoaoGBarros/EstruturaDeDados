#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi (float)3.14


void calc_esfera(float r, float *area, float *volume);
int raizes(float a, float b, float c, float* x1, float* x2);
int pares (int n, int* vet);
void inverte (int n, int* vet);
double avalia (double* poli, int grau, double x);




void calc_esfera(float r, float *area, float *volume){
    *area = 4 * pi * powf(r, 2);
    *volume = (4 * pi * powf(r, 3))/3;
}

/*int main(){
   float r, *area, *volume;
   area = (float*)malloc(sizeof(float));
   volume = (float*)malloc(sizeof(float));
   printf("Indique o valor de r: ");
   scanf("%f", &r);
   calc_esfera(r, area, volume);
   printf("Area da esfera de raior %.2f: %.2f\n", r, *area);
   printf("Volume da esfera de raior %.2f: %.2f\n", r, *volume);
   free(area);
   free(volume);
   return 0;
} //Exercicio 2.1*/


int raizes(float a, float b, float c, float* x1, float* x2){
    float delta;
    delta = pow(b, 2) - 4 * a * c;



    if(delta == 0){
        *x1 = ((-1*b)+sqrtf(delta))/(2 * a);
        return 1;
    }else if(delta > 0){
        *x1 = ((-1*b)+sqrtf(delta))/(2 * a);
        *x2 = ((-1*b)-sqrtf(delta))/(2 * a);
        return 2;
    }else{
        return 3;
    }
}


/*int main(){
    int num_raizes;
    float a, b, c, *x1, *x2;
    x1 = (float*)malloc(sizeof(float));
    x2 = (float*)malloc(sizeof(float));
    printf("Informe os valores de a, b, c da funcao de segundo grau ax^2 + bx + c: ");
    scanf("%f %f %f", &a, &b, &c);
    num_raizes = raizes(a, b, c, x1, x2);

    if(num_raizes == 1){
        printf("Raiz da funcao: %.2f", *x1);
    }else if(num_raizes == 2){
        printf("Raiz x1 da funcao: %.2f\n", *x1);
        printf("Raiz x2 da funcao: %.2f\n", *x2);
    }else{
        printf("Nao existem raizes reais");
    }
    free(x1);
    free(x2);
    return 0;

} //Exercicio 2.2*/

int pares (int n, int* vet){
    int qtd = 0;
    for(int i = 0; i < n; i++){
        if(vet[i] % 2 == 0){
            qtd++;
        }
    }
    return qtd;
}

/*int main(){
    int *vet, n;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);
    vet = (int*)malloc(n * sizeof(int));
    printf("Informe os numeros no vetor\n");

    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    printf("O vetor possuio %d numero(s) pare(s)", pares(n, vet));
    free(vet);
    return 0;

} //Exercicio 2.3*/

void inverte (int n, int* vet){
    int aux;

    for(int i = 0; i < n/2; i++){
        aux = vet[i];
        vet[i] = vet[n-(i+1)];
        vet[n-(i+1)] = aux;

    }
}

/*int main(){
    int *vet, n;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);
    vet = (int*)malloc(n * sizeof(int));
    printf("Informe os numeros no vetor\n");

    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    inverte (n, vet);

    for(int i = 0; i < n; i++){
        printf("%d\n", vet[i]);
    }

    free(vet);
    return 0;
} //Exercicio 2.4*/

double avalia (double* poli, int grau, double x){
    double result[grau], resultado = 0;
    int j = 0;

    for(int i = grau; i >= 0; i--, j++){
        result[j] = poli[j] * pow(x, i);
    }

    for(int i = 0; i < grau+1; i++){
        resultado = resultado + result[i];
    }

    return resultado;
}

/*int main(){
    double *poli, x, resultado;
    int grau;

    printf("Informe o grau do polinomio: ");
    scanf("%d", &grau);

    poli = (double*)malloc((grau + 1) * sizeof(double));

    for(int i = 0; i < grau+1; i++){
        scanf("%lf", &poli[i]);
    }

    printf("Informe o valor de x: ");
    scanf("%lf", &x);

    resultado = avalia(poli, grau, x);

    printf("Resultado = %.2lf", resultado);


    free(poli);

    return 0;
}//Exercicio 2.5 */