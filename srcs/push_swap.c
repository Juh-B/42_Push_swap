/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:50:50 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/01/29 12:51:36 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		code;

	stack_a = NULL;
	stack_b = NULL;
	code = verifications(argc, argv, &stack_a);
	if (code != 2)
    return (code);
	order_by(&stack_a, &stack_b);

  // t_stack  *current;
  // current = stack_a;
  // ft_printf("\n... Stack...\n");
  // while (current)
  // {
  //   ft_printf("%d\n", *(int *)current->content);
  //   current = current->next;
  // }

	ft_free(stack_a);
	return (0);
}
