/*
3) Faça um programa que receba dois vetores com N números, no qual
cada número do vetor deve conter apenas números entre 0 e 9 (valide
essa operação). Depois some os dois primeiros números e gere um terceiro vetor
com a soma. Exemplo: vet1 = [8, 2, 3] e vet2 =[3, 4, 9] geraria o vet3 =
[1, 1, 7, 2].
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    printf("Insira N: ");
    scanf("%d", &n);
    printf("\n");

    // Inicializando o primeiro vetor.
    printf("Inicialize o primeiro vetor, só serão aceitos números entre `0 e 9`.\n");
    int a1[n];
    int b;
    for (int i = 0; i < n; i++)
    {
        printf("Entrada [%d]: ", i);
        scanf("%d", &b);

        if (!(b > 0 && b < 10))
        {
            printf("Entrada inválida, tente novamente!");
            return 1;
        }

        a1[i] = b;
    }

    // Inicializando o segundo vetor.
    printf("Inicialize o segundo vetor, só serão aceitos números entre `0 e 9`.\n");
    int a2[n];
    for (int i = 0; i < n; i++)
    {
        printf("Entrada [%d]: ", i);
        scanf("%d", &b);

        if (!(b > 0 && b < 10))
        {
            printf("Entrada inválida, tente novamente!");
            return 1;
        }

        a2[i] = b;
    }

    // Gerando terceiro vetor.
    int len = n + 1;
    int a3[len];
    int vai1 = 0;
    int sum = 0;

    for (int i = n; i >= 0; i--)
    {
        if ((i - 1) < 0)
        {
            sum = vai1;
        }
        else
        {
            sum = a1[i - 1] + a2[i - 1] + vai1;
        }

        // Calculando vai 1
        vai1 = (sum > 9) ? 1 : 0;

        // Salvando o índice
        a3[i] = (vai1 == 0) ? sum : sum - 10;
    }

    for (int i = 0; i < len; i++)
    {
        if (i == 0)
        {
            printf("[");
            printf("%d, ", a3[i]);
        }
        else if (i == n)
        {

            printf("%d", a3[i]);
            printf("]");
        }
        else
        {
            printf("%d, ", a3[i]);
        }
    }
    printf("\n");

    return 0;
}