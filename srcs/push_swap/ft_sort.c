/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:57:55 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 12:43:54 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_sort_antirot_b(t_piles *piles, t_path_var *p_var)
{
	p_var->test_move_b = 1;
	ft_set_test_move_total(p_var);
	while (p_var->test_move_total < p_var->shortest_total
		&& (piles->nb_elem_total - p_var->test_move_b
			> piles->col_b_pos_first_elem))
	{
		p_var->test_nu_col_b = piles->nb_elem_total - p_var->test_move_b;
		if (ft_checking_insertion(piles, p_var))
		{
			ft_set_test_move_total(p_var);
			if (p_var->test_move_total < p_var->shortest_total)
				ft_put_shortest(p_var);
		}
		p_var->test_move_b++;
		ft_set_test_move_total(p_var);
	}
}

static void	ft_sort_rot_b(t_piles *piles, t_path_var *p_var)
{
	p_var->test_move_b = 0;
	ft_set_test_move_total(p_var);
	while (p_var->test_move_total < p_var->shortest_total
		&& (p_var->test_move_b + piles->col_b_pos_first_elem)
			< piles->nb_elem_total)
	{
		p_var->test_nu_col_b = p_var->test_move_b + piles->col_b_pos_first_elem;
		if (ft_checking_insertion(piles, p_var))
		{
			ft_set_test_move_total(p_var);
			if (p_var->test_move_total < p_var->shortest_total)
			{
				ft_put_shortest(p_var);
			}
		}
		p_var->test_move_b++;
	}
}

static void	ft_sort_antirot_a(t_piles *piles, t_path_var *p_var)
{
	p_var->test_move_a = 1;
	while (p_var->test_move_a < p_var->shortest_total
		&& ((piles->nb_elem_total - p_var->test_move_a)
			> piles->col_a_pos_first_elem)
		&& (piles->col_a_nb_element != 1
			&& piles->col_ui_a[piles->col_a_pos_first_elem]
				!= piles->nb_elem_total))
	{
		p_var->test_nu_col_a = piles->nb_elem_total - p_var->test_move_a;
		p_var->ft_sort_b(piles, p_var);
		p_var->test_move_a++;
	}
}

static void	ft_sort_rot_a(t_piles *piles, t_path_var *p_var)
{
	p_var->test_move_a = 0;
	while (p_var->test_move_a < p_var->shortest_total
		&& ((p_var->test_move_a + piles->col_a_pos_first_elem)
			< piles->nb_elem_total))
	{
		p_var->test_nu_col_a = piles->col_a_pos_first_elem + p_var->test_move_a;
		p_var->ft_sort_b(piles, p_var);
		p_var->test_move_a++;
	}
}

void		ft_get_sort(t_piles *piles, t_path_var *path_var)
{
	path_var->test_rotate_a = HORAIRE;
	path_var->test_rotate_b = HORAIRE;
	path_var->is_good_rotate = 1;
	path_var->ft_sort_b = &ft_sort_rot_b;
	ft_sort_rot_a(piles, path_var);
	path_var->test_rotate_b = ANTIHORAIRE;
	path_var->is_good_rotate = 0;
	path_var->ft_sort_b = &ft_sort_antirot_b;
	ft_sort_rot_a(piles, path_var);
	path_var->test_rotate_a = ANTIHORAIRE;
	path_var->test_rotate_b = HORAIRE;
	path_var->ft_sort_b = &ft_sort_rot_b;
	ft_sort_antirot_a(piles, path_var);
	path_var->test_rotate_b = ANTIHORAIRE;
	path_var->is_good_rotate = 1;
	path_var->ft_sort_b = &ft_sort_antirot_b;
	ft_sort_antirot_a(piles, path_var);
}
