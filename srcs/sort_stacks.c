#include "../includes/push_swap.h"

static void  order_final_stack(t_stack **stack_a, t_stack **lst)
{
  long  times;
  t_stack  *position;

  mov_cost(*stack_a, 'a');
  position = find_lowest(*stack_a);
  times = position->mov_a;
  while (times > 0)
  {
    if (position->type_mov_a == 'u')
    {
      rotate(stack_a);
      ft_stack(lst, "ra\n");
    }
    else
    {
      rotate_rev(stack_a);
      ft_stack(lst, "rra\n");
    }
    times--;
  }
}

void  sort_stacks(t_stack **stack_a, t_stack **stack_b, t_stack **lst)
{
  t_stack *node_a;
  t_stack *node_b;
  long  size;

  node_a = NULL;
  node_b = NULL;
  push(stack_a, stack_b);
  push(stack_a, stack_b);
  ft_stack(lst, "pb\n");
  ft_stack(lst, "pb\n");
  while (ft_lst_size(*stack_a) > 3)
  {
    node_a = calc_cost(*stack_a, *stack_b, 'a', 'b');
    node_b = fit_in_b(node_a, *stack_b);
    ft_move(stack_a, stack_b, node_a, node_b, lst); //arq mov_stack
    push(stack_a, stack_b);
    ft_stack(lst, "pb\n");
  }
  tiny_sort(stack_a, lst);
  size = ft_lst_size(*stack_b);
  while (size > 0)
  {
    node_b = calc_cost(*stack_b, *stack_a, 'b', 'a');
    node_a = fit_in_a(node_b, *stack_a);
    ft_move(stack_a, stack_b, node_a, node_b, lst);
    push(stack_b, stack_a);
    ft_stack(lst, "pa\n");
    size--;
  }
  order_final_stack(stack_a, lst);
}
