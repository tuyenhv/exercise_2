#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

const char * expressionToParse = "3*(2.5+3.5)";

char peek(){
  return *expressionToParse;
}

char get(){
  return *expressionToParse++;
}

float expression();

float number(){
  char str_value[50];
  int i = 0;
  bool decimal_found = false;
  char c;
  while ((peek() >= '0' && peek() <= '9') || peek() == '.'){
    str_value[i] = get();
    i++;
  }
  return atof(str_value);
}

float factor(){
  if (peek() >= '0' && peek() <= '9')
    return number();
  else if (peek() == '('){
    get(); // '('
    float result = expression();
    get(); // ')'
    return result;
  }
  else if (peek() == '-'){
    get();
    return -factor();
  }
  return 0; // error
}

float term(){
  float result = factor();
  while (peek() == '*' || peek() == '/')
    if (get() == '*')
      result *= factor();
    else
      result /= factor();
  return result;
}

float expression(){
  float result = term();
  while (peek() == '+' || peek() == '-')
    if (get() == '+')
      result += term();
    else
      result -= term();
  return result;
}

int main(void)
{
  float result = expression();
  printf("result: %f \n", result);
  return 0;
}
