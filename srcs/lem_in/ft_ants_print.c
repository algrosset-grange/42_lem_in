/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:40:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/02/22 01:06:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_ants	*ft_init_ants(t_map *map)
{
	int		i;
	t_ants	*ant;
	t_ants	*first_ant;
	t_ants	*actuacl_ant;

	i = 0;
	first_ant = NULL;
	while (i < map->nb_ants)
	{
		if (ant != (t_ants *)ft_memalloc(sizeof(t_ants)))
			ft_exit_prog_ant(map, first_ant, ERROR_MEMORY);
		ant->prev = NULL;
		if (first_ant == NULL)
			first_ant = ant;
		else
			actuacl_ant->next = ant;
		ant->actual_room = map->entre;
		ant->prev = actuacl_ant;
		actuacl_ant = ant;
		ant->next = NULL;
		ant->number = i + 1;
		i++;
	}
	return (first_ant);
}

void			ft_ants_print(t_map *map)
{
	t_ants	*first_ant;
	t_ants	*ant;
	t_ants	*actuacl_ant;
	int		is_ant_on_way;

	first_ant = NULL;
	actuacl_ant = NULL;
	first_ant = ft_init_ants(map);
	is_ant_on_way = 1;
	while (is_ant_on_way)
	{
		ant = first_ant;
		while (ant)
		{
			ft_move_ants(ant, map);
			ant = ant->next;
		}
		ft_printf("\n");
		first_ant = ft_sort_ant(first_ant, map);
	}
}
