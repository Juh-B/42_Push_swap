#include "../includes/push_swap.h"

t_stack	*ft_lst_last(t_stack *lst)
{
	t_stack	*p;

	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			p = lst;
		lst = lst->next;
	}
	return (p);
}

int	ft_lst_size(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
