/*
Faça um programa que receba dois vetores com N números, no qual
cada vetor tem seus valores em ordem crescente (não precisa validar)
e depois gere um terceiro vetor ordenado com os números dos dois
vetores. Exemplo: vet1 = [1, 2, 3] e vet2 = [2, 4, 5] resultaria em [1, 2, 2,
3, 4, 5].
*/

#include <stdio.h>

void init_array(int arr1[], int arr2[], int len, int *arr_result);
void sort_array(int *arr, int len);
int get_menor(int idx_menor, int arr[], int len);
void swap(int *idx_do_maior, int *idx_do_menor);
void print_array(int arr[], int len);

int main(void)
{
    // Inicializando variáveis básicas
    int n = 3;
    int a1[] = {1, 2, 3};
    int a2[] = {2, 4, 5};
    int len = 2 * n;
    int a3[len];
    /*
    Um array é um ponteiro! Sim, exatamente. Ele aponta para o primeiro elemento da lista, ou um elemento específico, se estizer indexado.
        - Equivalência fundamental: `arr[i]  ≡  *(arr + i)
            - arr é um ponteiro para o primeiro elemento;
            - i avança posições na memória;
            - *(...) desrreferência esse endereço e retorna seu valor.
    */
    init_array(a1, a2, len, a3); // Passando apenas o a3, sem & (operador `endereço de`) pois estaria retornando um ponteiro para ponteiro.

    sort_array(a3, len);

    print_array(a3, len);

    return 0;
}

/*
Um array criado dentro de uma função resulta em um ponteiro criado na stack, QUE SERÁ DESTRUÍDO APÓS A FUNÇÃO TERMINAR!
- Soluções:
    - Alocar memória, criando um ponteiro - provavelmente teria que tratar o arr com ponteiro nas outras funções.
    - [ESCOLHIDA]: Transformar a função em um `void` que recebe o ponteiro do array e o altera lá dentro.
*/
void init_array(int arr1[], int arr2[], int len, int *arr_result)
{

    for (int h = 0; h < len; h++)
    {
        if (h <= ((len / 2) - 1))
        {

            arr_result[h] = arr1[h];
        }
        else
        {
            arr_result[h] = arr2[h - 3];
        }
    }
}

void sort_array(int *arr, int len)
{
    // Selection Sort
    int idx_menor = 0;
    for (int i = 0; i < len; i++)
    {
        idx_menor = get_menor(i, arr, len);

        // swap
        swap(&arr[i], &arr[idx_menor]);
    }
}

int get_menor(int idx_menor, int arr[], int len)
{
    for (int j = idx_menor; j < len; j++)
    {

        if (arr[j] < arr[idx_menor])
        {
            idx_menor = j;
        }
    }
    return idx_menor;
}

void swap(int *idx_do_maior, int *idx_do_menor)
{
    int buffer = *idx_do_maior;
    // `*` operador de desreferência, ele não só retorna o valor que está dentro do endereço na memória, mas ainda permite altera-lo!
    *idx_do_maior = *idx_do_menor;
    *idx_do_menor = buffer;
}

void print_array(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
        {
            printf("[");
            printf("%d, ", arr[i]);
        }
        else if (i == len - 1)
        {

            printf("%d", arr[i]);
            printf("]");
        }
        else
        {
            printf("%d, ", arr[i]);
        }
    }
    printf("\n");
}
