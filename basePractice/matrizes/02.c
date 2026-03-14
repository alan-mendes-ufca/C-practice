/*
Faça um programa receba uma matriz de tamanho N x N e calcule
a matriz oposta.
- Para encontrar a matriz oposta basta multiplica-lá por -1.
*/

#include <stdio.h>
#include <cs50.h> // importando a cs50lib para agilizar o input de variáveis. -lcs50 ao final do comando gcc para incluir a lib na compilação.

void init_matrix(int col_row, int (*m)[col_row]);
void opposite_matrix(int col_row, int (*m)[col_row]);
void print_matrix(int col_row, int (*m)[col_row]);

int main(void)
{
    int len = get_int("Enter matrix length: ");
    int matrix[len][len];

    init_matrix(len, matrix);

    opposite_matrix(len, matrix);

    print_matrix(len, matrix);
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

void opposite_matrix(int col_row, int (*m)[col_row])
{
    for (int i = 0; i < col_row; i++)
    {
        for (int j = 0; j < col_row; j++)
        {
            m[i][j] = m[i][j] * (-1);
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