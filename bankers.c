#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("\n THE GIVEN PROGRAM ID TO DETERMINE WHETHER THE SYSTEM IS IN SAFE STATE OR NOT");
    int curr[5][5];
    int max_claim[5][5];//to allocate maximum resources to each file
    int avl[5];//tell available resources to each file
    int alloc[5] = {0, 0, 0, 0, 0};
    int max_res[5];// to declare maximum number of resources
    int running[5];

    int i, j, exec, r, p;
    int count = 0;
    bool safe = false;

    printf("\nEnter the number of resources: ");
    scanf("%d", &r);

    printf("\nEnter the number of processes: ");
    scanf("%d", &p);
    for (i = 0; i < p; i++) {
        running[i] = 1;
        count++;
    }

    printf("\nEnter Total instances of resources  ");
    for (i = 0; i < r; i++)
        scanf("%d", &max_res[i]);

    printf("\nEnter Allocated Resource Table: ");
    for (i = 0; i < p; i++) {
            printf("\nfor process %d:- ",i+1);
        for (j = 0; j < r; j++)
            scanf("%d", &curr[i][j]);
    }

    printf("\nEnter Maximum resources for each process: ");
    for (i = 0; i < p; i++) {
            printf("\nfor process %d:- ",i+1);
        for (j = 0; j < r; j++)
            scanf("%d", &max_claim[i][j]);
    }

    printf("\nTotal instacne of resources are : ");
    for (i = 0; i < r; i++)
        printf("%d ", max_res[i]);

    printf("\nThe Allocation Resource Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", curr[i][j]);
        printf("\n");
    }

    printf("\nThe Maximum resource table Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", max_claim[i][j]);
        printf("\n");
    }

    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            alloc[j] += curr[i][j];

    printf("\nAllocated resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", alloc[i]);
    for (i = 0; i < r; i++)
        avl[i] = max_res[i] - alloc[i];

    printf("\nAvailable resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", avl[i]);
    printf("\n");

    while (count != 0) {
        safe = false;
        for (i = 0; i < p; i++) {
            if (running[i]) {
                exec = 1;
                for (j = 0; j < r; j++) {
                    if (max_claim[i][j] - curr[i][j] > avl[j]) {
                        exec = 0;
                        break;
                    }
                }

                if (exec) {
                    printf("\nProcess%d is executing.\n", i + 1);
                    running[i] = 0;
                    count--;
                    safe = true;
                    for (j = 0; j < r; j++)
                        avl[j] += curr[i][j];
                    break;
                }
            }
        }

        if (!safe) {
            printf("\n\nThe system are in unsafe state.");
            break;
        }

        if (safe)
            printf("\n\nThe System is in safe state.\n");

        printf("\nTotal resources available after execution: ");
        for (i = 0; i < r; i++)
            printf("%d ", avl[i]);
    }

    return 0;
}

