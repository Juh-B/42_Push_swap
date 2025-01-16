#include "../includes/push_swap.h"

static void  type_mov(t_stack *stack, int size, char c)
{
  int i;

  i = 0;
  while (stack)
  {
    if (i <= size / 2)
    {
      if (c == 'a')
        stack->type_mov_a = 'u';
      else
        stack->type_mov_b = 'u';
    }
    else
    {
      if (c == 'a')
        stack->type_mov_a = 'd';
      else
        stack->type_mov_b = 'd';
    }
    i++;
    stack = stack->next;
  }
}

void  mov_cost(t_stack *stack, char c)
{
  int size;
  int cost;
  int i;

  size = ft_lst_size(stack);
  cost = 0;
  i = 1;
  type_mov(stack, size, c);
  while (stack)
  {
    if (c == 'a')
      stack->mov_a = cost;
    else
      stack->mov_b = cost;
    if ((i <= size / 2))
      cost++;
    else if ((i <= (size / 2 + 1)) && (size % 2 != 0))
      cost = cost;
    else
      cost--;
    stack = stack->next;
    i++;
  }
}
