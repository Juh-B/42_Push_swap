/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:41:27 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/01/29 12:42:42 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

static	t_stack *extreme_nbr(t_stack *stack, char c)
{
	int		nbr;
	t_stack	*place;

	if (c == 'a')
		nbr = 2147483647;
	else
		nbr = -2147483648;
	while (stack)
	{
		if (c == 'a' && *(int *)stack->content < nbr)
		{
			nbr = *(int *)stack->content;
			place = stack;
		}
		else if (c == 'b' && *(int *)stack->content >= nbr)
		{
			nbr = *(int *)stack->content;
			place = stack;
		}
		stack = stack->next;
	}
	return (place);
}

t_stack	*fit_in_b(t_stack *node_a, t_stack *stack_b)
{
	int		nbr;
	int		s_content;
	t_stack	*place;
	t_stack	*stack;

	place = NULL;
	stack = stack_b;
	nbr = -2147483648;
	while (stack)
	{
		s_content = *(int *)stack->content;
		if (*(int *)node_a->content > s_content && nbr < s_content)
		{
			nbr = s_content;
			place = stack;
		}
		stack = stack->next;
	}
	if (!place)
		place = extreme_nbr(stack_b, 'b');
	return (place);
}

t_stack	*fit_in_a(t_stack *node_b, t_stack *stack_a)
{
	int		nbr;
	int		s_content;
	t_stack	*place;
	t_stack	*stack;

	place = NULL;
	stack = stack_a;
	nbr = 2147483647;
	while (stack)
	{
		s_content = *(int *)stack->content;
		if (*(int *)node_b->content < s_content && nbr > s_content)
		{
			nbr = s_content;
			place = stack;
		}
		stack = stack->next;
	}
	if (!place)
		place = extreme_nbr(stack_a, 'a');
	return (place);
}
