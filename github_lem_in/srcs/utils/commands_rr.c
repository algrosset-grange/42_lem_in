/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:14:30 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 13:21:58 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int	ft_comm_rra(t_piles *piles)
{
	int				a;
	unsigned int	b;

	if (piles->col_a_nb_element <= 1)
		return (NO_ERROR);
	b = piles->nb_elem_total - 1;
	while (b > piles->col_a_pos_first_elem)
	{
		a = piles->col_ui_a[b];
		piles->col_ui_a[b] = piles->col_ui_a[b - 1];
		piles->col_ui_a[b - 1] = a;
		b--;
	}
	return (NO_ERROR);
}

int	ft_comm_rrb(t_piles *piles)
{
	int				a;
	unsigned int	b;

	if (piles->col_b_nb_element <= 1)
		return (NO_ERROR);
	b = piles->nb_elem_total - 1;
	while (b > piles->col_b_pos_first_elem)
	{
		a = piles->col_ui_b[b];
		piles->col_ui_b[b] = piles->col_ui_b[b - 1];
		piles->col_ui_b[b - 1] = a;
		b--;
	}
	return (NO_ERROR);
}

int	ft_comm_rrr(t_piles *piles)
{
	ft_comm_rra(piles);
	ft_comm_rrb(piles);
	return (NO_ERROR);
}
