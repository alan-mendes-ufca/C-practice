/*
Faça um programa receba uma matriz de tamanho N x M e
calcule a matriz transposta.
- matriz transposta: linha vira coluna e coluna vira linha.
*/
#include <stdio.h>
#include <cs50.h>

void init_matrix(int row, int col, int (*m)[col]);
void transposed(int row, int col, int (*t_m)[row], int (*m)[col]);
void print_matrix(int row, int col, int (*m)[col]);

int main(void)
{
    // input
    int row = get_int("Enter row length: ");
    int col = get_int("Enter col length: ");
    int matrix[row][col];
    init_matrix(row, col, matrix);

    // Process: init transposed matrix
    int transposed_matrix[col][row];
    transposed(row, col, transposed_matrix, matrix);

    // Output
    printf("Original matrix: \n");
    print_matrix(row, col, matrix);
    printf("Transposed matrix: \n");
    print_matrix(col, row, transposed_matrix);
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

void transposed(int row, int col, int (*t_m)[row], int (*m)[col])
{
    int t_row = col;
    int t_col = row;

    for (int i = 0; i < t_row; i++)
    {
        for (int j = 0; j < t_col; j++)
        {
            t_m[i][j] = m[j][i];
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