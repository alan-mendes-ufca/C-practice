/*
Escreva um programa que verifique se uma palavra ou frase fornecida
pelo usuário é um palíndromo.

Um palíndromo é uma sequência que
se lê da mesma forma da esquerda para a direita e da direita para a
esquerda.

O programa deve usar um ponteiro começando no início da
string e outro começando no final. Os dois ponteiros devem se mover
em direção ao centro, comparando os caracteres em cada passo. A
verifica ̧c ̃ao deve parar assim que encontrarem uma diferen ̧ca ou se
cruzarem.

Input: Uma string (palavra ou frase). Para simplificar,
considere apenas letras minúsculas e sem espaços. Output: Uma
mensagem dizendo ”E pal ́ındromo”ou ”Não é palíndromo”. Exemplo: (
Input: arara Output: É palíndromo), (Input: banana Output: Não é
palíndromo).
*/

#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool is_palindromo(char *sentence);
char *normalization(char *sentence);
void print(char *sentence);

int main(void)
{
    char *sentence = get_string("Input: ");
    sentence = normalization(sentence);

    if (is_palindromo(sentence))
    {
        print(sentence);
        printf("\nÉ um palíndromo!\n");
    }
    else
    {
        print(sentence);
        printf("\nNão é um palíndromo!\n");
    }

    return 0;
}

char *normalization(char *sentence)
{
    int len = strlen(sentence) - 1;
    char *standardized = malloc(sizeof(char) * (len + 1));
    int j = 0;
    for (int i = 0; i <= len; i++)
    {
        // Para previvinir erro de inconsistências numa sequência utiliza-se um contator j que, diferente o i não salta quando o caractere é um espaço.
        if (!isspace(sentence[i]))
        {
            standardized[j] = tolower(sentence[i]);
            j++;
        }
    }
    standardized[j] = '\0'; // Ao criar uma string com malloc, sempre definir o final com '\0'.
    return standardized;
}

bool is_palindromo(char *sentence)
{
    int len = strlen(sentence) - 1;
    char *end;
    char *begin;

    for (int i = 0, j = len; i <= j; i++, j--)
    {
        begin = sentence + i;
        end = sentence + j;

        if (*begin != *end)
        {
            return false;
        }
    }
    return true;
}

void print(char *sentence)
{

    int len = strlen(sentence) - 1;
    printf("\n");
    for (int i = 0; i <= len; i++)
    {
        printf("%c", sentence[i]);
    }
    printf("\n");
}
