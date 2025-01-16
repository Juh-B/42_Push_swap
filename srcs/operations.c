#include "../includes/push_swap.h"

void swap(t_list **stack)
{
  t_list *first;
  t_list *second;

  if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    return ;
  first = *stack;
  second = first->next;
  first->next = second->next;
  second->next = first;
  *stack = second;
}

void  push(t_list **stack_orig, t_list **stack_dest)
{
  t_list *orig;
  t_list *sec_orig;
  t_list *dest;


  if (stack_orig == NULL)
    return ;
  dest = *stack_dest;
  orig = *stack_orig;
  sec_orig = orig->next;
  orig->next = dest;
  *stack_orig = sec_orig;
  *stack_dest = orig;
}

void rotate(t_list **stack)
{
  t_list *first;
  t_list *second;
  t_list *last;

  if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    return ;
  first = *stack;
  second = first->next;
  last = ft_lstlast(*stack);
  first->next = NULL;
  last->next = first;
  *stack = second;
}

void rotate_rev(t_list **stack)
{
  t_list *before_last;
  t_list *last;

  if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    return ;
  last = *stack;
  while (last->next)
  {
    before_last = last;
    last = last->next;
  }
  before_last->next = NULL;
  last->next = *stack;
  *stack = last;
}
