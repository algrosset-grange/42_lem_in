/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:14:30 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 13:21:58 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int	ft_comm_ra(t_piles *piles)
{
	int				a;
	unsigned int	c;

	if (piles->col_a_nb_element <= 1)
		return (NO_ERROR);
	c = piles->col_a_pos_first_elem;
	while (c < piles->nb_elem_total - 1)
	{
		a = piles->col_ui_a[c];
		piles->col_ui_a[c] = piles->col_ui_a[1 + c];
		piles->col_ui_a[1 + c] = a;
		c++;
	}
	return (NO_ERROR);
}

int	ft_comm_rb(t_piles *piles)
{
	int				a;
	unsigned int	c;

	if (piles->col_b_nb_element <= 1)
		return (NO_ERROR);
	c = piles->col_b_pos_first_elem;
	while (c < piles->nb_elem_total - 1)
	{
		a = piles->col_ui_b[c];
		piles->col_ui_b[c] = piles->col_ui_b[1 + c];
		piles->col_ui_b[1 + c] = a;
		c++;
	}
	return (NO_ERROR);
}

int	ft_comm_rr(t_piles *piles)
{
	ft_comm_ra(piles);
	ft_comm_rb(piles);
	return (NO_ERROR);
}
