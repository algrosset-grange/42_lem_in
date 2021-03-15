/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list_have_next.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:40:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/02/22 01:06:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


static int	ft_parcour_room(t_room *room, t_lroom **rendu_first_room, 
	t_lroom **rendu_actuel_room, int *condition_and_range)
{
	int		iterator;
	t_lroom	*new_lroom;

	iterator = 0;
	while (iterator < room->nb_room_contact)
	{
		if (room->contact[iterator].range == condition_and_range[0])
		{
			if (new_lroom = (t_lroom *)ft_memalloc(sizeof(t_lroom)) == NULL)
				return (ERROR_MEMORY);
			if (*rendu_first_room == NULL)
			{
				*rendu_first_room = new_lroom;
				rendu_actuel_room = new_lroom;
			}
			else
			{
				(*rendu_actuel_room)->next = new_lroom;
				rendu_actuel_room = (*rendu_actuel_room)->next;
			}
			(*rendu_actuel_room)->room = &(room->contact[iterator]);
			(*rendu_actuel_room)->room->range = condition_and_range[1];
		}
		iterator++;
	}
	return (NO_ERROR);
}


int	ft_find_first_new_lroom(t_room *room, t_lroom **rendu_first_room)
{
	t_lroom	*rendu_actuel_room;
	int		condition_and_range[2];

	rendu_actuel_room = NULL;
	if (check_room_have_next(room))
	{
		condition_and_range[0] = INCONNU;
		condition_and_range[1] = room->range + 1;
		if (ft_parcour_room(room, rendu_first_room, &rendu_actuel_room,
			condition_and_range))
			return (ERROR_MEMORY);
	}
	else if (check_room_are_impasse(room))
	{
		condition_and_range[0] = room->range - 1;
		condition_and_range[1] = room->range - 1;
		if (ft_parcour_room(room, rendu_first_room, &rendu_actuel_room,
			condition_and_range))
			return (ERROR_MEMORY);
		room->range = IMPASSE;
	}
	return (NO_ERROR);
}

static int	check_list_have_next_p2(t_map *map, t_lroom *lroom,
	t_lroom *rendu_first_room)
{
	t_lroom	*rendu_actuel_room;
	int		is_find_begin;

	rendu_actuel_room = rendu_first_room;
	while (rendu_actuel_room->next != NULL)
		rendu_actuel_room = rendu_actuel_room->next;
	while (lroom)
	{
		if ((is_find_begin = ft_get_all_new_lroom(lroom->room,
			&rendu_actuel_room) == ERROR_MEMORY))
			return (ERROR_MEMORY);
		if (is_find_begin == BEGIN_FIND && map->begin_find == NOT_FIND)
			map->begin_find = lroom->room->range;
		lroom = lroom->next;
	}
	return (NO_ERROR);
}

t_lroom		*ft_check_list_have_next(t_map *map, t_lroom *list_room)
{
	t_lroom	*lroom;
	t_lroom	*rendu_first_room;
	int		is_find_begin;

	lroom = list_room;
	rendu_first_room = NULL;
	while (lroom && !rendu_first_room)
	{
		if ((is_find_begin = ft_find_first_new_lroom(lroom->room,
			&rendu_first_room)) == ERROR_MEMORY)
			ft_exit_prog(map, list_room, rendu_first_room, ERROR_MEMORY);
		if (is_find_begin == BEGIN_FIND && map->begin_find == NOT_FIND)
			map->begin_find = lroom->room->range;
		lroom = lroom->next;
	}
	if (check_list_have_next_p2(map, lroom, rendu_first_room) == ERROR_MEMORY)
		ft_exit_prog(map, list_room, rendu_first_room, ERROR_MEMORY);
	return (rendu_first_room);
}
