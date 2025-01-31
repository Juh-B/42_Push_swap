/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:53:45 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/01/29 13:26:35 by jcosta-b         ###   ########.fr       */
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
		ft_printf("Double\n");
		return (2);
	}
	if (!verify(stack, 'o'))
	{
		ft_free(stack);
		return (0);
	}
	return (3);
}

static int	verif_args(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	else if (argc == 2 && !argv[1][0])
		return (2);
	else
		return (3);
}

int	verifications(int argc, char **argv, t_stack **stack_a)
{
	int	verif_1;
	int	verif_2;
	int	verif_stack;

	verif_1 = verif_args(argc, argv);
	if (verif_1 != 3)
	{
		if (verif_1 == 1)
			return (1);
		else
			return (2);
	}
	verif_stack = ft_stack(argc, argv, stack_a);
	if (verif_stack == 2)
		return (2);
	verif_2 = verif_order_and_double(*stack_a);
	if (verif_2 != 3)
	{
		if (verif_2 == 2)
			return (2);
		else
			return (0);
	}
	return (3);
}
