/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:40:07 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/26 11:04:17 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*initialize_node(void *content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->mov_a = 0;
	new_node->mov_b = 0;
	new_node->type_mov_a = '\0';
	new_node->type_mov_b = '\0';
	return (new_node);
}

static void	node_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	create_stack(t_stack **stack, void *content)
{
	t_stack	*new_node;

	new_node = initialize_node(content);
	if (!new_node)
		return ;
	node_add_back(stack, new_node);
}
