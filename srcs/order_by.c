#include "../includes/push_swap.h"

void  order_by(t_list **stack_a, t_list **stack_b, t_list **moves)
{
  int size;

  size = ft_lstsize(*stack_a);
  // printf("size. %d\n", size);
  if (size == 2)
  {
    swap(stack_a);
    ft_stack(moves, "sa\n");
  }
  else if (size == 3)
    tiny_sort(stack_a, moves);
  else
    sort_stacks(stack_a, stack_b, moves);
}
