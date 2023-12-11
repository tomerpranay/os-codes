// Write a program to remove left Recursion from a Grammar
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of rules: ");
    scanf("%d", & n);
    char L[n][1], R[n][100];
    for (int i = 0; i < n; i++) {
        printf("R%d: ", i + 1);
        scanf("%1s->%s", & L[i], & R[i]);
    }
    printf("Grammar without left recursion:\n");
    for (int i = 0; i < n; i++) {
        char LHS = L[i][0];
        char RHS[100];
        strcpy(RHS, R[i]);
        char * a[100];
        char * b[100];
        char * token = strtok(R[i], "/");
        if (!token) break;
        int j = 0, k = 0;
        while (token) {
            if (token[0] == LHS) a[k++] = token + 1;
            else b[j++] = token;
            token = strtok(NULL, "/");
        }
        if (!k) {
            printf("%c->%s\n", LHS, RHS);
            continue;
        }
        printf("%c->", LHS);
        for (int l = 0; l < j; l++) {
            if (l) printf("/");
            printf("%s%c'", b[l], LHS);
        }
        printf("\n%c'->", LHS);
        for (int l = 0; l < k; l++)
            printf("%s%c'/", a[l], LHS);
        printf("ε\n");
    }
    return 0;
}