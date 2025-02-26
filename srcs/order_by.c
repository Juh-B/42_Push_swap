/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_by.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:50:20 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/26 11:09:29 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	order_by(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lst_size(*stack_a);
	if (size == 2)
		swap_stack(stack_a, 'a');
	else if (size == 3)
		tiny_sort(stack_a);
	else
		sort_stacks(stack_a, stack_b);
}
