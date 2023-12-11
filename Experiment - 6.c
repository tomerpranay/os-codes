// Write a program to perform Left Factoring on a Grammar.
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
    printf("Grammar after left factoring:");
    for (int i = 0; i < n; i++) {
        char LHS = L[i][0];
        char RHS[100];
        strcpy(RHS, R[i]);
        char * tokens[100];
        char * token = strtok(R[i], "/");
        if (!token) break;
        int j = 0, count = 0;
        while (token) {
            tokens[j++] = token;
            token = strtok(NULL, "/");
        }
        int lf[j];
        for (int k = 0; k < j; k++) lf[k] = -1;
        for (int k = 0; k < j; k++) {
            if (lf[k] != -1) continue;
            lf[k] = k;
            char * token1 = tokens[k];
            int len = strlen(token1);
            int x = len, y, unique = 1, slash = 0;
            for (int l = k + 1; l < j; l++) {
                char * token2 = tokens[l];
                for (y = 0; y < x && token1[y] == token2[y]; y++);
                if (y > 0) {
                    lf[l] = k;
                    if (y < x) x = y;
                }
            }
            for (int l = 0; l < j; l++)
                if (l != k && lf[l] == k) {
                    unique = 0;
                    break;
                }
            printf("\n%c->", LHS);
            for (y = 0; y < x; y++) printf("%c", token1[y]);
            if (unique) continue;
            count++;
            printf("%c", LHS);
            for (int l = 0; l < count; l++) printf("'");
            printf("\n%c", LHS);
            for (int l = 0; l < count; l++) printf("'");
            printf("->");
            for (int l = 0; l < j; l++) {
                if (lf[l] != k) continue;
                if (slash) printf("/");
                else slash = 1;
                char * token = tokens[l];
                int len = strlen(token);
                if (x == len) printf("ε");
                for (int z = x; z < len; z++) printf("%c", token[z]);
            }
        }
    }
    return 0;
}