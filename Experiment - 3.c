//input string follows the rules of specific grammar or not
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int divideIdentifier(char str[], int init) {
    int len = strlen(str);
    if (!islower(str[init])) return -1;
    for (int i=init + 1; i<len; i++)
        if (!islower(str[i]) && !isdigit(str[i])) return i;
    return len;
}
int isValidOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '%');
}
int main() {
    char str[50];
    printf("Enter the string: ");
    scanf("%s", str);
    int index = divideIdentifier(str, 0);
    while (1) {
        if (index == strlen(str)) {
            printf("%s is accepted", str);
            break;
        } else if (index==-1 || !isValidOperator(str[index])) {
            printf("%s is rejected", str);
            break;
        }
        index = divideIdentifier(str, index+1);
    }
    return 0;
}