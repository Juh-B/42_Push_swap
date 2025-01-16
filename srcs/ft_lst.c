#include "../includes/push_swap.h"

t_stack	*ft_lst_last(t_stack *stack)
{
	t_stack	*p;

	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->next == NULL)
			p = stack;
		stack = stack->next;
	}
	return (p);
}

int	ft_lst_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
