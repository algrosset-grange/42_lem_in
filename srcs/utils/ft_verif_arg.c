/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:14:30 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 13:21:58 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_verif_arg(int nb_elem, char **av, int is_one)
{
	int a;
	int b;

	a = 2 - is_one;
	while (a <= (nb_elem - is_one))
	{
		b = 1 - is_one;
		if (ft_is_integer(av[b]) || ft_is_integer(av[a]))
		{
			return (1);
		}
		while (b < a)
		{
			if (!ft_strcmp(av[a], av[b]))
				return (1);
			b++;
		}
		a++;
	}
	return (0);
}
