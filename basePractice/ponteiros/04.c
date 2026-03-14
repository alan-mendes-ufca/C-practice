/*
Modifique o código da questão dois, de forma que seja requisitado ao
usuário o tamanho n dos vetores e, na sequência, os elementos dos
vetores. Utilize ponteiros para criação dos vetores.
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

char **init_matrix_memory(int len);
char **init_matrix_normalized_memory(char **m_orig, int len);
char *normalization(char *sentence);
bool is_palindromo(char *sentence);
void print(char *sentence);

int main(void)
{
    int numVectors = get_int("Number of vectors: ");

    char **m_orig = init_matrix_memory(numVectors);

    char **m_norm = init_matrix_normalized_memory(m_orig, numVectors);

    // matriz booleana para armazenar quais frases normalizadas são pontieros ou não.
    bool *m_norm_is_palindromo = malloc(sizeof(bool) * numVectors);
    // inicializando a m_bool
    for (int i = 0; i < numVectors; i++)
    {
        m_norm_is_palindromo[i] = is_palindromo(m_norm[i]);
    }

    // Output: sentenças que, de fato, sçao palídromos.
    printf("---------------------------------------------\nPalídromo sentences:");
    for (int i = 0; i < numVectors; i++)
    {
        if (m_norm_is_palindromo[i])
        {
            print(m_norm[i]);
        }
    }
    printf("\n---------------------------------------------\n");

    // liberando memória alocada para m_orig
    for (int i = 0; i < numVectors; i++)
    {
        // free(m_orig[i]); - get_string já gerencia memória automaticamente.
        free(m_norm[i]);
    }
    free(m_orig);
    free(m_norm);
    free(m_norm_is_palindromo);
}

char **init_matrix_memory(int len)
{
    char **m = malloc(sizeof(char *) * len);
    for (int i = 0; i < len; i++)
    {
        // m aponta para pontiero de início do array
        *(m + i) = get_string("Sentence [%d]: ", i + 1);
        /*
        - m aponta para o primeiro ponteiro do array de ponteiros, onde cada ponteiro aponta para o início de uma string.
            - Vizualize:
                m
                │
                ├── m[0] → string de até LEN caracteres.
                ├── m[1] → string de até LEN caracteres.
                └── m[2] → string de até LEN caracteres.
        */
    }
    return m;
}

char **init_matrix_normalized_memory(char **m_orig, int len)
{
    char **m = malloc(sizeof(char *) * len);
    for (int i = 0; i < len; i++)
    {
        // Ponteiro buffer que aponta para a frase sem normalização;
        m[i] = normalization(m_orig[i]);
    }
    return m;
}

char *normalization(char *sentence)
{
    int len = strlen(sentence);
    char *standardized = malloc(sizeof(char) * (len + 1));
    int j = 0;
    for (int i = 0; i < len; i++)
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

    int len = strlen(sentence);
    printf("\n");
    for (int i = 0; i < len; i++)
    {
        printf("%c", sentence[i]);
    }
}
