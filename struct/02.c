/*
2) Crie um programa que utilize uma struct para representar um Vetor no plano
cartesiano R2. O programa deve ser capaz de:
    a) Criar uma struct chamada Vetor2D com dois campos do tipo float: x
    (coordenada horizontal) e y (coordenada vertical).

    b) Implemente uma função criar_vetor que recebe as coordenadas x e y
    e retorna uma nova struct Vetor2D inicializada.

    c) Implemente uma função calcular_modulo que recebe o endereço de
    uma struct Vetor2D (Passagem por Referência) e retorna o módulo (ou
    norma) desse vetor, que é calculado
*/
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
} vector2D;

vector2D *init_vector()
{
    vector2D *ptr = malloc(sizeof(vector2D));
    if (ptr == NULL) // Verifica falha na alocação
    {
        printf("Error: memory allocation failed\n");
        return NULL;
    }
    ptr->x = get_float("x-coordinate: ");
    ptr->y = get_float("y-coordinate: ");

    return ptr;
}

float get_module(vector2D *ptr)
{
    return sqrt((pow(ptr->x, 2) + pow(ptr->y, 2)));
}

int main(void)
{
    vector2D *vector = init_vector();
    printf("Vector module %.2f\n", get_module(vector));
    free(vector);
    return 0;
}