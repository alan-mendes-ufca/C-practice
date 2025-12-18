/*
Escreva uma função para calcular o fatorial de um número de
forma recursiva. A função fatorialRecursivo deve receber um
inteiro n e retornar n!.
*/

#include <stdio.h>
#include <cs50.h>

int recursive_factorial(int number);

int main(void)
{
    int n = get_int("Input: ");
    printf("%d! = %d\n", n, recursive_factorial(n));
    return 0;
}

int recursive_factorial(int number)
{
    // Caso base || Recurção
    return number == 0 ? 1 : number * recursive_factorial(number - 1);
}