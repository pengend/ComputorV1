#ifndef CPV1_H
# define CPV1_H
# define MAX_POL 3
# define MULT 0b00000001
# define DIV 0b00000010

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct s_pol
{
  int num;
  int deg;
  int op;
}		t_pol;

typedef struct s_opr
{
  t_pol left[MAX_POL];
  t_pol right[MAX_POL];
}		t_opr;
#endif
