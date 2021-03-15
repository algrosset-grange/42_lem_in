/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_room_are_impasse.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:40:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/02/22 01:06:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_check_room_are_impasse(t_room *room)
{
	int		iterator;
	int		val;

	val = -1;
	iterator = 0;
	while (iterator < room->nb_room_contact)
	{
		if (room->contact[iterator].range == room->range + 1
			|| room->contact[iterator].type_room == ENTRE)
			return (1);
		iterator++;
	}
	return (0);
}
