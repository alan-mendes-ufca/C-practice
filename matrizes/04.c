/*
Faça um programa que calcule o determinante de uma matriz 2x2.
*/

#include <stdio.h>
#include <cs50.h> // importando a cs50lib para agilizar o input de variáveis. -lcs50 ao final do comando gcc para incluir a lib na compilação.

void init_matrix(int (*m)[2]);
float determinant_matrix(int (*m)[2]);

int main(void)
{
    int matrix[2][2];

    init_matrix(matrix);

    printf("The determinant of matrix elements is: %.2f.\n", determinant_matrix(matrix));
    return 0;
}

void init_matrix(int (*m)[2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            m[i][j] = get_int("Enter matrix[%d][%d]: ", i, j);
        }
    }
}

float determinant_matrix(int (*m)[2])
{
    // Diagonal principal - diagonal segundária.
    return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
    /*
    O que acontece de baixo dos panos quando chamamos: m[0][0]?
    - Expressão equivalente: *(*(m + i) + j).
        - (m+1) ponteiro para a linha (array) i;
        - *(m + i) retorna um "array", que, na verdade, é um ponteiro para o início da sequência;
        - (*(m + i) + j) avança para o índice j;
        - ... desreferência o elemento do índice j e retorna seu valor.
    */
}
