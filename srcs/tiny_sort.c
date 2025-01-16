#include "../includes/push_swap.h"

void  tiny_sort(t_stack **stack, t_stack **lst)
{
	t_stack	*highest;

	highest = find_highest(*stack);
	if (*stack == highest)
  {
		rotate(stack);
    ft_stack(lst, "ra\n");
  }
	else if ((*stack)->next == highest)
  {
    rotate_rev(stack);
    ft_stack(lst, "rra\n");
  }
	if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
  {
		swap(stack);
    ft_stack(lst, "sa\n");
  }
}
