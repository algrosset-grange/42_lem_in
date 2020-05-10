/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_shortest_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:57:55 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 12:43:54 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_do_a(t_piles *piles, t_path_var *p_var)
{
	if (p_var->rotate_a == HORAIRE)
		ft_do_command(piles, "ra\n", RA);
	else
		ft_do_command(piles, "rra\n", RRA);
}

static void	ft_do_b(t_piles *piles, t_path_var *p_var)
{
	if (p_var->rotate_b == HORAIRE)
		ft_do_command(piles, "rb\n", RB);
	else
		ft_do_command(piles, "rrb\n", RRB);
}

static void	ft_do_both(t_piles *piles, t_path_var *p_var)
{
	if (p_var->rotate_a == HORAIRE)
		ft_do_command(piles, "rr\n", RR);
	else
		ft_do_command(piles, "rrr\n", RRR);
}

void		ft_do_shortest_move(t_piles *piles, t_path_var *p_var)
{
	unsigned int mov_both;
	unsigned int mov_a;
	unsigned int mov_b;

	mov_both = 0;
	mov_a = 0;
	mov_b = 0;
	while (mov_both < p_var->shortest_both)
	{
		ft_do_both(piles, p_var);
		mov_both++;
		mov_a++;
		mov_b++;
	}
	while (mov_a < p_var->shortest_a)
	{
		ft_do_a(piles, p_var);
		mov_a++;
	}
	while (mov_b < p_var->shortest_b)
	{
		ft_do_b(piles, p_var);
		mov_b++;
	}
	ft_do_command(piles, "pb\n", PB);
}
