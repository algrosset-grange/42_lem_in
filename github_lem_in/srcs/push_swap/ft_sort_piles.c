/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_piles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:57:55 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 12:43:54 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void			ft_push_b(t_piles *piles)
{
	unsigned int a;

	a = 0;
	while (piles->col_ui_b[a] != 0)
		a++;
	if (a <= (piles->col_b_nb_element / 2))
		while (piles->col_ui_b[piles->nb_elem_total - 1] != 0)
			ft_do_command(piles, "rb\n", RB);
	else
		while (piles->col_ui_b[piles->nb_elem_total - 1] != 0)
			ft_do_command(piles, "rrb\n", RRB);
	while (piles->col_b_nb_element)
		ft_do_command(piles, "pa\n", PA);
}

static void			ft_sort_end_a(t_piles *piles)
{
	unsigned int	a;
	unsigned int	moy;

	if (!piles->col_a_nb_element)
		return ;
	a = piles->col_a_pos_first_elem;
	while (piles->col_ui_a[a] != piles->nb_elem_total - 1)
		a++;
	moy = piles->col_a_pos_first_elem
		+ (piles->nb_elem_total - piles->col_a_pos_first_elem) / 2;
	if (a < moy)
		while (piles->col_ui_a[piles->nb_elem_total - 1]
			!= piles->nb_elem_total - 1)
			ft_do_command(piles, "ra\n", RA);
	else
		while (piles->col_ui_a[piles->nb_elem_total - 1]
			!= piles->nb_elem_total - 1)
			ft_do_command(piles, "rra\n", RRA);
}

static int			ft_col_a_end_issort(t_piles *piles)
{
	unsigned int	a;
	int				max_stay_in_i;

	max_stay_in_i = 0;
	a = piles->col_a_pos_first_elem;
	while (a + 1 < piles->nb_elem_total)
	{
		if (piles->col_ui_a[a] == piles->nb_elem_total - 1)
			max_stay_in_i = 1;
		if (piles->col_ui_a[a] != piles->nb_elem_total - 1
			&& piles->col_ui_a[a] + 1 != piles->col_ui_a[a + 1])
			return (0);
		a++;
	}
	if (!max_stay_in_i)
		return (0);
	if (piles->col_ui_a[a] == piles->nb_elem_total - 1
		|| (piles->col_ui_a[a]
			== piles->col_ui_a[piles->col_a_pos_first_elem] + 1))
		return (1);
	return (0);
}

static t_path_var	*ft_init_struct_path_var(void)
{
	t_path_var	*var_path;

	if ((var_path = (t_path_var *)ft_memalloc(sizeof(t_path_var))) == NULL)
		return (NULL);
	return (var_path);
}

int					ft_sort_piles(t_piles *piles)
{
	t_path_var		*var_path;

	if ((var_path = ft_init_struct_path_var()) == NULL)
		return (EXIT_FAILURE);
	while (piles->col_a_nb_element && !ft_col_a_end_issort(piles))
	{
		var_path->shortest_a = piles->nb_elem_total;
		var_path->shortest_b = piles->nb_elem_total;
		var_path->shortest_total = piles->nb_elem_total;
		ft_get_sort(piles, var_path);
		ft_do_shortest_move(piles, var_path);
	}
	ft_sort_end_a(piles);
	ft_push_b(piles);
	ft_memdel((void **)&var_path);
	return (0);
}
