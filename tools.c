#include "cpv1.h"

t_pol get_pol(char *operation)
{
  t_pol pol;
  int i;

  pol.num = atoi(operation);
  i = 1;
  while (isdigit(operation[i]))
    i++;
  pol.op = DIV;
  if (operation[i] == '*')
    pol.op = MULT;
  pol.deg = operation[i + 3] - 48;
  return (pol);
}

int get_next_signe(char *operation)
{
  int i;

  i = 0;
  while (operation[i] && operation[i] != '+' && operation[i] != '-'
	 && operation[i] != '=')
    i++;
  return (i);
}

void get_opr(t_opr *sides, char *operation)
{
  int nb;
  int i;

  nb = 0;
  i = 0;
  while (operation[i] != '=')
    {
      sides->left[nb] = get_pol(operation + i);
      i += get_next_signe(operation + i);
      nb++;
    }
  nb = 0;
  i++;
  while (operation[i])
    {
      sides->right[nb] = get_pol(operation + i);
      i += get_next_signe(operation + i);
      nb++;
    }
}

int main(int ac, char **av)
{
  t_pol pol;

  pol = get_pol(av[1]);
  printf("num : %d deg : %d op : %d\n", pol.num, pol.deg, pol.op);
}
