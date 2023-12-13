#include <stdio.h>

void printPageTable(int frameTable[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", frameTable[i]);
    printf("\n");
}

int find(int table[], int n, int target, int start) {
    for (int i = start; i < n; i++)
        if (table[i] == target) return i;
    return -1;
}

int findMax(int counter[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++)
        if (counter[i] > counter[max]) max = i;
    return max;
}

void updateCounter(int counter[], int n, int index) {
    counter[index] = 0;
    for (int i = 0; i < n; i++)
        if (i != index) counter[i]++;
}

void fifo(int frameTable[], int refTable[], int n, int ref) {
    int fault = 0, front = 0;
    for (int i = 0; i < ref; i++) {
        if (find(frameTable, n, refTable[i], 0) == -1) {
            frameTable[front] = refTable[i];
            front = (front + 1) % n;
            fault++;
        }
        printf("%d: ", refTable[i]);
        printPageTable(frameTable, n);
    }
    printf("Success: %d\nFailure: %d\n", ref - fault, fault);
}

void lru(int frameTable[], int refTable[], int n, int ref) {
    int fault = 0, counter[n];
    for (int i = 0; i < n; i++) counter[i] = 0;
    for (int i = 0; i < ref; i++) {
        int index = find(frameTable, n, refTable[i], 0);
        if (index != -1) updateCounter(counter, n, index);
        else {
            int max = findMax(counter, n);
            frameTable[max] = refTable[i];
            updateCounter(counter, n, max);
            fault++;
        }
        printf("%d: ", refTable[i]);
        printPageTable(frameTable, n);
    }
    printf("Success: %d\nFailure: %d\n", ref - fault, fault);
}

void optimal(int frameTable[], int refTable[], int n, int ref) {
    int fault = 0;
    for (int i = 0; i < ref; i++) {
        if (find(frameTable, n, refTable[i], 0) == -1) {
            int distant = 0;
            for (int j = 0; j < n; j++) {
                int index = find(frameTable, n, -1, i);
                if (index != -1) {
                    distant = index;
                    break;
                }
                index = find(refTable, ref, frameTable[j], i + 1);
                if (index > find(refTable, ref, frameTable[distant], i + 1)) distant = j;
                else if (index == -1) {
                    distant = j;
                    break;
                }
            }
            frameTable[distant] = refTable[i];
            fault++;
        }
        printf("%d: ", refTable[i]);
        printPageTable(frameTable, n);
    }
    printf("Success: %d\nFailure: %d\n", ref - fault, fault);
}

int main() {
    int n, ref, choice;
    printf("Enter the number of page frames: ");
    scanf("%d", & n);
    printf("Enter the number of page references: ");
    scanf("%d", & ref);
    int frameTable[n], refTable[ref];
    printf("Enter the page references: ");
    for (int i = 0; i < ref; i++)
        scanf("%d", & refTable[i]);
    printf("1) FIFO\n2) LRU\n3) Optimal\n4) Exit\n");
    do {
        printf("Enter the choice: ");
        scanf("%d", & choice);
        for (int i = 0; i < n; i++) frameTable[i] = -1;
        if (choice == 1) fifo(frameTable, refTable, n, ref);
        else if (choice == 2) lru(frameTable, refTable, n, ref);
        else if (choice == 3) optimal(frameTable, refTable, n, ref);
    } while (choice != 4);
    return 0;
}