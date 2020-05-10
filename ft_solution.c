/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:40:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/02/22 01:06:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


static int	check_room_have_next(t_room *room, int range)
{
	int		iterator;

	iterator = 0;
	while (iterator < room->nb_room_contact)
	{
		if (room->contact[iterator].range == INCONNU
			|| room->contact[iterator].range == range + 1)
			return (1);
		iterator++;
	}
	return (0);
}


// terminé, mais à réduire
static t_lroom *check_list_have_next(t_map *map, t_lroom *list_room, int range)
{
	int		iterator;
	t_lroom	*lroom;
	t_room	*room;
	t_lroom	*rendu_first_room;
	t_lroom	*rendu_actuel_room;

	
	lroom = list_room;
	rendu_first_room = NULL;
	while (lroom)
	{
		room = lroom->room;
		iterator = 0;
		if (check_room_have_next(room, range))
		{

			while (iterator < room->nb_room_contact)
			{
				if (room->contact[iterator].range == INCONNU)
				{
					if (!rendu_first_room)
					{
						if (rendu_first_room = (t_lroom *)ft_memalloc(sizeof(t_lroom)) == NULL)
							return (ft_exit_prog(map, list_room, rendu_first_room, ERROR_MEMORY));
						rendu_actuel_room = rendu_first_room;
						rendu_actuel_room->room = &(room->contact[iterator]);
					}
					else
					{
						if (rendu_actuel_room->next = (t_lroom *)ft_memalloc(sizeof(t_lroom)) == NULL)
							return (ft_exit_prog(map, list_room, rendu_first_room, ERROR_MEMORY));
						rendu_actuel_room = rendu_actuel_room->next;
						rendu_actuel_room->room = &(room->contact[iterator]);
					}
				}
				iterator++;
			}
			
		}
		else
		{
			if (room->contact[iterator].range == room->range - 1)
				{
					if (!rendu_first_room)
					{
						if (rendu_first_room = (t_lroom *)ft_memalloc(sizeof(t_lroom)) == NULL)
							return (ft_exit_prog(map, list_room, rendu_first_room, ERROR_MEMORY));
						rendu_actuel_room = rendu_first_room;
						rendu_actuel_room->room = &(room->contact[iterator]);
					}
					else
					{
						if (rendu_actuel_room->next = (t_lroom *)ft_memalloc(sizeof(t_lroom)) == NULL)
							return (ft_exit_prog(map, list_room, rendu_first_room, ERROR_MEMORY));
						rendu_actuel_room = rendu_actuel_room->next;
						rendu_actuel_room->room = &(room->contact[iterator]);
					}
				}
			room->range = IMPASSE;
		}
		lroom = lroom->next;
	}
	ft_memdel_lroom(&lroom);
	return (rendu_first_room);
}

static int	give_range(t_lroom *list_room, int range)
{
	int		iterator;
	t_lroom	*lroom;
	t_lroom *previous;
	t_lroom	*exclu;

	iterator = 0;
	lroom = list_room;
	previous = NULL;
	exclu = NULL;
	while (lroom->next)
	{
		if (lroom->room->range == range)
		{
			exclu = lroom;
			previous->next = exclu->next;
			ft_memdel((void **)&exclu);
		}
		if (lroom->room->range == INCONNU
			|| lroom->room->range > range)
			lroom->room->range = range;
		previous = lroom;
		lroom = lroom->next;
	}
	return (1);
}

static int	ft_soluce_rec(t_map *map, t_lroom *list_room, int range)
{
	int		iterator;
	t_lroom	*lroom;

	iterator = 0;
	give_range(list_room, range);
	lroom = check_list_have_next(map, list_room, range);
	return 1;
}

void		ft_solution(t_map *the_map)
{
	int			iterator;
	t_lroom		*lroom;
	t_lroom		*next;

	if (lroom != (t_lroom *)ft_memalloc(sizeof(t_lroom)))
		return (ft_exit_prog(the_map, NULL, ERROR_MEMORY));
	iterator = 1;
	lroom->room = &(the_map->sortie->contact[0]);
	next = lroom;
	next->next = NULL;
	while (iterator < the_map->sortie->nb_room_contact)
	{
		if (next->next = (t_lroom *)ft_memalloc(sizeof(t_lroom)) == NULL)
			return (ft_exit_prog(the_map, lroom, NULL, ERROR_MEMORY));
		next->next->room = &(the_map->sortie->contact[iterator]);
		next = next->next;
		next->next = NULL;
		iterator++;
	}
	ft_soluce_rec(the_map, lroom, 1);
}