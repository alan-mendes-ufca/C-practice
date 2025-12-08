/*
6) Dadas as datas de aniversário de um casal, diz-se que o casal é
perfeito se o número mágico dos dois é igual. O número mágico é
obtido por somar-se repetidamente os dígitos da data de aniversário
dos indivíduos no formato ddmmaaaa até que esse número permaneça
com um único digito. Faça um programa que verifique se um casal é
perfeito ou não, dados as datas de nascimento do casal no formato
ddmmaaaa. Exemplo: niver1 = 19011981 (1+9+0+1+1+9+8+1 = 30 =
3+0 = 3) e niver2 = 23321973 (2+3+3+2+1+9+7+3 = 30 = 3+0= 3), logo
este casal é perfeito.

Atenção: N deverá ser uma constante declarada no início do programa
com #define N <valor>
*/

#include <stdbool.h>
#include <stdio.h>

bool is_perfect(char *anv1, char *anv2);
int sum(char *anv);

int main(void)
{
    char *anv1 = "05042006";
    char *anv2 = "10112004";

    if (is_perfect(anv1, anv2))
    {
        printf("Felicidades, o casal é feito um para o outro!\n");
    }
    else
    {
        printf("O destino de você pode estar fadado ao fracasso...\n");
    }

    return 0;
}

bool is_perfect(char *anv1, char *anv2)
{
    return sum(anv1) == sum(anv2);
}

int sum(char *anv)
{
    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        // subtração de valores ascii
        sum += anv[i] - '0';
    }

    // caso o número tenha duas casas é necessário soma-las.
    if (sum > 9)
    {
        // Converter cada dígito para um char separadamente
        // char centena = ((sum/100) % 10);
        char dezena = ((sum / 10) % 10) + '0';
        char unidade = (sum % 10) + '0';

        sum = (dezena - '0') + (unidade - '0');
    }

    return sum;
}
