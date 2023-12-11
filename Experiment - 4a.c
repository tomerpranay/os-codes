// Write a program to check whether a string include Keyword or not.
#include <stdio.h>
#include <string.h>

char keywords[][32] = {"auto", "break", "case", "char", "continue", "do", "default", "const", "double", "else", "enum", "extern", "for", "if", "goto", "float", "int", "long", "register", "return", "signed", "static", "sizeof", "short", "struct", "switch", "typedef", "union", "void", "while", "volatile", "unsigned"};

int isValidKeyword(char str[]) {
    for (int i=0; i<32; i++)
        if (!strcmp(str, keywords[i])) return 1;
    return 0;
}

char* containsKeyword(char str[]) {
    char* token = strtok(str, " ");
    while (token) {
        if (isValidKeyword(token)) return token;
        token = strtok(NULL, " ");
    }
    return NULL;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    char* keyword = containsKeyword(str);
    if (keyword != NULL) printf("String contains keyword: %s", keyword);
    else printf("String doesn't contain a keyword");
    return 0;
}