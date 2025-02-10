/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:46:09 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/01/29 12:47:09 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	verif_number(const char *str)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	number *= sign;
	if (str[i] == '\0' && (number >= -2147483648 && number <= 2147483647))
		return (1);
	else
		return (0);
}

static char	**ft_argv(char **argv)
{
	char	*new_argv;

	new_argv = ft_strjoin("0 ", argv[1]);
	argv = ft_split(new_argv, ' ');
	free(new_argv);
	return (argv);
}

int	ft_stack(int argc, char **argv, t_stack **stack_a)
{
	int	i;
	int	*value;

	if (argc == 2)
		argv = ft_argv(argv);
	i = 1;
	while (argv[i])
	{
		if (verif_number(argv[i]))
		{
			value = malloc(sizeof(int));
			if (!value)
			{
				ft_free(*stack_a);
				return (1);
			}
			*value = ft_atoi(argv[i]);
			create_stack(stack_a, value);
		}
		else
			return (1);
		i++;
	}
	return (2);
}
