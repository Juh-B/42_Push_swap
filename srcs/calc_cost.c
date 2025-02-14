/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:37:38 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/01/29 15:19:05 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	type_mov(t_stack *stack, int size, char c)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (i <= size / 2)
		{
			if (c == 'a')
				stack->type_mov_a = 'u';
			else
				stack->type_mov_b = 'u';
		}
		else
		{
			if (c == 'a')
				stack->type_mov_a = 'd';
			else
				stack->type_mov_b = 'd';
		}
		i++;
		stack = stack->next;
	}
}

void	mov_cost(t_stack *stack, char c)
{
	int	size;
	int	cost;
	int	i;

	size = ft_lst_size(stack);
	cost = 0;
	i = 1;
	type_mov(stack, size, c);
	while (stack)
	{
		if (c == 'a')
			stack->mov_a = cost;
		else
			stack->mov_b = cost;
		if ((i <= size / 2))
			cost++;
		else if (!((i <= (size / 2 + 1)) && (size % 2 != 0)))
			cost--;
		stack = stack->next;
		i++;
	}
}

static long	mov_total(t_stack *stack_a, t_stack *stack_b)
{
	long	total;

	total = 0;
	if (stack_a->type_mov_a == stack_b->type_mov_b)
	{
		if (stack_a->mov_a >= stack_b->mov_b)
			total = stack_a->mov_a;
		else
			total = stack_b->mov_b;
	}
	else
		total = stack_a->mov_a + stack_b->mov_b;
	return (total);
}

static long total_cost(t_stack *s_orig, t_stack *s_dest, char orig)
{
  long  total;
  t_stack	*fit_in;

  total = 1;
  if (orig == 'a')
  {
    fit_in = fit_in_b(s_orig, s_dest);
    total += mov_total(s_orig, fit_in);
  }
  else
  {
    fit_in = fit_in_a(s_orig, s_dest);
    total += mov_total(fit_in, s_orig);
  }
  return (total);
}

t_stack	*calc_cost(t_stack *s_orig, t_stack *s_dest, char orig, char dest)
{
	long	total;
	long	lowest_total;
	t_stack	*lowest_cost;

	mov_cost(s_orig, orig);
	mov_cost(s_dest, dest);
	lowest_total = 100000;
	while (s_orig)
	{
		total = total_cost(s_orig, s_dest, orig);
    if (lowest_total > total)
		{
			lowest_total = total;
			lowest_cost = s_orig;
		}
		s_orig = s_orig->next;
	}
	return (lowest_cost);
}
