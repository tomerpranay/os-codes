// program which accepts all the string start with a letter followed by a digit or a letter

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validRegexInput(char str[])
{
  if (islower(str[0]) && (islower(str[1]) || isdigit(str[1])))
    return 1;
  else
    return 0;
}

void main()
{
  char str[50];
  printf("Enter the string : ");
  scanf("%s", str);

  if (validRegexInput(str))
    printf("%s is accepted", str);
  else
    printf("%s is rejected", str);
}