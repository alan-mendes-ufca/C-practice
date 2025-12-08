/*
Faça um programa receba uma matriz de tamanho N x N e realize
uma multiplicação dessa matriz por um escalar dado pelo usuário.
*/

#include <stdio.h>
#include <cs50.h> // importando a cs50lib para agilizar o input de variáveis. -lcs50 ao final do comando gcc para incluir a lib na compilação.

void init_matrix(int col_row, int (*m)[col_row]);
void scalar_multiplication(int col_row, int (*m)[col_row], int x);
void print_matrix(int col_row, int (*m)[col_row]);

int main(void)
{
    int len = get_int("Enter matrix length: ");
    int matrix[len][len];

    init_matrix(len, matrix);

    int x = get_int("Enter a times: ");
    scalar_multiplication(len, matrix, x);

    print_matrix(len, matrix);
    return 0;
}

/*
void init_matrix(int **m, int col_row) //  espera uma matriz dinâmica,

- Anteriormente, ao declarar um `int arr[n]` ele poderia ser recebido em uma função como int * arr,
 pois o int arr[n] decai para um int arr*, apontando para o início da sequência (`&arr[0]`). Entretanto,
 por baixo dos panos, una matriz se comporta dessa forma.

 - Para uma m[n][n], sua equivalência direta é `(*m)[n]` (ponteiro para array de n números, perde-se uma dimenção) um ponteiro que aponta para um array de n elementos.
    Fazendo a aritmética de ponteiros é possível chegar nas próximas linhas.
 - m[n][n] x **m
    - m[n][n] => (*m)[n] => [0], [1], ..., [n-1] (bloco contínuo na memória).
    - **m => [ponteiro] -> [n]
              ...

*/
void init_matrix(int col_row, int (*m)[col_row])
{
    for (int i = 0; i < col_row; i++)
    {
        for (int j = 0; j < col_row; j++)
        {
            m[i][j] = get_int("Enter matrix[%d][%d]: ", i, j);
        }
    }
}

void scalar_multiplication(int col_row, int (*m)[col_row], int x)
{
    for (int i = 0; i < col_row; i++)
    {
        for (int j = 0; j < col_row; j++)
        {
            m[i][j] = m[i][j] * x;
        }
    }
}

void print_matrix(int col_row, int (*m)[col_row])
{
    for (int i = 0; i < col_row; i++)
    {
        for (int j = 0; j < col_row; j++)
        {
            printf("[%d]", m[i][j]);
        }
        printf("\n");
    }
}