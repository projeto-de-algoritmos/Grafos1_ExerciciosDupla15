#include <stdio.h>
#include <stdlib.h>

// QUESTAO 997 DO LEETCODE


int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    //Armazena a quantidade de pessoas que CONFIAM em na pessoa n (int confia)
    //e o total de pessoas que a pessoa n confia (int confio)

    int *confia = (int*)calloc(n + 1, sizeof(int));
    int *confio = (int*)calloc(n + 1, sizeof(int));



    for (int i = 0; i < n - 1; i++) {
    printf("Em quem a pessoa %d confia? \n", i+1);
    scanf("%d", &trust[i][1]);
    trust[i][0] = i+1;
    confio[trust[i][0]]++;
    confia[trust[i][1]]++;
}

    int judge = -1;
    for (int i = 1; i <= n; i++) {
        if (confia[i] == n - 1 && confio[i] == 0) {
            judge = i;
            break;
        }
    }

    free(confia);
    free(confio);

    return judge;
}

int main() {
    int n;
    printf("Caso deseje encerrar o programa entre ctrl + d \n");
    printf("Digite o valor de n (entre 1 e 1000): ");
    scanf("%d", &n);

    int trustSize = 1000;
    int **trust = (int**)malloc(trustSize * sizeof(int*));
    for (int i = 0; i < trustSize; i++) {
        trust[i] = (int*)malloc(2 * sizeof(int));
        trust[i][0] = i + 1; // inicializa o array com os indices
    }

    int trustColSize[trustSize];
    int judge = findJudge(n, trust, trustSize, trustColSize);

    if (judge != -1) {
        printf("O juiz da cidade eh a pessoa %d\n", judge);
    } else {
        printf("Nao foi possivel identificar quem eh o juiz da cidade.\n");
    }

    for (int i = 0; i < trustSize; i++) {
        free(trust[i]);
    }
    free(trust);

    return 0;
}
