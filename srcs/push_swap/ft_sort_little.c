/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_little.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:57:55 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 12:43:54 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_sort_little_4_p2(unsigned int *tab, unsigned int p)
{
	if ((tab[p] == 0 && tab[p + 1] == 3 && tab[p + 2] == 2)
		|| (tab[p] == 1 && tab[p + 1] == 3 && tab[p + 2] == 2)
		|| (tab[p] == 3 && tab[p + 1] == 1 && tab[p + 2] == 0)
		|| (tab[p] == 3 && tab[p + 1] == 0 && tab[p + 2] == 1)
		|| (tab[p] == 1 && tab[p + 1] == 2 && tab[p + 2] == 0)
		|| (tab[p] == 0 && tab[p + 1] == 2 && tab[p + 2] == 1))
		return (1);
	return (0);
}

static void	ft_sort_little_4(t_piles *piles)
{
	unsigned int	p;
	unsigned int	*tab;

	tab = piles->col_ui_a;
	p = piles->col_a_pos_first_elem;
	while (!(tab[p] == 0 && tab[p + 1] == 1 && tab[p + 2] == 2))
	{
		if ((tab[p] == 1 && tab[p + 1] == 0 && tab[p + 2] == 3)
			|| (tab[p] == 0 && tab[p + 1] == 1 && tab[p + 2] == 3)
			|| (tab[p] == 3 && tab[p + 1] == 0 && tab[p + 2] == 2)
			|| (tab[p] == 3 && tab[p + 1] == 1 && tab[p + 2] == 2)
			|| (tab[p] == 2 && tab[p + 1] == 3 && tab[p + 2] == 0)
			|| (tab[p] == 2 && tab[p + 1] == 3 && tab[p + 2] == 1)
			|| (tab[p] == 0 && tab[p + 1] == 2 && tab[p + 2] == 3)
			|| (tab[p] == 1 && tab[p + 1] == 2 && tab[p + 2] == 3))
			ft_do_command(piles, "rra\n", RRA);
		else if (ft_sort_little_4_p2(tab, p))
			ft_do_command(piles, "ra\n", RA);
		else
			ft_do_command(piles, "sa\n", SA);
	}
}

static void	ft_sort_little_5(t_piles *piles)
{
	unsigned int	pos_max;

	pos_max = 0;
	while (piles->col_ui_a[pos_max] != 4)
		pos_max++;
	if (pos_max <= 2)
		while (pos_max)
		{
			ft_do_command(piles, "ra\n", RA);
			pos_max--;
		}
	else
		while (pos_max != 5)
		{
			ft_do_command(piles, "rra\n", RA);
			pos_max++;
		}
	ft_do_command(piles, "pb\n", PB);
	ft_sort_little_4(piles);
	ft_do_command(piles, "pa\n", PB);
	ft_do_command(piles, "ra\n", RA);
}

void		ft_sort_little(t_piles *piles)
{
	if (piles->nb_elem_total == 2)
		ft_do_command(piles, "sa\n", SA);
	else if (piles->nb_elem_total == 3)
	{
		if (piles->col_ui_a[0] == 2 && piles->col_ui_a[1] == 1)
			ft_do_command(piles, "sa\n", SA);
		if (piles->col_ui_a[0] == 1 && piles->col_ui_a[1] == 2)
			ft_do_command(piles, "rra\n", RRA);
		if (piles->col_ui_a[0] == 0 && piles->col_ui_a[1] == 2)
			ft_do_command(piles, "sa\n", SA);
		if (piles->col_ui_a[0] == 2 && piles->col_ui_a[1] == 0)
			ft_do_command(piles, "ra\n", RA);
		if (piles->col_ui_a[0] == 1 && piles->col_ui_a[1] == 0)
			ft_do_command(piles, "sa\n", SA);
	}
	else if (piles->nb_elem_total == 4)
		ft_sort_little_4(piles);
	else if (piles->nb_elem_total == 5)
		ft_sort_little_5(piles);
}
