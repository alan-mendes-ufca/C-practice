/*
5) Faça um programa que receba dois vetores com N números. Verifique
se esse vetor tem um número palíndromo (um número que escrito na
ordem inversa é igual).
*/

#include <stdio.h>
#include <stdbool.h>

void get_array(int *arr, int len);
bool is_palindromo(int arr[], int len);

int main(void)
{
    int n;
    printf("Tamanho do array: ");
    scanf("%d", &n);

    int arr[n];
    get_array(arr, n);

    if (is_palindromo(arr, n))
    {
        printf("\nÉ palíndromo!\n");
    }
    else
    {
        printf("\nNÃO é um palíndromo.\n");
    }
    return 0;
}

void get_array(int *arr, int len)
{
    /*
    Dúvida: O que acontece quando eu trato o ponteiro como um array?
    - Bom, todo array, por baixo dos panos, é um ponteiro - ele aponta para o início da sequência de valores.

    - A indexação é deita por meio da aritmética de ponteiro, então o operador int arr_x[] pode ser convertido para
     *(arr_x + i) - arr_x = início do ponteiro (decaído para ponteirio na declaração), i é um escalar, * operador de desrreferência.

    - Por fim, se eu estiver passando um ponteiro int *ptr => ptr[0] => *(ptr + 0), resumindo, a desrreferência ocorrerá igualmente.
    */
    for (int i = 0; i < len; i++)
    {
        printf("[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

bool is_palindromo(int arr[], int len)
{

    int count = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (arr[i] != arr[count])
        {
            return false;
        }
        count++;
    }

    return true;
}