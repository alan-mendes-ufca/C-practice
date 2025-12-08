/*
Faça um programa que receba um vetor com N números. Supondo que
o vetor digitado foi [1, 2, 3, 4], imprima-o da seguinte maneira: (1) (2)
(3) (4)
*/
#include <stdio.h>

int main(void){
    int n = 0;
    printf("Input: ");
    scanf("%d", &n);
    
    int array[n];
    for(int i = 0; i<n; i++){
        printf("Input [%d]: ", i+1);
        scanf("%d", &array[i]);
    }
    printf("\n");

    for(int i=0; i<n; i++){
        printf("(%d) ", array[i]);
    }
    printf("\n");
}