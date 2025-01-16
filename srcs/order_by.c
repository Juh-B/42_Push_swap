#include "../includes/push_swap.h"

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

void  order_by(t_stack **stack_a, t_stack **stack_b, t_stack **moves)
{
  int size;

  size = ft_lst_size(*stack_a);
  printf("size. %d\n", size);
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
