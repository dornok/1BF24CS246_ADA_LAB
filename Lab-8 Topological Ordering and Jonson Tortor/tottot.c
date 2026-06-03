#include <stdio.h>

#define LEFT 0
#define RIGHT 1


void printPermutation(int perm[], int n) {
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

int findPosition(int perm[], int n, int mobile) {
    int i;
    for(i = 0; i < n; i++) {
        if(perm[i] == mobile)
            return i;
    }
    return -1;
}

int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    int i;

    for(i = 0; i < n; i++) {

        if(dir[perm[i]-1] == LEFT && i != 0) {
            if(perm[i] > perm[i-1] && perm[i] > mobile)
                mobile = perm[i];
        }

        if(dir[perm[i]-1] == RIGHT && i != n-1) {
            if(perm[i] > perm[i+1] && perm[i] > mobile)
                mobile = perm[i];
        }
    }

    return mobile;
}

void johnsonTrotter(int n) {

    int perm[n], dir[n];
    int i;

    for(i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }


    printPermutation(perm, n);

    while(1) {

        int mobile = getMobile(perm, dir, n);

        if(mobile == 0)
            break;

        int pos = findPosition(perm, n, mobile);

        if(dir[mobile-1] == LEFT) {
            int temp = perm[pos];
            perm[pos] = perm[pos-1];
            perm[pos-1] = temp;

            pos = pos - 1;
        }
        else {
            int temp = perm[pos];
            perm[pos] = perm[pos+1];
            perm[pos+1] = temp;

            pos = pos + 1;
        }

        for(i = 0; i < n; i++) {
            if(perm[i] > mobile) {
                if(dir[perm[i]-1] == LEFT)
                    dir[perm[i]-1] = RIGHT;
                else
                    dir[perm[i]-1] = LEFT;
            }
        }

        printPermutation(perm, n);
    }
}

int main() {

    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
