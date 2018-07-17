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
  int i = 0;
  bool decimal_found = false;
  char c;

  while (has_next(*expression)){
    c = peek(*expression);
    if (c == '.'){
      if (decimal_found)
        printf("Warning: Found more than one . character in a number \n");
      decimal_found = true;
      str_value[i] = '.';
      i++;
    }
    else if (c >= '0' && c <= '9'){
      str_value[i] = 'c';
      i++;
    }
    else
      break;
    expression++;

    // Return the value of str_value in float
    // return (float) 

  }
}
