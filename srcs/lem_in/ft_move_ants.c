/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:40:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/02/22 01:06:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_make_move(t_room *room, t_ants *ant, t_map *map)
{
	if (ant->actual_room->type_room == ENTRE)
		map->ants_hall--;
	ant->actual_room->ant_here = NULL;
	ant->actual_room = room;
	room->ant_here = ant;
	ft_printf("L%d-%s", ant->number, room->nom);
}

static int		check_range(t_room *check_room, t_room *retu_room, t_ants *ant,
	t_map *map)
{
	if (check_room->ant_here == NULL
		&& check_room->range != INCONNU
		&& ant->actual_room->type_room == ENTRE
		&& map->ants_hall > check_room->range - map->begin_find
		&& (retu_room == NULL || check_room->range > retu_room->range))
		return (1);
	return (0);
}

static t_room	*ft_verif_next_room(t_ants *ant, t_map *map)
{
	int		i;
	t_room	*check_room;
	t_room	*retu_room;

	i = 0;
	check_room = NULL;
	retu_room = NULL;
	while (i < ant->actual_room->nb_room_contact)
	{
		check_room = &(ant->actual_room->contact)[i];
		if (ant->actual_room->type_room == SORTIE)
			return (NULL);
		if (check_room->type_room == SORTIE)
			return (check_room);
		else if (check_range(check_room, retu_room, ant, map))
			retu_room = check_room;
		else if (check_room->ant_here == NULL
			&& ant->actual_room->type_room != ENTRE
			&& check_room->range == ant->actual_room->range - 1)
			return (check_room);
		i++;
	}
	return (retu_room);
}

void			ft_move_ants(t_ants *ant, t_map *map)
{
	t_room *room;

	room = NULL;
	if (ant->actual_room->type_room != SORTIE)
	{
		room = ft_verif_next_room(ant, map);
		if (room)
			ft_make_move(room, ant, map);
	}
}
