/*
Dado um vetor de inteiros ordenado, escreva um programa que remova
os elementos duplicados. A modificação deve ser feita no próprio vetor
(”in-place”). Ao final, o programa deve imprimir o vetor modificado e o
seu novo tamanho efetivo (o número de elementos únicos).
*/

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int remove_duplicates(int *arr, int len);
int *init_arr(int len);
void print_arr(int *arr, int len);
int main(void)
{
    int len = get_int("Tamanho do array: ");
    int *vector = init_arr(len);
    int new_len = remove_duplicates(vector, len);

    print_arr(vector, new_len);

    free(vector);
    return 0;
}

int *init_arr(int len)
{
    int *arr = malloc(len * sizeof(int));

    for (int i = 0; i < len; i++)
    {
        arr[i] = get_int("vetor[%d]: ", i);
    }
    return arr;
}

int remove_duplicates(int *arr, int len)
{
    int len_buffer = len;
    for (int i = 0; i < len_buffer; i++)
    {
        for (int j = i + 1; j < len_buffer; j++)
        {
            if (arr[i] == arr[j])
            {
                // Remover elemento do array trazendo os elementos posteriores para frente.
                for (int k = j; k + 1 < len_buffer; k++)
                {
                    arr[k] = arr[k + 1];
                }
                j--;
                len_buffer--; // "Remove" o elemento do final e evita index out of the range.
            }
        }
    }
    return len_buffer;
}

void print_arr(int *arr, int len)
{
    printf("\nDeduplicate array: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\nNovo tamanho = %d\n", len);
    printf("\n");
}