/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:14:30 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 13:21:58 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_comm_sa(t_piles *piles)
{
	int a;

	if (piles->col_a_nb_element <= 1)
		return (NO_ERROR);
	a = piles->col_ui_a[piles->col_a_pos_first_elem];
	piles->col_ui_a[piles->col_a_pos_first_elem] =
		piles->col_ui_a[piles->col_a_pos_first_elem + 1];
	piles->col_ui_a[piles->col_a_pos_first_elem + 1] = a;
	return (NO_ERROR);
}

int	ft_comm_sb(t_piles *piles)
{
	int a;

	if (piles->col_b_nb_element <= 1)
		return (NO_ERROR);
	a = piles->col_ui_b[piles->col_b_pos_first_elem];
	piles->col_ui_b[piles->col_b_pos_first_elem] =
		piles->col_ui_b[piles->col_b_pos_first_elem + 1];
	piles->col_ui_b[piles->col_b_pos_first_elem + 1] = a;
	return (NO_ERROR);
}

int	ft_comm_ss(t_piles *piles)
{
	ft_comm_sa(piles);
	ft_comm_sb(piles);
	return (NO_ERROR);
}
