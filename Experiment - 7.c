// Write a program to find out the leading of the non-terminals in a grammar

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int isterminal(char c) {
    return c >= 33 && c <= 126 && !isupper(c);
}

char * leading(char LHS, char L[][1], char R[][100], int n) {
    char * lead = (char * ) malloc(100);
    for (int i = 0; i < n; i++) {
        if (LHS != L[i][0]) continue;
        char * temp = (char * ) malloc(100);
        strcpy(temp, R[i]);
        char * token = strtok(temp, "/");
        char tokens[100][100];
        int c = 0;
        while (token) {
            strcpy(tokens[c++], token);
            token = strtok(NULL, "/");
        }
        for (int j = 0; j < c; j++) {
            char * token = tokens[j];
            if (isterminal(token[0])) lead[strlen(lead)] = token[0];
            else if (isupper(token[0])) {
                if (isterminal(token[1])) lead[strlen(lead)] = token[1];
                if (token[0] != LHS) strcat(lead, leading(token[0], L, R, n));
            }
        }
        break;
    }
    return lead;
}

int main() {
    int n;
    printf("Enter number of rules: ");
    scanf("%d", & n);
    char L[n][1], R[n][100];
    for (int i = 0; i < n; i++) {
        printf("R%d: ", i + 1);
        scanf("%1s->%s", & L[i], & R[i]);
    }
    for (int i = 0; i < n; i++) {
        char LHS = L[i][0];
        printf("%c: %s\n", LHS, leading(LHS, L, R, n));
    }
    return 0;
}