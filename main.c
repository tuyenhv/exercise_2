#include <stdio.h>
#include <stdbool.h>
#include <float.h>
#include "headers.h"

int main(void)
{
  char str[MAX_LEN];
  char *expression = str;
  printf("Input the expression: \n");
  scanf("%[^\n]%*c", expression);
  printf("Output: %c\n", *expression);
  printf("Max float: %f \n", FLT_MAX);

  return 0;
}

/* Return the value of the first element in a string*/
char peek(char *str){
  return *str;
}

/* Return the value of the first element in a string and increase the pointer
   to the second element*/
char get(char *str){
  return *str++;
}

/* check whether the pointer is end of string or not*/
bool has_next(char *expression){
  if (*expression != '\0')
    return true;
  else
    return false;
}

void skip_white_space(char *expression){
  while (has_next(*expression)){
    if ((*expression = '\t') || (*expression = '\v') || (*expression = ' '))
      expression++;
  }
}

float parse_number(char *expression){
  skip_white_space(expression);
  char str_value[MAX_FLOAT_LEN];
}
