/*
Crie uma função somarVetor que receba um ponteiro para o
primeiro elemento de um vetor de inteiros e o tamanho do vetor.
Utilizando apenas aritmética de ponteiros (sem usar o operador []),
a função deve calcular e retornar a soma de todos os elementos
do vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int *init_vector(int len);
int sum_vector(int *arr, int len);

int main(void)
{
    int len = get_int("Insira o tamanho do array: ");
    int *vector = init_vector(len);

    printf("A soma dos elementos do array é: %d.\n", sum_vector(vector, len));
    return 0;
}

int *init_vector(int len)
{
    int *arr = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
    {
        *(arr + i) = get_int("Vetor[%d]: ", i);
    }

    return arr;
}

int sum_vector(int *arr, int len)
{
    int sum = 0;

    for (int i = 0; i < len; i++)
    {
        sum += *(arr + i);
    }
    return sum;
}
