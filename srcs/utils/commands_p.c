/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:14:30 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 13:21:58 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int	ft_comm_pa(t_piles *piles)
{
	if (piles->col_b_nb_element == 0)
		return (NO_ERROR);
	piles->col_ui_a[piles->col_a_pos_first_elem - 1] =
		piles->col_ui_b[piles->col_b_pos_first_elem];
	piles->col_b_pos_first_elem++;
	piles->col_b_nb_element--;
	piles->col_a_pos_first_elem--;
	piles->col_a_nb_element++;
	return (NO_ERROR);
}

int	ft_comm_pb(t_piles *piles)
{
	if (piles->col_a_nb_element == 0)
		return (NO_ERROR);
	piles->col_ui_b[piles->col_b_pos_first_elem - 1] =
	piles->col_ui_a[piles->col_a_pos_first_elem];
	piles->col_b_pos_first_elem--;
	piles->col_b_nb_element++;
	piles->col_a_pos_first_elem++;
	piles->col_a_nb_element--;
	if (piles->col_ui_b[piles->col_b_pos_first_elem] > piles->col_b_elem_max)
		piles->col_b_elem_max = piles->col_ui_b[piles->col_b_pos_first_elem];
	if (piles->col_ui_b[piles->col_b_pos_first_elem] < piles->col_b_elem_min)
		piles->col_b_elem_min = piles->col_ui_b[piles->col_b_pos_first_elem];
	return (NO_ERROR);
}
