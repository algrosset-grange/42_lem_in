/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:40:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/02/22 01:06:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_exit_prog(t_map *map, t_lroom *list_room, t_lroom *rendu_first_room,
	int type_error)
{
	t_lroom	*erase_lroom;
	t_room	*erase_room;

	while (rendu_first_room)
	{
		erase_lroom = rendu_first_room;
		rendu_first_room = rendu_first_room->next;
		ft_memdel((void **)&erase_lroom);
	}
	while (list_room)
	{
		erase_lroom = list_room;
		list_room = list_room->next;
		ft_memdel((void **)&erase_lroom);
	}
	while(map->entre)
	{
		erase_room = map->entre;
		map->entre = map->entre->next;
		ft_memdel((void **)&erase_room);
	}
	ft_memdel((void **)&map);
}