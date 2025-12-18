/*
8) Escreva um programa que faça o seguinte:
    a) Alocar dinamicamente um vetor de números ponto flutuante com
    capacidade inicial para 3 amostras.

    b) Faça um loop que solicita ao usuário que digite um valor de erro
    (float). O loop deve parar quando o usuário digitar 0.0.

    c) Se o vetor ficar cheio durante a coleta de dados, aumente a
    capacidade do vetor em mais 3 amostras de cada vez
    (crescimento incremental).
*/
#define INITIAL_LEN 3
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdbool.h>
#include <math.h>

float rms_calc(float *arr, int len)
{
    float sum = 0;

    // to square
    for (int i = 0; i < len; i++)
    {
        arr[i] = pow(arr[i], 2);
        sum += arr[i];
    }

    float avg = sum / len;

    return sqrt(avg);
}

int main(void)
{
    float *arr = malloc(INITIAL_LEN * sizeof(float));
    if (arr == NULL)
    {
        printf("memory allocation error");
        return 1;
    }
    int new_len = INITIAL_LEN;
    int count = 0;

    while (true)
    {
        float input = get_float("Input [%d]: ", count);

        // end condition
        if (input == 0.0)
        {
            printf("\nBreaking loop...\n");
            break;
        }

        // realloc memory
        if (count != 0 && count % 3 == 0)
        {
            new_len += 3;
            float *temp = realloc(arr, sizeof(float) * new_len);

            // validating memory allocation
            if (temp != NULL)
            {
                arr = temp;
            }
            else
            {
                printf("memory allocation error");
                return 1;
            }
        }

        arr[count] = input;

        count++;
    }

    printf("\nRoot Mean Square = %.2f\n", rms_calc(arr, count));

    free(arr);
    return 0;
}