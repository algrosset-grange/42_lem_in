/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:57:55 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 12:43:54 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			ft_is_sort_at_begin(t_piles *piles)
{
	unsigned int	a;

	if (piles->col_b_nb_element != 0)
		return (0);
	a = 1;
	while (a < piles->nb_elem_total)
	{
		if (piles->col_i_a[a - 1] > piles->col_i_a[a])
			return (0);
		a++;
	}
	return (1);
}

static int	ft_push_swap_p2(int nb_number, char **av, int is_one)
{
	t_piles			*piles;

	if ((piles = ft_init_struct_piles(nb_number, av, is_one)) == NULL)
		return (EXIT_FAILURE);
	ft_align_piles(piles);
	if (!ft_is_sort_at_begin(piles))
	{
		if (nb_number < 6)
			ft_sort_little(piles);
		else
		{
			ft_do_command(piles, "pb\n", PB);
			ft_do_command(piles, "pb\n", PB);
			if (ft_sort_piles(piles) == EXIT_FAILURE)
				ft_printf("error-allocation-memory\n");
		}
	}
	ft_free_piles(&piles);
	return (0);
}

static int	ft_push_swap(int nb_number, char **av, int is_one)
{
	if (ft_verif_arg(nb_number, av, is_one))
	{
		ft_answer(INT_MESSAGE_ERROR);
		return (0);
	}
	ft_push_swap_p2(nb_number, av, is_one);
	return (0);
}

int			main(int ac, char **av)
{
	char	**serial;
	int		nb_elem;

	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		serial = ft_strsplit(av[1], ' ');
		nb_elem = 0;
		while (serial[nb_elem])
			nb_elem++;
		ft_push_swap(nb_elem, serial, 1);
		ft_free_tab(nb_elem, serial);
		return (0);
	}
	ft_push_swap(ac - 1, av, 0);
	return (0);
}
