/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:21:55 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/26 16:42:58 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

static int	new_stack(char *argv, t_stack **stack_a)
{
	int	*value;

	value = malloc(sizeof(int));
	if (!value)
	{
		ft_free(*stack_a);
		return (1);
	}
	*value = ft_atoi(argv);
	create_stack(stack_a, value);
	return (0);
}

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	verif_stack(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	if (argc == 2)
		argv = ft_argv(argv);
	i = 1;
	while (argv[i])
	{
		if (verif_number(argv[i]))
		{
			if (new_stack(argv[i], stack_a))
				return (1);
		}
		else if (argc == 2)
		{
			free_array(argv);
			return (1);
		}
		else
			return (1);
		i++;
	}
	if (argc == 2)
		free_array(argv);
	return (2);
}
