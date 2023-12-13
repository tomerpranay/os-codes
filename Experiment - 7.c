#include<stdio.h>

void printMemory(int memory[], int n) {
    printf("\nMemory Blocks: ");
    for (int i = 0; i < n; i++) printf("%d ", memory[i]);
}

int main() {
    int m, n;
    printf("Enter the number of memory blocks: ");
    scanf("%d", & m);
    printf("Enter the number of jobs: ");
    scanf("%d", & n);
    int firstTable[m], bestTable[m], worstTable[m], jobs[n], first[n], best[n], worst[n];
    printf("Enter the size of memory blocks: ");
    for (int i = 0; i < m; i++) {
        int value;
        scanf("%d", & value);
        firstTable[i] = bestTable[i] = worstTable[i] = value;
    }
    printf("Enter the size of jobs: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", & jobs[i]);
        first[i] = best[i] = worst[i] = -1;
    }
    printf("First Fit:\nJobs allocated at: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (firstTable[j] >= jobs[i]) {
                first[i] = j;
                firstTable[j] -= jobs[i];
                break;
            }
        printf("%d ", first[i]);
    }
    printMemory(firstTable, m);
    printf("\nBest Fit:\nJobs allocated at: ");
    for (int i = 0; i < n; i++) {
        int remaining = 999999;
        for (int j = 0; j < m; j++) {
            int diff = bestTable[j] - jobs[i];
            if (diff >= 0 && diff < remaining) {
                best[i] = j;
                remaining = diff;
            }
        }
        if (best[i] != -1) bestTable[best[i]] -= jobs[i];
        printf("%d ", best[i]);
    }
    printMemory(bestTable, m);
    printf("\nWorst Fit:\nJobs allocated at: ");
    for (int i = 0; i < n; i++) {
        int remaining = -1;
        for (int j = 0; j < m; j++) {
            int diff = worstTable[j] - jobs[i];
            if (diff > remaining) {
                worst[i] = j;
                remaining = diff;
            }
        }
        if (worst[i] != -1) worstTable[worst[i]] -= jobs[i];
        printf("%d ", worst[i]);
    }
    printMemory(worstTable, m);
    return 0;
}