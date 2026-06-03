#include <stdio.h>

int n, a[10][10], indegree[10];

void topologicalSort() {
    int i, j, k;

    for(i = 0; i < n; i++) {
        indegree[i] = 0;
        for(j = 0; j < n; j++) {
            indegree[i] += a[j][i];
        }
    }

    printf("Topological Ordering: ");

    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {

            if(indegree[i] == 0) {

                printf("%d ", i);

                indegree[i] = -1;

                for(j = 0; j < n; j++) {
                    if(a[i][j] == 1)
                        indegree[j]--;
                }
            }
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    topologicalSort();

    return 0;
}
