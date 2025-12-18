/*
Declare uma string (vetor de caracteres) e a inicialize com um texto.
Usando dois ponteiros (char *), um apontando para o início da string e
outro para o final, inverta a string ”in-place”, ou seja, sem criar um novo
vetor para armazenar o resultado. Exemplo: Se a string for
”programacao”, após a execução, ela deverá se tornar ”oacamargorp”.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get(char *output);
void replace_in_place(char *sentence);
void print(char *sentence);

int main(void)
{
    char *sentence = get("Input: ");

    replace_in_place(sentence);
    print(sentence);

    free(sentence);
    return 0;
}

char *get(char *output)
{
    char *returned = malloc(sizeof(char) * 100);
    printf("%s", output);
    scanf("%s", returned);

    return returned;
}

void replace_in_place(char *sentence)
{
    int len = strlen(sentence) - 1;

    char buffer;

    for (int i = 0, j = len; i < j; i++, j--)
    {
        // aritmética de ponteiros para definir o início e o fim da sentença
        char *begin = sentence + i;
        char *end = sentence + j;

        buffer = *end;
        *end = *begin;
        *begin = buffer;
    }
}

void print(char *sentence)
{
    int len = strlen(sentence);
    printf("\n");
    for (int i = 0; i < len; i++)
    {
        printf("%c", sentence[i]);
    }
    printf("\n");
}
