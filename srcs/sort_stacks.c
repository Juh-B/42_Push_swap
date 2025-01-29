/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:51:53 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/01/29 15:19:54 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	order_final_stack(t_stack **stack_a)
{
	long	times;
	t_stack	*position;

	mov_cost(*stack_a, 'a');
	position = find_lowest(*stack_a);
	times = position->mov_a;
	while (times > 0)
	{
		if (position->type_mov_a == 'u')
			rotate_stack(stack_a, 'a');
		else
			rotate_rev_stack(stack_a, 'a');
		times--;
	}
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_a;
	t_stack	*node_b;

	node_a = NULL;
	node_b = NULL;
	push_stack(stack_a, stack_b, 'b');
	push_stack(stack_a, stack_b, 'b');
	while (ft_lst_size(*stack_a) > 3)
	{
		node_a = calc_cost(*stack_a, *stack_b, 'a', 'b');
		node_b = fit_in_b(node_a, *stack_b);
		ft_rot(stack_a, stack_b, node_a, node_b);
		push_stack(stack_a, stack_b, 'b');
	}
	tiny_sort(stack_a);
	while (ft_lst_size(*stack_b) > 0)
	{
		node_b = calc_cost(*stack_b, *stack_a, 'b', 'a');
		node_a = fit_in_a(node_b, *stack_a);
		ft_rot(stack_a, stack_b, node_a, node_b);
		push_stack(stack_b, stack_a, 'a');
	}
	order_final_stack(stack_a);
}
