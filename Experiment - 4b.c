//count keyword Identifer Operator Constant
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int key = 0, id = 0, op = 0, integer = 0;

int isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=');
}

int isDelimiter(char ch) {
	return (ch == ' ' || ch == ',' || ch == ';' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || isOperator(ch));
}

int isInteger(char* str) {
	int i, len = strlen(str);
	if (len == 0) return 0;
	for (i = 0; i < len; i++)
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0)) return 0;
	return 1;
}

int validIdentifier(char ch) {
	return !(ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || isDelimiter(ch));
}

int isKeyword(char* str) {
    // More keywords to be included
	return !(strcmp(str, "if") && strcmp(str, "else") && strcmp(str, "while") && strcmp(str, "do") && strcmp(str, "break") && strcmp(str, "continue") && strcmp(str, "int") && strcmp(str, "double") && strcmp(str, "float") && strcmp(str, "return") && strcmp(str, "char") && strcmp(str, "case") && strcmp(str, "sizeof") && strcmp(str, "long") && strcmp(str, "short") && strcmp(str, "typedef") && strcmp(str, "switch") && strcmp(str, "unsigned") && strcmp(str, "void") && strcmp(str, "static") && strcmp(str, "struct") && strcmp(str, "goto"));
}

char* subString(char* str, int left, int right) {
	char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));
	for (int i = left; i <= right; i++) subStr[i - left] = str[i];
	subStr[right - left + 1] = '\0';
	return (subStr);
}

void parse(char* str) {
	int left = 0, right = 0;
	int len = strlen(str);
	while (right <= len && left <= right) {
		if (!isDelimiter(str[right])) right++;
		if (isDelimiter(str[right]) && left == right) {
			if (isOperator(str[right])) op++;
			right++;
			left = right;
		} else if (isDelimiter(str[right]) && left != right || (right == len && left != right)) {
			char* subStr = subString(str, left, right - 1);
			if (isKeyword(subStr)) key++;
			else if (isInteger(subStr)) integer++;
			else if (validIdentifier(subStr[0]) && !isDelimiter(str[right - 1])) id++;
			left = right;
		}
	}
}

int main() {
	char str[100] = "int sum = 0; int i = 0; while ( i < = 10 ) { sum = sum + i; i = i + 1; }";
	parse(str); // calling the parse function
	printf("Identifer count: %d\n", id);
	printf("Keyword count: %d\n", key);
	printf("Operator count: %d\n", op);
	printf("Constant count: %d\n", integer);
	return 0;
}