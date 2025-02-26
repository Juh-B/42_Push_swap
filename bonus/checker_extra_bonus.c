/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_extra_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:16:58 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/26 12:49:30 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

void	ft_free(t_stack *stack)
{
	t_stack	*temp;

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

void	ft_free_all(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		ft_free(stack_a);
	if (stack_b)
		ft_free(stack_b);
}
