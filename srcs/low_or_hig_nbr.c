#include "../includes/push_swap.h"

t_stack	*find_highest(t_stack *stack)
{
	int				numb;
	t_stack	*highest;

	if (NULL == stack)
		return (NULL);
	numb = -2147483648;
	while (stack)
	{
		if (*(int *)stack->content > numb)
		{
			numb = *(int *)stack->content;
			highest = stack;
		}
		stack = stack->next;
	}
	return (highest);
}

t_stack	*find_lowest(t_stack *stack)
{
	int				numb;
	t_stack	*lowest;

	if (NULL == stack)
		return (NULL);
	numb = 2147483647;
	while (stack)
	{
		if (*(int *)stack->content < numb)
		{
			numb = *(int *)stack->content;
			lowest = stack;
		}
		stack = stack->next;
	}
	return (lowest);
}
