/*
Dizemos que uma `matriz quadrada` de números inteiros é um
quadrado mágico se a soma dos elementos de cada linha, a soma
dos elementos de cada coluna e a soma dos elementos das
diagonais principal e secundária são todas iguais. Faça um
programa receba uma matriz de tamanho N x N, informe se a
matriz é mágica ou não.
*/

#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

void init_matrix(int n, int (*m)[n]);
bool is_magic(int n, int (*m)[n]);

int main(void)
{
    // input
    int len = get_int("Enter row-col length: ");
    int m[len][len]; // inicializando em tempo de execução...

    init_matrix(len, m);

    if (is_magic(len, m))
    {
        printf("A matriz é mágica!\n");
    }
    else
    {
        printf("A matriz não é mágica.\n");
    }

    return 0;
}

void init_matrix(int n, int (*m)[n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m[i][j] = get_int("Enter matrix[%d][%d]: ", i, j);
        }
    }
}

bool is_magic(int n, int (*m)[n])
{
    int sum_diag_main = 0, sum_diag_secondary = 0;
    // int sum_row[row] = {0}; - como esses arrays são inicializados em tempo de execução, o comportamento pode ser identifido, vamo inicializar do jeito tradicional.
    // int sum_col[col] = {0};

    int sum_row[n];
    int sum_col[n];

    // Preenchendo os vetores com 0's.
    for (int h = 0; h < n; h++)
    {
        sum_row[h] = 0;
        sum_col[h] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        sum_diag_main += m[i][i];
        for (int j = 0; j < n; j++)
        {
            // somando os valores de cada linha
            sum_row[i] += m[i][j];
            // somando os valores de cada coluna
            sum_col[j] += m[i][j];

            if (i + j == n - 1)
            {
                sum_diag_secondary += m[i][j];
            }
        }
    }

    // Validando diagonais.
    int magic_number = sum_diag_main;
    if (magic_number != sum_diag_secondary)
    {
        return false;
    }

    // Verificando linhas e colunas.
    for (int k = 0; k < n; k++)
    {
        if ((sum_row[k] != magic_number) || (sum_col[k] != magic_number))
        {
            return false;
        }
    }

    return true;
}
