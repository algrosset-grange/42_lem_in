/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort_final.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:14:30 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 13:21:58 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_issort_final(t_piles *piles)
{
	unsigned int	a;

	if (piles->col_b_nb_element != 0)
		return (ft_answer(INT_MESSAGE_KO));
	a = 1;
	while (a < piles->nb_elem_total)
	{
		if (piles->col_ui_a[a - 1] > piles->col_ui_a[a])
			return (ft_answer(INT_MESSAGE_KO));
		a++;
	}
	return (ft_answer(INT_MESSAGE_OK));
}
