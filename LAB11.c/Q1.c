
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF (INT_MAX / 4)

typedef struct {
    int to, weight, next;
} Edge;

int main() {
    int n, m, S, C;

    printf("Enter vertices, edges, source and penalty: ");
    scanf("%d%d%d%d", &n, &m, &S, &C);

    int *head = malloc(n * sizeof(int));
    Edge *edges = malloc((m > 0 ? m : 1) * sizeof(Edge));

    for (int i = 0; i < n; i++)
        head[i] = -1;

    int cnt = 0;

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);

        edges[cnt] = (Edge){v, w, head[u]};
        head[u] = cnt++;
    }

    // State: 2 * vertex + parity
    int states = 2 * n;
    int *dist = malloc(states * sizeof(int));

    // At most 2*m successful relaxations, plus the source
    int cap = 2 * m + states + 5;
    int *dq = malloc(cap * sizeof(int));
    int front = 0, back = 0;

    for (int i = 0; i < states; i++)
        dist[i] = INF;

    int start = 2 * S;
    dist[start] = 0;
    dq[back] = start;
    back = (back + 1) % cap;

    while (front != back) {
        int state = dq[front];
        front = (front + 1) % cap;

        int u = state / 2;
        int parity = state % 2;

        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            int w = edges[i].weight;

            int newParity = parity ^ w;
            int nextState = 2 * v + newParity;
            int newDist = dist[state] + w;

            if (newDist < dist[nextState]) {
                dist[nextState] = newDist;

                if (w == 0) {
                    front = (front - 1 + cap) % cap;
                    dq[front] = nextState;
                } else {
                    dq[back] = nextState;
                    back = (back + 1) % cap;
                }
            }
        }
    }

    printf("\nMinimum effective costs:\n");

    for (int v = 0; v < n; v++) {
        int even = dist[2 * v];
        int odd = dist[2 * v + 1];

        if (even == INF && odd == INF) {
            printf("Vertex %d: Unreachable\n", v);
        } else {
            int ans = even;
            if (odd != INF && odd + C < ans)
                ans = odd + C;

            printf("Vertex %d: %d\n", v, ans);
        }
    }

    free(head);
    free(edges);
    free(dist);
    free(dq);

    return 0;
}