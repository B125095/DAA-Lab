
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100005
#define HS 262144

char words[MAX][11];
int table[HS];

unsigned long long hash(char *s) {
    unsigned long long h = 5381;
    while (*s)
        h = h * 33 + *s++;
    return h % HS;
}

int find(char *s) {
    unsigned long long h = hash(s);
    while (table[h]) {
        int i = table[h] - 1;
        if (strcmp(words[i], s) == 0)
            return i;
        h = (h + 1) % HS;
    }
    return -1;
}

void insert(int i) {
    unsigned long long h = hash(words[i]);
    while (table[h])
        h = (h + 1) % HS;
    table[h] = i + 1;
}

int bfs(int a, int b, int n, int len) {
    int *d1 = malloc(n * sizeof(int));
    int *d2 = malloc(n * sizeof(int));
    int *f1 = malloc(n * sizeof(int));
    int *f2 = malloc(n * sizeof(int));
    int *next = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        d1[i] = d2[i] = -1;

    int s1 = 1, s2 = 1;
    f1[0] = a;
    f2[0] = b;
    d1[a] = d2[b] = 0;

    while (s1 && s2) {
        if (s1 > s2) {
            int *t = f1; f1 = f2; f2 = t;
            t = d1; d1 = d2; d2 = t;
            int z = s1; s1 = s2; s2 = z;
        }

        int cnt = 0;

        for (int i = 0; i < s1; i++) {
            int u = f1[i];

            for (int j = 0; j < len; j++) {
                char old = words[u][j];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == old) continue;

                    words[u][j] = c;
                    int v = find(words[u]);

                    if (v != -1) {
                        if (d2[v] != -1) {
                            int ans = d1[u] + 1 + d2[v];
                            free(d1); free(d2);
                            free(f1); free(f2); free(next);
                            return ans;
                        }

                        if (d1[v] == -1) {
                            d1[v] = d1[u] + 1;
                            next[cnt++] = v;
                        }
                    }
                }
                words[u][j] = old;
            }
        }

        int *t = f1;
        f1 = next;
        next = t;
        s1 = cnt;
    }

    free(d1); free(d2);
    free(f1); free(f2); free(next);
    return -1;
}

int main() {
    int N;
    char A[11], B[11];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%10s", words[i]);
        insert(i);
    }

    scanf("%10s %10s", A, B);

    if (strcmp(A, B) == 0) {
        printf("0\n");
        return 0;
    }

    int b = find(B);
    if (b == -1) {
        printf("-1\n");
        return 0;
    }

    int a = find(A);
    if (a == -1) {
        strcpy(words[N], A);
        a = N;
        insert(N);
        N++;
    }

    int ans = bfs(a, b, N, strlen(A));
    printf("%d\n", ans);

    return 0;
}