
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int to, next;
} Edge;

int main() {
    int n, m, K, R;

    printf("Enter vertices, edges, number of hubs and radius: ");
    scanf("%d%d%d%d", &n, &m, &K, &R);

    int *head = malloc(n * sizeof(int));
    Edge *edges = malloc((2 * m > 0 ? 2 * m : 1) * sizeof(Edge));

    for (int i = 0; i < n; i++)
        head[i] = -1;

    int cnt = 0;

    printf("Enter undirected edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        edges[cnt] = (Edge){v, head[u]};
        head[u] = cnt++;

        edges[cnt] = (Edge){u, head[v]};
        head[v] = cnt++;
    }

    int *dist = malloc(n * sizeof(int));
    int *owner = malloc(n * sizeof(int));
    int *queue = malloc(n * sizeof(int));
    int front = 0, back = 0;

    for (int i = 0; i < n; i++) {
        dist[i] = -1;
        owner[i] = -1;
    }

    printf("Enter hub vertices in increasing hub-index order:\n");

    for (int i = 1; i <= K; i++) {
        int h;
        scanf("%d", &h);

        dist[h] = 0;
        owner[h] = i;
        queue[back++] = h;
    }

    while (front < back) {
        int u = queue[front++];

        if (dist[u] == R)
            continue;

        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;

            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                owner[v] = owner[u];
                queue[back++] = v;
            }
        }
    }

    printf("\nVertex\tOwner\tDistance\n");

    for (int v = 0; v < n; v++)
        printf("%d\t%d\t%d\n", v, owner[v], dist[v]);

    free(head);
    free(edges);
    free(dist);
    free(owner);
    free(queue);

    return 0;
}