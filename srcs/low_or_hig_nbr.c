#include "../includes/push_swap.h"

t_list	*find_highest(t_list *stack)
{
	int				numb;
	t_list	*highest;

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

t_list	*find_lowest(t_list *stack)
{
	int				numb;
	t_list	*lowest;

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
