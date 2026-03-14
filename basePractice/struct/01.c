/*
1) Imagine que você precisa armazenar informações de vários alunos: nome,
matrícula e duas notas. Você também precisa calcular a média das notas de
cada aluno e imprimir se ele passou ou não. Utilize struct para resolver essa
questão.
*/

typedef struct
{
    char *name;
    char *registration;
    float av1;
    float av2;
    float avg;
} aluno;

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int len = 1;
    aluno *students = malloc(len * sizeof(aluno));
    // a1.name = "Leôncio"; // Uma string literal é alocada automaticamente pelo compilador.

    for (int i = 0; i < len; i++)
    {
        // inicializando aluno
        (students + i)->name = malloc(20 * sizeof(char));
        printf("Nome do aluno: ");
        scanf("%s", (students + i)->name);

        (students + i)->registration = malloc(10 * sizeof(char));
        printf("Matrícula do aluno: ");
        scanf("%s", (students + i)->registration);

        printf("AV1 de %s: ", (students + i)->name);
        scanf("%f", &(students + i)->av1);

        printf("AV2 de %s: ", (students + i)->name);
        scanf("%f", &(students + i)->av2);

        // calculando a média
        (students + i)->avg = ((students + i)->av1 + (students + i)->av2) / 2;
    }
    // retornando os valores

    for (int i = 0; i < len; i++)
    {
        printf("\n%s\n", students[i].name);
        printf("%s\n", students[i].registration);
        printf("%.2f\n", students[i].av1);
        printf("%.2f\n", students[i].av2);
        printf("%.2f\n", students[i].avg);
    }

    return 0;
}