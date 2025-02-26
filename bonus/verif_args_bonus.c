/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:21:01 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/26 12:49:12 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	verif_order(t_stack *stack)
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
				if (numb > *(int *)temp->content)
					return (0);
				temp = temp->next;
			}
		}
		stack = stack->next;
	}
	return (1);
}

static int	verif_double(t_stack *stack)
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
				if (numb == *(int *)temp->content)
					return (1);
				temp = temp->next;
			}
		}
		stack = stack->next;
	}
	return (0);
}

int	verif_args(int argc, char **argv, t_stack **stack_a)
{
	int	v_stack;

	if (argc == 1)
		return (0);
	else if (argc == 2 && !argv[1][0])
		return (1);
	else
		v_stack = verif_stack(argc, argv, stack_a);
	if (v_stack == 1)
		return (1);
	if (verif_double(*stack_a))
		return (1);
	return (2);
}
