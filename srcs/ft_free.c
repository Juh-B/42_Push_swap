/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:43:33 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/01/29 15:21:00 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
