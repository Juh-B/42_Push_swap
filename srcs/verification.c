/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:53:45 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/10 11:51:13 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	verify(t_stack *stack, char type)
{
	int		numb;
	t_stack	*temp;

	numb = 0;
	while (stack)
	{
		numb = *(int *)stack->content;
		temp = stack;
		if (stack->next != NULL)
		{
			temp = temp->next;
			while (temp)
			{
				if (type == 'd' && numb == *(int *)temp->content)
					return (1);
				else if (type == 'o' && numb > *(int *)temp->content)
					return (1);
				temp = temp->next;
			}
		}
		stack = stack->next;
	}
	return (0);
}

static int	verif_order_and_double(t_stack *stack)
{
	if (verify(stack, 'd'))
	{
		ft_free(stack);
		ft_printf("You have duplicate numbers on your stack.\n");
		return (1);
	}
	if (!verify(stack, 'o'))
	{
		ft_free(stack);
		return (0);
	}
	return (2);
}

static int	ft_error(void)
{
	ft_printf("Error\n");
	return (1);
}

int	verifications(int argc, char **argv, t_stack **stack_a)
{
	int	verif_param;
	int	verif_stack;

	if (argc == 1)
		return (0);
	else if (argc == 2 && !argv[1][0])
		return (ft_error());
	verif_stack = ft_stack(argc, argv, stack_a);
	if (verif_stack == 1)
		return (ft_error());
	verif_param = verif_order_and_double(*stack_a);
	if (verif_param == 0)
		return (0);
	else if (verif_param == 1)
		return (ft_error());
	return (2);
}
