/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct_piles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:14:30 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 13:21:58 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static void	ft_fill_table_commande(t_piles *piles)
{
	piles->tab_comm[0] = &ft_comm_sa;
	piles->tab_comm[1] = &ft_comm_sb;
	piles->tab_comm[2] = &ft_comm_ss;
	piles->tab_comm[3] = &ft_comm_pa;
	piles->tab_comm[4] = &ft_comm_pb;
	piles->tab_comm[5] = &ft_comm_ra;
	piles->tab_comm[6] = &ft_comm_rb;
	piles->tab_comm[7] = &ft_comm_rr;
	piles->tab_comm[8] = &ft_comm_rra;
	piles->tab_comm[9] = &ft_comm_rrb;
	piles->tab_comm[10] = &ft_comm_rrr;
}

static void	ft_fill_col_a(t_piles *piles, char **av, int is_one)
{
	unsigned int	a;

	a = 1;
	while (a <= piles->nb_elem_total)
	{
		piles->col_i_a[a - 1] = ft_atoi(av[a - is_one]);
		piles->col_i_b[a - 1] = 0;
		a++;
	}
}

static void	ft_fill_var(t_piles *piles, int nb_number)
{
	piles->nb_elem_total = nb_number;
	piles->col_a_nb_element = nb_number;
	piles->col_a_pos_first_elem = 0;
	piles->col_b_nb_element = 0;
	piles->col_b_pos_first_elem = nb_number;
	piles->col_b_elem_min = piles->nb_elem_total;
	piles->col_b_elem_max = 0;
}

t_piles		*ft_init_struct_piles(int nb_number, char **av, int is_one)
{
	t_piles	*piles;

	if ((piles = (t_piles *)ft_memalloc(sizeof(t_piles))) == NULL)
		return (NULL);
	if ((piles->col_i_a = (int *)ft_memalloc(sizeof(int) * nb_number)) == NULL
		|| ((piles->col_i_b =
			(int *)ft_memalloc(sizeof(int) * nb_number)) == NULL)
		|| ((piles->col_ui_b =
			(unsigned int *)ft_memalloc(sizeof(unsigned int) * nb_number))
				== NULL)
		|| ((piles->col_ui_a =
			(unsigned int *)ft_memalloc(sizeof(unsigned int) * nb_number))
				== NULL))
	{
		ft_free_piles(&piles);
		return (NULL);
	}
	ft_fill_var(piles, nb_number);
	ft_fill_col_a(piles, av, is_one);
	ft_fill_table_commande(piles);
	return (piles);
}
