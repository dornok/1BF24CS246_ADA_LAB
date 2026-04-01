#include <stdio.h>

#define MAX 10
#define INF 9999

int main() {
    int cost[MAX][MAX], distance[MAX], visited[MAX];
    int n, i, j, source, count, mindistance, nextnode;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter ADJ matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for(i = 0; i < n; i++) {
        distance[i] = cost[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;

    for(count = 1; count < n - 1; count++) {
        mindistance = INF;

        for(i = 0; i < n; i++) {
            if(distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        for(i = 0; i < n; i++) {
            if(!visited[i] && mindistance + cost[nextnode][i] < distance[i]) {
                distance[i] = mindistance + cost[nextnode][i];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);
    for(i = 0; i < n; i++) {
        printf("To vertex %d = %d\n", i, distance[i]);
    }

    return 0;
}
