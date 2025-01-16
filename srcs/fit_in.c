
#include "../includes/push_swap.h"

t_stack *fit_in_b(t_stack *node_a, t_stack *stack_b)
{
  int nbr;
  t_stack *place;
  t_stack *stack;

  place = NULL;
  stack = stack_b;
  nbr = -2147483648;
  while (stack)
  {
    if (*(int *)node_a->content > *(int *)stack->content && nbr < *(int *)stack->content)
    {
      nbr = *(int *)stack->content;
      place = stack;
    }
    stack = stack->next;
  }
  if (!place)
  {
    while (stack_b)
    {
      if (*(int *)stack_b->content >= nbr)
      {
        nbr = *(int *)stack_b->content;
        place = stack_b;
      }
      stack_b = stack_b->next;
    }
  }
  return (place);
}

t_stack *fit_in_a(t_stack *node_b, t_stack *stack_a)
{
  int nbr;
  t_stack *place;
  t_stack *stack;

  place = NULL;
  stack = stack_a;
  nbr = 2147483647;
  while (stack)
  {
    if (*(int *)node_b->content < *(int *)stack->content && nbr > *(int *)stack->content)
    {
      nbr = *(int *)stack->content;
      place = stack;
    }
    stack = stack->next;
  }
  if (!place)
  {
    nbr = 2147483647;
    while (stack_a)
    {
      if (*(int *)stack_a->content < nbr)
      {
        nbr = *(int *)stack_a->content;
        place = stack_a;
      }
      stack_a = stack_a->next;
    }
  }
  return (place);
}
