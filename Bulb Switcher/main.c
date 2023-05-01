#include <stdio.h>
#include <stdlib.h>

/* VERSÃO 2

QUESTAO 319 DO LEETCODE

AVISO:
foi utilizado eh para evitar o uso de acentos

a quantidade de divisores eh proporcional ao numero de "quadrados".
Por exemplo: n = 4

começa aqui:    0  0  0  0
1o round:       1  2  3  4
2o round:       1  0  3  0
3o round:       1  0  0  0
4o round:       1  0  0  4

o programa entao retornaria 2, que eh o total de numeros "quadrados" presentes entre 0 e 4 (no caso 1 e 4).

*/

int main() {
    int n, i, j, bulbs_on = 0; // define as lampadas acesas como 0

    printf("Informe o total de lampadas (0 <= n <= 10^9): ");
    scanf("%d", &n);

    int **grafo = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 1; i <= n; i++) {
        grafo[i] = (int *)malloc((n + 1) * sizeof(int));
        for (j = 1; j <= n; j++) {
            if (i % j == 0 || j % i == 0) {
                grafo[i][j] = 1;
            } else {
                grafo[i][j] = 0;
            }
        }
    }

    // contabiliza os vertices e define o numero de divisores
    for (i = 1; i <= n; i++) {
        int divisores = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                divisores++;
            } // VER AVISO NO COMEÇO DO CÓDIGO
        }
        if (divisores % 2 == 1) {
            bulbs_on++;
        }
    }

    printf("Lampadas acesas: %d\n", bulbs_on);

    // libera a memoria alocada
    for (i = 1; i <= n; i++) {
        free(grafo[i]);
    }
    free(grafo);

    return 0;
}
