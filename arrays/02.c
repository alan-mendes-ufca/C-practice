/*
2) Faça um programa que receba um vetor com N números. Depois,
realize as seguintes operações na sequência:
    a) Imprima o vetor preenchido
    b) Digite um número x, se este número existir NO VETOR diga “o número
    <número> existe”
    c) Digite um número y, se este número não existir no vetor,
    substitua x por y
    d) Imprima novamente o vetor
*/
#include <stdio.h>

void get_array(int array[], int n);
void print_array(int array[], int n);
int validating_existence(int number, int array[], int n);

int main(void)
{
    int n = 0;
    printf("Input of array n: ");
    scanf("%d", &n);

    // Preenchendo o array
    int array[n];
    get_array(array, n);
    print_array(array, n);

    // Inicializando `x`
    int x = 0;
    printf("Input of `x`: ");
    scanf("%d", &x);

    // Validando se `x` existe no `array`
    if (validating_existence(x, array, n))
    {
        printf("O número %d existe no array.\n", x);
    }
    else
    {
        printf("O número %d NÃO EXISTE no array.\n", x);
    }

    // Inicializando `y`
    int y = 0;
    printf("Input of `y`: ");
    scanf("%d", &y);

    if (validating_existence(y, array, n))
    {
        printf("O número %d existe no array.\n", y);
    }
    else
    {
        printf("O número %d NÃO EXISTE no array, trocando x por y...\n", y);

        printf("Novo array: ");
        for (int i = 0; i < n; i++)
        {
            if (array[i] == x)
            {
                array[i] = y;
            }
        }
        print_array(array, n);
    }
}

void get_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Input [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("\n");
}

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int validating_existence(int number, int array[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (array[i] == number)
        {
            return 1;
        }
    }
    return 0;
}