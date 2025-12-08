/*
Faça um programa receba uma matriz de tamanho N x M e
rotacione essa matriz em 180 graus.
- Dismestificando o problema:
  - Para cada posição [i][j], colocar o valor na posição [N-1-i][M-1-j] da matriz resultado
*/

#include <stdio.h>
#include <cs50.h>

void init_matrix(int row, int col, int (*m)[col]);
void to_180(int row, int col, int (*m)[col], int (*m_r)[col]);
void print_matrix(int row, int col, int (*m)[col]);

int main(void)
{
    // input
    int row = get_int("Enter row length: ");
    int col = get_int("Enter col length: ");
    int m[row][col]; // inicializando em tempo de execução...
    init_matrix(row, col, m);
    int m_r[row][col];

    // process
    to_180(row, col, m, m_r);

    // ouput
    printf("Primeira matriz: ");
    print_matrix(row, col, m);
    printf("\nMatriz após rotacionada: ");
    print_matrix(row, col, m_r);

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

void to_180(int row, int col, int (*m)[col], int (*m_r)[col])
{
    // Para cada posição [i][j], colocar o valor na posição `[N-1-i][M-1-j]` da matriz resultado

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            m_r[row - 1 - i][col - 1 - j] = m[i][j];
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