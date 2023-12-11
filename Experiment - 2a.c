// Write a program to check whether a string belong to the grammar (a)*ba

#include <stdio.h>
#include <string.h>

int validRegexInput(char str[])
{
  int len = strlen(str);
  int validInput = 0;
  if (str[len - 2] == 'b' && str[len - 1] == 'a')
    validInput = 1;

  for (int i = 0; i < len - 2; i++)
    if (str[i] != 'a')
    {
      validInput = 0;
      break;
    }

  return validInput;
}

void main()
{
  char str[20];
  printf("Enter the string : ");
  scanf("%s", str);

  if (validRegexInput(str))
    printf("%s is accepted\n", str);

  else
    printf("%s is rejected\n", str);
}