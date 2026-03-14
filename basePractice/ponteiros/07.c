/*
7) Escreva um programa que calcule a transposta de uma matriz. As
matrizes, tanto a original quanto a transposta, devem ser criadas

utilizando alocação dinâmica de memória e representadas por variáveis
do tipo ”ponteiro para ponteiro de inteiro”(int **). O programa deve
seguir estes passos:
a) Solicitar ao usuário as dimensões da matriz original (número de
linhas L e colunas C).
b) Permitir que o usuário preencha os valores da matriz original.
c) Imprimir a matriz original e a matriz transposta para verificação

- matriz transposta = linhas -> colunas e colunas -> linhas;
*/

/*
Dado um vetor de inteiros ordenado, escreva um programa que remova
os elementos duplicados. A modificação deve ser feita no próprio vetor
(”in-place”). Ao final, o programa deve imprimir o vetor modificado e o
seu novo tamanho efetivo (o número de elementos únicos).
*/

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int **init_matrix(int row, int col);
int **transposed_matrix(int **m, int row, int col);
void print_matrix(int **m, int row, int col);

int main(void)
{
    // input
    int row = get_int("Matrix row: ");
    int col = get_int("Matrix col: ");
    int **m = init_matrix(row, col);

    // process
    int **m_t = transposed_matrix(m, row, col);

    // output
    printf("Original matrix: \n");
    print_matrix(m, row, col);

    printf("\nTransposed matrix: \n");
    print_matrix(m_t, col, row);

    free(m);
    free(m_t);
}

int **init_matrix(int row, int col)
{
    int **m = malloc(row * sizeof(int *));

    for (int i = 0; i < row; i++)
    {
        m[i] = malloc(col * sizeof(int));
    }

    for (int j = 0; j < row; j++)
    {
        for (int k = 0; k < col; k++)
        {
            m[j][k] = get_int("m[%d][%d] = ", j, k);
        }
    }

    return m;
}

int **transposed_matrix(int **m, int row, int col)
{
    int **m_transp = malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        m_transp[i] = malloc(col * sizeof(int));
    }

    //
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            m_transp[i][j] = m[j][i];
        }
    }
    return m_transp;
}

void print_matrix(int **m, int row, int col)
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