#include <stdio.h>
#include <stdlib.h>

#define VAL_MAX 2000

// Questao 886 do leetcode

int n;
int marca[VAL_MAX + 1];
int adj[VAL_MAX + 1][VAL_MAX + 1];

int dfs(int v, int c) { //algoritmo de busca em largura
    marca[v] = c;
    for (int i = 1; i <= n; i++) {
        if (adj[v][i]) {
            if (marca[i] == c) return 0;
            if (!marca[i] && !dfs(i, -c)) return 0;
        }
    }
    return 1;
}

int main() {
    int m, a, b;
    printf("Informe quantas pessoas existem: \n");
    scanf("%d", &n);
    m = n;

    printf("Informe a pessoa e a pessoa de quem ela nao gosta (Exemplo -> 1 2, caso deseje encerrar entre ctrl+d):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        adj[a][b] = adj[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!marca[i] && !dfs(i, 1)) { //caso nao seja possivel separar o programa retorna false
            printf("false\n");
            return 0;
        }
    }
    printf("true\n");
    return 0;
}
