/*
Faça um programa que verifique se duas matrizes podem ser
multiplicadas e, caso seja possível, multiplique as duas matrizes.
- Para validar se duas matrizes podem ser multiplicadas basta verificar se o número de colunas
 da primeira é igual ao número de linhas da segunda matriz.
    - col_a = row_b
*/
#include <stdio.h>
#include <cs50.h>

void init_matrix(int row, int col, int (*m)[col]);
void multiply(int row_a, int col_a, int col_b, int (*m_a)[col_a], int (*m_b)[col_b], int (*m_r)[col_b]);
void print_matrix(int row, int col, int (*m)[col]);

int main(void)
{
    // input
    int row_a = get_int("Enter row for matrix `a` length: ");
    int col_a = get_int("Enter col for matrix `a` length: ");

    int row_b = get_int("Enter row for matrix `b` length: ");
    int col_b = get_int("Enter col for matrix `b` length: ");

    int m_a[row_a][col_a];
    int m_b[row_b][col_b];

    // process
    if (!(col_a == row_b))
    {
        printf("As matrizes não podem ser multiplicadas.");
        return 0;
    }

    init_matrix(row_a, col_a, m_a);
    init_matrix(row_b, col_b, m_b);

    // inicializando matriz resultante
    int m_r[row_a][col_b];
    multiply(row_a, col_a, col_b, m_a, m_b, m_r);

    // output
    printf("Matrix A: ");
    print_matrix(row_a, col_a, m_a);
    printf("\nMatriz B: ");
    print_matrix(row_b, col_b, m_b);
    printf("\nMatriz produto (AxB): ");
    print_matrix(row_a, col_b, m_r);

    return 0;
}

void init_matrix(int row, int col, int (*m)[col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            m[i][j] = get_int("Enter matrix[%d][%d]: ", i, j);
        }
    }
}

void multiply(int row_a, int col_a, int col_b, int (*m_a)[col_a], int (*m_b)[col_b], int (*m_r)[col_b])
{
    /*
    A multiplicação entre matrizes consiste em seguir os passos de um algoritmo.
        - 1o. validar se o número de colunas da primeira é igual ao número de linhas da segunda.
        - 2o. calcular a matriz produto: multiplicar uma coluna da primeira com uma linha da segunda.
    */
    for (int i = 0; i < row_a; i++)
    {
        for (int j = 0; j < col_b; j++)
        {
            for (int k = 0; k < col_a; k++)
            {
                m_r[i][j] += m_a[i][k] * m_b[k][j];
            }
        }
    }
}

void print_matrix(int row, int col, int (*m)[col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("[%d]", m[i][j]);
        }
        printf("\n");
    }
}