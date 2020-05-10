/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:14:30 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 13:21:58 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static int	ft_checker_p3(t_piles *piles)
{
	int		nu_command;
	int		i;
	char	*command;

	command = NULL;
	while ((i = get_next_line(0, &command)) == GNL_NOT_END)
	{
		if ((nu_command = ft_checker_check_order(command))
			== CHECK_COMMAND_ERROR)
		{
			i = GNL_END_NULL;
			break ;
		}
		else
			piles->tab_comm[nu_command](piles);
		ft_memdel((void **)&command);
	}
	ft_memdel((void **)&command);
	return (i);
}

static int	ft_checker_p2(int nb_number, char **av, int is_one)
{
	int			i;
	t_piles		*piles;

	if ((piles = ft_init_struct_piles(nb_number, av, is_one)) == NULL)
		return (EXIT_FAILURE);
	ft_align_piles(piles);
	i = ft_checker_p3(piles);
	if (i != GNL_END_ERROR && i != GNL_END_NULL)
		ft_issort_final(piles);
	ft_free_piles(&piles);
	if (i == GNL_END_ERROR)
		return (EXIT_FAILURE);
	if (i == GNL_END_NULL)
		return (ft_answer(INT_MESSAGE_ERROR));
	return (0);
}

static int	ft_checker(int nb_number, char **av, int is_one)
{
	if (ft_verif_arg(nb_number, av, is_one))
		return (ft_answer(INT_MESSAGE_ERROR));
	return (ft_checker_p2(nb_number, av, is_one));
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
		ft_checker(nb_elem, serial, 1);
		ft_free_tab(nb_elem, serial);
		return (0);
	}
	return (ft_checker(ac - 1, av, 0));
}
