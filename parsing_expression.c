#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"parsing_expression.h"

int main(void)
{
  char str[MAX_LEN];
  int index;
  printf("Input the expression: \n");
  scanf("%[^\n]%*c", str);
  remove_spaces(str);
  float result = expression(str, &index);
  printf("result: %f \n", result);
  return 0;
}

/* Remove spaces in the input string before parsing it*/
void remove_spaces(char *str){
  int i, count = 0;
  for (i = 0; str[i]; i++)
    if (str[i] != ' ')
        str[count++] = str[i];

  str[count] = '\0';
}

/* Get the character with index in the string*/
char get(char *str, int *index){
  return *(str + (*index));
}

/* Get the float number from the input string*/
float number(char *str, int *index){
  char str_value[MAX_FLOAT_LEN];
  int i = 0;
  while ((get(str, index) >= '0' && get(str, index) <= '9') || get(str, index) == '.'){
    str_value[i] = get(str, index);
    (*index)++;
    i++;
  }
  str_value[i] = '\0';
  return atof(str_value);
}

/* Parse the string and handle if the character is number or parenthesis*/
float factor(char *str, int *index){
  if (get(str, index) >= '0' && get(str, index) <= '9')
    return number(str, index);
  else if (get(str, index) == '('){
    // Increase index when get '()'
    (*index)++;
    float result = expression(str, index);
    // Increase index when get ')'
    (*index)++;
    return result;
  }
  else if (get(str, index) == '-'){
    // Increase index when get '-'
    (*index)++;
    return -factor(str, index);
  }
  return 0; // error
}

/* Parse the string and handle if the character is multiplication*/
float term(char *str, int *index){
  float result = factor(str, index);
  while (get(str, index) == '*' || get(str, index) == '/'){
    if (get(str, index) == '*'){
      (*index)++;
      result *= factor(str, index);
    }
    else{
      (*index)++;
      result /= factor(str, index);
    }
  }
  return result;
}

/* Parse the string and handle if the character is addition*/
float expression(char *str, int *index){
  float result = term(str, index);
  while (get(str, index) == '+' || get(str, index) == '-'){
    if (get(str, index) == '+'){
      (*index)++;
      result += term(str, index);
    }
    else{
      (*index)++;
      result -= term(str, index);
    }
  }
  return result;
}
