/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:49:05 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/01/29 12:49:58 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	push(t_stack **stack_orig, t_stack **stack_dest)
{
	t_stack	*orig;
	t_stack	*sec_orig;
	t_stack	*dest;


	if (stack_orig == NULL)
		return ;
	dest = *stack_dest;
	orig = *stack_orig;
	sec_orig = orig->next;
	orig->next = dest;
	*stack_orig = sec_orig;
	*stack_dest = orig;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	last = ft_lst_last(*stack);
	first->next = NULL;
	last->next = first;
	*stack = second;
}

void	rotate_rev(t_stack **stack)
{
	t_stack	*before_last;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
