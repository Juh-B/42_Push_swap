#include "../includes/push_swap.h"

void ft_free(t_list *stack)
{
  t_list *temp;

	if (stack == NULL)
		return ;
  while (stack)
  {
    temp = stack->next;
    free(stack->content);
    free(stack);
    stack = temp;
  }
}
