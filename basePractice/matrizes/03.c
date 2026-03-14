/*
Faça um programa receba uma matriz de tamanho N x N e calcule
a média de todos elementos da matriz.
*/

#include <stdio.h>
#include <cs50.h> // importando a cs50lib para agilizar o input de variáveis. -lcs50 ao final do comando gcc para incluir a lib na compilação.
#include <math.h>

void init_matrix(int col_row, int (*m)[col_row]);
float avg_m(int col_row, int (*m)[col_row]);

int main(void)
{
    int len = get_int("Enter matrix length: ");
    int matrix[len][len];

    init_matrix(len, matrix);

    printf("The avg of matrix elements is: %.2f.\n", avg_m(len, matrix));
    return 0;
}

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

float avg_m(int col_row, int (*m)[col_row])
{
    int sum = 0;

    for (int i = 0; i < col_row; i++)
    {
        for (int j = 0; j < col_row; j++)
        {
            sum += m[i][j];
        }
    }
    return sum / pow(col_row, 2);
}
