// Write a program to check whether a grammar is operator precedent.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n, isOperatorGrammar = 1;
    printf("Enter number of rules: ");
    scanf("%d", & n);
    char L[n][1], R[n][100];
    for (int i = 0; i < n; i++) {
        printf("R%d: ", i + 1);
        scanf("%1s->%s", & L[i], & R[i]);
    }
    for (int i = 0; i < n; i++) {
        char * token = strtok(R[i], "/");
        while (token && isOperatorGrammar) {
            if (!strcmp(token, "ɛ")) isOperatorGrammar = 0;
            else {
                int len = strlen(token);
                for (int i = 0; i < len - 1 && isOperatorGrammar; i++)
                    if (isupper(token[i]) && isupper(token[i + 1])) isOperatorGrammar = 0;
            }
            token = strtok(NULL, "/");
        }
    }
    printf("The given grammar is ");
    if (!isOperatorGrammar) printf("not ");
    printf("an opeartor precedent grammar");
    return 0;
}