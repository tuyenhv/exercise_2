#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

char * str = "3+2.5+3.5";

char peek(char *str){
  return *str;
}

float expression(char *str);

float number(char *str){
  char str_value[50];
  int i = 0;
  while ((peek(str) >= '0' && peek(str) <= '9') || peek(str) == '.'){
    str_value[i] = peek(str);
    str++;
    i++;
  }
  return atof(str_value);
}

float factor(char *str){
  if (peek(str) >= '0' && peek(str) <= '9')
    return number(str);
  else if (peek(str) == '('){
    peek(str); // '('
    str++;
    float result = expression(str);
    peek(str); // ')'
    str++;
    return result;
  }
  else if (peek(str) == '-'){
    peek(str);
    str++;
    return -factor(str);
  }
  return 0; // error
}

float term(char *str){
  float result = factor(str);
  while (peek(str) == '*' || peek(str) == '/'){
    if (peek(str) == '*'){
      str++;
      result *= factor(str);
    }
    else{
      str++;
      result /= factor(str);
    }
  }
  return result;
}

float expression(char *str){
  float result = term(str);
  while (peek(str) == '+' || peek(str) == '-'){
    if (peek(str) == '+'){
      str++;
      result += term(str);
    }
    else{
      str++;
      result -= term(str);
    }
  }
  return result;
}

int main(void)
{
  float result = expression(str);
  printf("result: %f \n", result);
  return 0;
}
