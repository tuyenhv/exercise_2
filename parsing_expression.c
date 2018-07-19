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
  float result = expression(str, &index);
  printf("result: %f \n", result);
  return 0;
}

char get(char *str, int *index){
  return *(str + (*index));
}

float number(char *str, int *index){
  char str_value[50];
  int i = 0;
  while ((get(str, index) >= '0' && get(str, index) <= '9') || get(str, index) == '.'){
    str_value[i] = get(str, index);
    (*index)++;
    i++;
  }
  return atof(str_value);
}

float factor(char *str, int *index){
  if (get(str, index) >= '0' && get(str, index) <= '9')
    return number(str, index);
  else if (get(str, index) == '('){
    get(str, index); // '('
    (*index)++;
    float result = expression(str, index);
    get(str, index); // ')'
    (*index)++;
    return result;
  }
  else if (get(str, index) == '-'){
    get(str, index);
    (*index)++;
    return -factor(str, index);
  }
  return 0; // error
}

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
