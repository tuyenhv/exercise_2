#ifndef __PARSING_EXPRESSION_H
#define __PARSING_EXPRESSION_H

#define MAX_LEN 100
#define MAX_FLOAT_LEN 40

void remove_spaces(char *str);
char get(char *str, int *index);
float number(char *str, int *index);
float factor(char *str, int *index);
float term(char *str, int *index);
float expression(char *str, int *index);

#endif
