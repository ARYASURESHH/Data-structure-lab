#include<stdio.h>
#include<stdlib.h>

int i, j, l, k, u, v, ru, rv, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int u)
{
    while (parent[u])
        u = parent[u];
    return u;
}

void uni(int ru, int rv)
{
    parent[rv] = ru;
}

void main()
{
    printf("Enter the no.of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("The edges of minimum cost spanning tree are:\n");

    while (ne < n)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        ru = find(u);
        rv = find(v);

        if (ru != rv)
        {
            uni(ru, rv);
            printf("%d edge (%d,%d) = %d\n", ne++, u, v, min);
            mincost += min;
        }

        cost[u][v] = cost[v][u] = 999;
    }

    printf("Minimum cost = %d\n", mincost);
}

