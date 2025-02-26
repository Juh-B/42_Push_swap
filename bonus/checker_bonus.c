/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:50:50 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/26 13:57:08 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		code;

	stack_a = NULL;
	stack_b = NULL;
	code = verif_args(argc, argv, &stack_a);
	if (code != 2)
	{
		if (code == 1)
			ft_printf("Error\n");
		if (stack_a != NULL)
			ft_free(stack_a);
		return (code);
	}
	if (get_command(&stack_a, &stack_b))
		return (1);
	if (verif_order(stack_a) && stack_b == NULL)
		ft_printf("Ok\n");
	else
		ft_printf("KO\n");
	ft_free_all(stack_a, stack_b);
	return (0);
}
