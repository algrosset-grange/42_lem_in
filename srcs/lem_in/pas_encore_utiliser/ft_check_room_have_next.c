/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_room_have_next.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:40:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/02/22 01:06:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_check_room_have_next(t_room *room)
{
	int		iterator;
	int		val;

	val = -1;
	iterator = 0;
	while (iterator < room->nb_room_contact)
	{
		if (room->contact[iterator].range == INCONNU
			|| room->contact[iterator].range == room->range + 1)
			return (1);
		iterator++;
	}
	return (0);
}
