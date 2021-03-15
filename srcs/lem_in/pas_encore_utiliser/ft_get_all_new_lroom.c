/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_new_lroom.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:40:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/02/22 01:06:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_browse_room(t_room *room, t_lroom **rendu_actuel_room,
	int *condition_and_range)
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
			(*rendu_actuel_room)->next = new_lroom;
			rendu_actuel_room = (*rendu_actuel_room)->next;
			(*rendu_actuel_room)->room = &(room->contact[iterator]);
			(*rendu_actuel_room)->room->range = condition_and_range[1];
		}
		iterator++;
	}
}

int			ft_get_all_new_lroom(t_room *room, t_lroom **rendu_actual_room)
{
	int		condition_and_range[2];

	if (check_room_have_next(room))
	{
		condition_and_range[0] = INCONNU;
		condition_and_range[1] = room->range + 1;
		if (ft_browse_room(room, &rendu_actual_room,
			condition_and_range) == ERROR_MEMORY)
			return (ERROR_MEMORY);
	}
	else if (check_room_are_impasse(room))
	{
		condition_and_range[0] = room->range - 1;
		condition_and_range[1] = room->range - 1;
		if (ft_browse_room(room, &rendu_actual_room,
			condition_and_range))
			return (ERROR_MEMORY);
		room->range = IMPASSE;
	}
	return (NO_ERROR);
}
