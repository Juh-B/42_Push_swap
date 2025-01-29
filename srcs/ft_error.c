/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:42:58 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/01/29 13:08:54 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_error(int type)
{
	if (type == 1)
	{
		ft_printf("Invalid number of args\n");
		return (0);
	}
	else if (type == 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
