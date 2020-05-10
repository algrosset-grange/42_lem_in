/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:57:55 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 12:43:54 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_put_shortest(t_path_var *p_var)
{
	p_var->shortest_a = p_var->test_move_a;
	p_var->shortest_b = p_var->test_move_b;
	p_var->shortest_both = p_var->test_move_both;
	p_var->shortest_total = p_var->test_move_total;
	p_var->rotate_a = p_var->test_rotate_a;
	p_var->rotate_b = p_var->test_rotate_b;
}

/*
**	t = total
**	bo = nb de commande rr
**	ra = nb de comm ra
**	rb = nb de comm rb
**	|
**	t = bo + ra + rb
**	ra = a - bo
**	rb = b - bo
**	t = bo + a - bo + b - bo
**	t = a + b - bo
*/

void	ft_set_test_move_total(t_path_var *p_var)
{
	p_var->test_move_both = 0;
	while (p_var->is_good_rotate
		&& p_var->test_move_both < p_var->test_move_a
		&& p_var->test_move_both < p_var->test_move_b)
	{
		p_var->test_move_both++;
	}
	p_var->test_move_total = p_var->test_move_a + p_var->test_move_b
		- p_var->test_move_both;
}
