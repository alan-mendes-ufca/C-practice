/*
Uma matriz é dita estritamente diagonal dominante se cada
elemento da diagonal principal é maior do que o somatório dos
demais termos da linha. Faça um programa receba uma matriz de
tamanho N x N, imprima se a matriz é ou não estritamente
diagonal dominante.
*/

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdbool.h>

void init_matrix(int row, int col, int (*m)[col]);
bool is_diagonally_domi(int row, int col, int (*m)[col]);

int main(void)
{
    // input
    int row = get_int("Enter row for matrix `a` length: ");
    int col = get_int("Enter col for matrix `a` length: ");
    int m[row][col]; // inicializando em tempo de execução...

    init_matrix(row, col, m);

    if (is_diagonally_domi(row, col, m))
    {
        printf("A matriz é diagonal dominante!");
    }
    else
    {
        printf("A matriz não é diagonal dominante.");
    }

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

bool is_diagonally_domi(int row, int col, int (*m)[col])
{
    /*
    O elemento diagonal principal em cada linha é maior que o somatório dos outros que não são
        - todos os números devem estar em valor absoluto.
    */

    for (int i = 0; i < row; i++)
    {
        int d_element = abs(m[i][i]);
        int sum = 0; // reseta a cada iteração.

        for (int j = 0; j < col; j++)
        {
            if (i != j)
            {
                // somar os que não são.
                sum += abs(m[i][j]);
            }
        }
        // validar disparidade.
        if (d_element < sum)
        {
            return false;
        }
    }

    return true;
}
