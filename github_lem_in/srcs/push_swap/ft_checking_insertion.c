/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking_insertion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:57:55 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 12:43:54 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_checking_insertion_p2(t_piles *piles, unsigned int verif,
	unsigned int lower, unsigned int upper)
{
	if (lower == piles->col_b_elem_max && verif > lower)
		return (1);
	if (upper == piles->col_b_elem_min && verif < upper)
		return (1);
	if ((lower < verif) && (verif < upper))
		return (1);
	return (0);
}

/*
**	3 cas à voir
**	|
**	cas 1 x = première position :
**	je dois vérifier que le dernier élément est plus grand
**	sauf cas particulier : a est > max de b
**	ou < min de b
**	|
**	cas 2 :
**	on test le dernier élément. Donc il faut vérifier l'avant dernier
**	l'avant dernier doit donc être plus grand et l'actuel + petit
**	|
**	cas 3 : aucun extreme
**	l'actuel doit être plus petit et le précédent plus grand
*/

int			ft_checking_insertion(t_piles *piles, t_path_var *p_var)
{
	unsigned int	nu_col_a;
	unsigned int	nu_col_b;

	nu_col_a = p_var->test_nu_col_a;
	nu_col_b = p_var->test_nu_col_b;
	if ((!p_var->test_move_b && (ft_checking_insertion_p2(piles,
					piles->col_ui_a[nu_col_a],
					piles->col_ui_b[nu_col_b],
					piles->col_ui_b[piles->nb_elem_total - 1])))
		|| (p_var->test_move_b && (ft_checking_insertion_p2(piles,
					piles->col_ui_a[nu_col_a],
					piles->col_ui_b[nu_col_b],
					piles->col_ui_b[nu_col_b - 1]))))
		return (1);
	return (0);
}
