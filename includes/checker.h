/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:37 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/26 11:39:59 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	void			*content;
	struct s_stack	*next;
}	t_stack;

int		verif_args(int argc, char **argv, t_stack **stack_a);
int		verif_stack(int argc, char **argv, t_stack **stack_a);
int		verif_order(t_stack *stack);

int		get_command(t_stack **stack_a, t_stack **stack_b);
void	create_stack(t_stack **stack, void *content);
t_stack	*ft_lst_last(t_stack *stack);

void	ft_free(t_stack *stack);
void	ft_free_all(t_stack *stack_a, t_stack *stack_b);

void	swap(t_stack **stack);
void	swap_stack(t_stack **stack_a, t_stack **stack_b, char *cmd);
void	push(t_stack **stack_orig, t_stack **stack_dest);
void	push_stack(t_stack **stack_a, t_stack **stack_b, char *cmd);
void	rotate(t_stack **stack);
void	rotate_stack(t_stack **stack_a, t_stack **stack_b, char *cmd);
void	rotate_rev(t_stack **stack);
void	rotate_rev_stack(t_stack **stack_a, t_stack **stack_b, char *cmd);

#endif