#include "../includes/push_swap.h"

int ft_error(int type)
{
  if (type == 1)
  {
    printf("Invalid number of args\n");
    return (0);
  }
  else if (type == 2)
  {
    printf("Error\n");
    return (1);
  }
  return (0);
}
