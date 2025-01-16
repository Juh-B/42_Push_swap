#include "../includes/push_swap.h"

void  ft_move(t_list **stack_a, t_list **stack_b, t_list *node_a, t_list *node_b, t_list **lst)
{
  long  both;
  long  only_a;
  long  only_b;

  both = 0;
  only_a = node_a->mov_a;
  only_b = node_b->mov_b;
  if (node_a->type_mov_a == node_b->type_mov_b)
  {
    if (node_a->mov_a <= node_b->mov_b)
    {
      both = node_a->mov_a;
      only_a = 0;
      only_b = node_b->mov_b - node_a->mov_a;
    }
    else
    {
      both = node_b->mov_b;
      only_a = node_a->mov_a - node_b->mov_b;
      only_b = 0;
    }
    if (node_a->type_mov_a == 'u')
    {
      while (both > 0)
      {
        rotate(stack_a);
        rotate(stack_b);
        ft_stack(lst, "rr\n");
        both--;
      }
    }
    else
    {
      while (both > 0)
      {
        rotate_rev(stack_a);
        rotate_rev(stack_b);
        ft_stack(lst, "rrr\n");
        both--;
      }
    }
  }
  while (only_a > 0)
  {
    if (node_a->type_mov_a == 'u')
    {
      rotate(stack_a);
      ft_stack(lst, "ra\n");
    }
    else
    {
      rotate_rev(stack_a);
      ft_stack(lst, "rra\n");
    }
    only_a--;
  }
  while (only_b > 0)
  {
    if (node_b->type_mov_b == 'u')
    {
      rotate(stack_b);
      ft_stack(lst, "rb\n");
    }
    else
    {
      rotate_rev(stack_b);
      ft_stack(lst, "rrb\n");
    }
    only_b--;
  }
}
