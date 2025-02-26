/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:19:37 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/26 13:56:25 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	push_stack(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (cmd[1] == 'a')
		push(stack_b, stack_a);
	else
		push(stack_a, stack_b);
}

void	swap_stack(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (cmd[1] == 'a')
		swap(stack_a);
	else if (cmd[1] == 'b')
		swap(stack_b);
	else
	{
		swap(stack_a);
		swap(stack_b);
	}
}

void	rotate_stack(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (cmd[1] == 'a')
		rotate(stack_a);
	else if (cmd[1] == 'b')
		rotate(stack_b);
	else
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}

void	rotate_rev_stack(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (cmd[2] == 'a')
		rotate_rev(stack_a);
	else if (cmd[2] == 'b')
		rotate_rev(stack_b);
	else
	{
		rotate_rev(stack_a);
		rotate_rev(stack_b);
	}
}
