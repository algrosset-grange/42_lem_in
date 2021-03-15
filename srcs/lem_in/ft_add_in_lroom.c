/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_in_lroom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:40:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/02/22 01:06:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_add_in_lroom(t_map *the_map, t_lroom *lroom, t_room *room)
{
	t_lroom *actual_lroom;

	actual_lroom = lroom;
	if (!actual_lroom)
	{
		if (actual_lroom = (t_lroom *)ft_memalloc(sizeof(t_lroom)) == NULL)
			return (ERROR_MEMORY);
		actual_lroom->room = NULL;
		actual_lroom->next = NULL;
	}
	while(actual_lroom->room)
	{
		if(actual_lroom->next)
			actual_lroom = actual_lroom->next;
		else	
		{
			if (actual_lroom->next = (t_lroom *)ft_memalloc(sizeof(t_lroom)) == NULL)
				return (ERROR_MEMORY);
			actual_lroom->next->room = room;
			actual_lroom->next->next = NULL;
			return (NO_ERROR);
		}
	}
	actual_lroom->room = room;
	if(actual_lroom->next)
		actual_lroom->next->room = NULL;
	return (NO_ERROR);
	
}