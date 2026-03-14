/*
Faça um programa que calcule o determinante de uma matriz 3x3
*/

#include <stdio.h>
#include <cs50.h> // importando a cs50lib para agilizar o input de variáveis. -lcs50 ao final do comando gcc para incluir a lib na compilação.

void init_matrix(int (*m)[3]);
float determinant_matrix(int (*m)[3]);

int main(void)
{
    int matrix[3][3];

    init_matrix(matrix);

    printf("The determinant of matrix elements is: %.2f.\n", determinant_matrix(matrix));
    return 0;
}

void init_matrix(int (*m)[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m[i][j] = get_int("Enter matrix[%d][%d]: ", i, j);
        }
    }
}

float determinant_matrix(int (*m)[3])
{
    // Diagonal principal - diagonal segundária.
    return (
               (m[0][0] * m[1][1] * m[2][2]) +
               (m[0][1] * m[1][2] * m[2][0]) +
               (m[0][2] * m[1][0] * m[2][1])) -
           ((m[0][2] * m[1][1] * m[2][0]) +
            (m[0][0] * m[1][2] * m[2][1]) +
            (m[0][1] * m[1][0] * m[2][2]));
}
