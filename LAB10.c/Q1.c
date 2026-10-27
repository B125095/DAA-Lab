
#include <stdio.h>

int parent[1000], size[1000], parity[1000];

int find(int x)
{
    if (parent[x] != x) {
        int p = parent[x];
        parent[x] = find(p);
        parity[x] ^= parity[p];
    }
    return parent[x];
}

int addEdge(int u, int v)
{
    int ru = find(u), pu = parity[u];
    int rv = find(v), pv = parity[v];

    if (ru == rv)
        return (pu ^ pv) == 1;

    if (size[ru] < size[rv]) {
        parent[ru] = rv;
        parity[ru] = pu ^ pv ^ 1;
        size[rv] += size[ru];
    } else {
        parent[rv] = ru;
        parity[rv] = pu ^ pv ^ 1;
        size[ru] += size[rv];
    }
    return 1;
}

int main()
{
    int V, E, u, v;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    if (V < 1 || V > 1000 || E < 0) {
        printf("Invalid input\n");
        return 0;
    }

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        size[i] = 1;
        parity[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= V || v < 0 || v >= V) {
            printf("Invalid edge\n");
            i--;
            continue;
        }

        if (addEdge(u, v))
            printf("Edge (%d, %d): Accepted\n", u, v);
        else
            printf("Edge (%d, %d): Rejected\n", u, v);
    }

    return 0;
}