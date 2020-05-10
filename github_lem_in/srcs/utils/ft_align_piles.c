/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_piles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:57:55 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 12:43:54 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

/*
**	avec l'alignement, la valeur la plus petite est 0
**	la valeur la plus grande est donc (nombre d'element - 1)
** |
**	pour	1 2 3 4 6 5
**	donne	0 1 2 3 5 4
*/

int	ft_align_piles(t_piles *piles)
{
	unsigned int	a;
	unsigned int	b;

	a = 0;
	while (a < piles->nb_elem_total)
	{
		b = 0;
		piles->col_ui_a[a] = 0;
		piles->col_ui_b[a] = 0;
		while (b < piles->nb_elem_total)
			if (piles->col_i_a[a] > piles->col_i_a[b++])
				piles->col_ui_a[a]++;
		a++;
	}
	return (0);
}
