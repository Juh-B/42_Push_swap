/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:37 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/01/29 15:23:50 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	void			*content;
	long			mov_a;
	long			mov_b;
	char			type_mov_a;
	char			type_mov_b;
	struct s_stack	*next;
}	t_stack;

int		ft_stack(int argc, char **argv, t_stack **stack_a);
int		ft_lst_size(t_stack *stack);
int		verifications(int argc, char **argv, t_stack **stack_a);

void	create_stack(t_stack **stack, void *content);
void	ft_free(t_stack *stack);
void	ft_rot(t_stack **st_a, t_stack **st_b, t_stack *n_a, t_stack *n_b);
void	mov_cost(t_stack *stack, char c);
void	order_by(t_stack **stack_a, t_stack **stack_b);
void	sort_stacks(t_stack **stack_a, t_stack **stack_b);
void	tiny_sort(t_stack **stack);

void	swap(t_stack **stack);
void	swap_stack(t_stack **stack, char dest);
void	push(t_stack **stack_orig, t_stack **stack_dest);
void	push_stack(t_stack **stack_orig, t_stack **stack_dest, char dest);
void	rotate(t_stack **stack);
void	rotate_stack(t_stack **stack, char dest);
void	rotate_rev(t_stack **stack);
void	rotate_rev_stack(t_stack **stack, char dest);
void	rotate_both_stacks(t_stack **stack_a, t_stack **stack_b, char mov);

t_stack	*calc_cost(t_stack *s_orig, t_stack *s_dest, char orig, char dest);
t_stack	*find_lowest(t_stack *stack);
t_stack	*find_highest(t_stack *stack);
t_stack	*fit_in_a(t_stack *node_b, t_stack *stack_a);
t_stack	*fit_in_b(t_stack *node_a, t_stack *stack_b);
t_stack	*ft_lst_last(t_stack *stack);

#endif
