#include "../includes/push_swap.h"

void  tiny_sort(t_stack **stack)
{
	t_stack	*highest;

	highest = find_highest(*stack);
	if (*stack == highest)
    rotate_stack(stack, 'a');
	else if ((*stack)->next == highest)
    rotate_rev_stack(stack, 'a');
	if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
    swap_stack(stack, 'a');
}
