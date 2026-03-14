/*
Escreva um programa que receba dois vetores de inteiros, vetorA e
vetorB, ambos já ordenados em ordem crescente. O programa deve
criar um terceiro vetor, vetorC, que contenha todos os elementos de A e
B, também em ordem crescente. Utilize alocação dinâmica para criar o
vetorC
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cs50.h>

int *init_array(int len);
int *merge_array(int len, int *arr1, int *arr2);
void print_array(int len, int *arr);

int main(void)
{
    int size = get_int("Digite o tamanho dos vetores A e B: ");
    int *vetorA = init_array(size);
    int *vetorB = init_array(size);
    int *vetorC = merge_array(2 * size, vetorA, vetorB);

    print_array(2 * size, vetorC);
    free(vetorA);
    free(vetorB);
    free(vetorC);
    return 0;
}

int *init_array(int len)
{
    int *arr = malloc(len * sizeof(int));

    // Validação da alocação
    if (arr == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    for (int i = 0; i < len; i++)
    {
        printf("Digite o valor para a posição %d: ", i);
        scanf("%d", &arr[i]);
    }

    return arr;
}

int *merge_array(int len, int *arr1, int *arr2)
{

    int *merged_arr = malloc(len * sizeof(int));

    int i = 0;
    int j = 0;
    int k = 0;

    while (k != len)
    {
        if (arr1[i] < arr2[j])
        {
            merged_arr[k] = arr1[i];
            i++;
            k++;
        }
        else if (arr2[j] < arr1[i])
        {
            merged_arr[k] = arr2[j];
            j++;
            k++;
        }
        else
        {
            // Insere o primeiro elemento da igualdade
            merged_arr[k] = arr1[i];
            i++;
            k++;

            // Insere o segundo elemento da igualdade
            merged_arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    return merged_arr;
}

void print_array(int len, int *arr)
{
    printf("\nMerged array: ");
    for (size_t i = 0; i < len; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}