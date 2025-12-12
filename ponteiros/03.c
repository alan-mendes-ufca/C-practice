/*
3) Escreva um programa que calcule o produto escalar de dois vetores
arrays de números de ponto flutuante. O programa deve solicitar que o
usuário digite os elementos do primeiro vetor e em seguida os
elementos do segundo vetor. Por fim, deve calcular e exibir o produto
escalar entre os dois vetores, utilizando operações com ponteiros.
Considere os vetores de tamanho fixo, determinados dentro do código.
*/

#define LEN 3
#include <stdio.h>
#include <stdlib.h>

float scalar_product(float *arr1, float *arr2);
void init_arr(float *arr);

int main(void)
{
    // var
    float *arr1 = malloc(sizeof(float) * LEN);
    float *arr2 = malloc(sizeof(float) * LEN);

    // Verificação de alocação de memória
    if (arr1 == NULL || arr2 == NULL)
    {
        printf("Erro ao alocar memória!\n");
        free(arr1);
        free(arr2);
        return 1;
    }

    // input
    printf("Inicializando o primeiro vetor \n");
    init_arr(arr1);
    printf("Inicializando o segundo vetor \n");
    init_arr(arr2);

    // process
    float scalar = scalar_product(arr1, arr2);

    // output
    printf("O produto escalar entre os dois arrays é: %.2f.\n", scalar);

    free(arr1);
    free(arr2);
    return 0;
}

void init_arr(float *arr)
{
    for (int i = 0; i < LEN; i++)
    {
        printf("Input arr[%d]: ", i);
        scanf("%f", (arr + i));
    }
    printf("\n");
}

float scalar_product(float *arr1, float *arr2)
{
    float scalar = 0.0;
    int count = 0;

    while (count < LEN)
    {
        scalar += *(arr1 + count) * *(arr2 + count);
        count++;
    }
    return scalar;
}
