#include "../includes/push_swap.h"

// PROTOTIPADA (MAS TALVEx possa ser static da calc cost)
long  mov_total(t_list *stack_a, t_list *stack_b)
{
  long  total;

  total = 0;
  if (stack_a->type_mov_a == stack_b->type_mov_b)
  {
    if (stack_a->mov_a >= stack_b->mov_b)
      total = stack_a->mov_a;
    else
      total = stack_b->mov_b;
  }
  else
    total = stack_a->mov_a + stack_b->mov_b;
  return (total);
}
