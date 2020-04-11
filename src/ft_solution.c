/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 20:20:17 by agrosset          #+#    #+#             */
/*   Updated: 2017/07/02 01:58:54 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_ending(t_map *map, t_room *actual_room)
{
	int iterator;

	iterator = 0;
	while (iterator < actual_room->nb_room_contact)
	{
		if ((&(actual_room->contact[iterator]))->type_room == SORTIE)
		{
			(&(actual_room->contact[iterator]))->range
				= actual_room->range + 1;
			return (1);
		}
		iterator++;
	}
	return (0);
}


static int	check_next_range(t_map *map, t_room *actual_room, int range)
{
	int iterator;
	int have_a_path;

	iterator = 0;
	while (iterator < actual_room->nb_room_contact)
	{
		if (((&(actual_room->contact[iterator]))->range == IMPASSE)
			|| ((&(actual_room->contact[iterator]))->range == range + 1)
			|| ((&(actual_room->contact[iterator]))->type_room == ENTRE))
			continue;
		else if ((&(actual_room->contact[iterator]))->range != INCONNU)
		{
			ft_soluce_rec(map, &(actual_room->contact[iterator]),
				actual_room, range + 1);
		}
		else if	((&(actual_room->contact[iterator]))->range > range + 1)
		{
			follow_the_ways();
		}
			
		iterator++;
	}
	
}


static int	ft_soluce_rec(t_map *map, t_room *actual_room, t_room *previus_room, int range)
{
	if (check_ending(map, actual_room))
	{
		actual_room->range = range;
		return (1);
	}
		return (actual_room->range + 1);
	check_next_range(map, actual_room, actual_room->range);

}

void		ft_solution(t_map *the_map)
{
	ft_soluce_rec(the_map, the_map->entre, NULL, 1);
}