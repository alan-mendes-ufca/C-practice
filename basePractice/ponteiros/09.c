/*
9) Escreva um programa que faça o seguinte:
    a) Crie matriz A e aloque dinamicamente ela com dimensões N x M.
    b) Solicite ao usuário que preencha todos os N x M elementos da
    matriz A
    c) Aloque dinamicamente a matriz transposta B
    d) Calcule a transposta da matriz $A$ e armazene o resultado na
    matriz B
    e) Imprima as duas matrizes (A e B) no console em formato de
    matriz.
    f) Libere toda a memória alocada dinamicamente
*/
#include <stdio.h>
#include <stdlib.h>

int **allocate_matrix(int row, int col);
void init_matrix(int row, int col, int **m);
void transpose_matrix(int row, int col, int **t_m, int **m);
void print_matrix(int row, int col, int **m);
void free_matrix(int **m, int row);

int main(void)
{
    int row, col;

    // Input das dimensões
    printf("Enter row length: ");
    scanf("%d", &row);
    printf("Enter col length: ");
    scanf("%d", &col);

    // a) Aloca dinamicamente matriz A (N x M)
    int **matrix = allocate_matrix(row, col);
    if (matrix == NULL)
    {
        printf("Erro ao alocar matriz A!\n");
        return 1;
    }

    // b) Preenche a matriz A
    init_matrix(row, col, matrix);

    // c) Aloca dinamicamente matriz transposta B (M x N)
    int **transposed_matrix = allocate_matrix(col, row);
    if (transposed_matrix == NULL)
    {
        printf("Erro ao alocar matriz B!\n");
        free_matrix(matrix, row);
        return 1;
    }

    // d) Calcula a transposta
    transpose_matrix(row, col, transposed_matrix, matrix);

    // e) Imprime as duas matrizes
    printf("\nOriginal matrix A (%dx%d):\n", row, col);
    print_matrix(row, col, matrix);

    printf("\nTransposed matrix B (%dx%d):\n", col, row);
    print_matrix(col, row, transposed_matrix);

    // f) Libera toda a memória
    free_matrix(matrix, row);
    free_matrix(transposed_matrix, col);

    return 0;
}

// Aloca matriz dinamicamente
int **allocate_matrix(int row, int col)
{
    int **m = (int **)malloc(row * sizeof(int *));
    if (m == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < row; i++)
    {
        m[i] = (int *)malloc(col * sizeof(int));
        if (m[i] == NULL)
        {
            // Libera o que já foi alocado
            for (int j = 0; j < i; j++)
            {
                free(m[j]);
            }
            free(m);
            return NULL;
        }
    }

    return m;
}

// Preenche a matriz
void init_matrix(int row, int col, int **m)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter matrix[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

// Calcula a transposta
void transpose_matrix(int row, int col, int **t_m, int **m)
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            t_m[i][j] = m[j][i];
        }
    }
}

// Imprime a matriz
void print_matrix(int row, int col, int **m)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
}

// Libera memória da matriz
void free_matrix(int **m, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(m[i]);
    }
    free(m);
}