/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:48:12 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/01/29 12:48:51 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_stack(t_stack **stack, char dest)
{
	swap(stack);
	if (dest == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	push_stack(t_stack **stack_orig, t_stack **stack_dest, char dest)
{
	push(stack_orig, stack_dest);
	if (dest == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	rotate_stack(t_stack **stack, char dest)
{
	rotate(stack);
	if (dest == 'a')
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	rotate_rev_stack(t_stack **stack, char dest)
{
	rotate_rev(stack);
	if (dest == 'a')
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}

void	rotate_both_stacks(t_stack **stack_a, t_stack **stack_b, char mov)
{
	if (mov == 'u')
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
	else
	{
		rotate_rev(stack_a);
		rotate_rev(stack_b);
		ft_printf("rrr\n");
	}
}
