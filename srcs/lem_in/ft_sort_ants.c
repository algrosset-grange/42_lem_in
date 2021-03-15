/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:40:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/02/22 01:06:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_make_swap_ant(t_room **first_ant, t_room **previous,
	t_room **actual, t_room **next)
{
	(*actual)->next = (*next)->next;
	(*next)->next = *actual;
	if (*previous)
		(*previous)->next = *next;
	else
		*first_ant = *next;
	*previous = *next;
	*next = *actual;
	*actual = *previous;
}

static int	ft_count_next_room(t_room *room)
{
	int		i;
	int		ret;
	t_room	*test;

	i = 0;
	ret = 0;
	while (i < room->nb_room_contact)
	{
		test = &(room->contact[i]);
		if (test->range == room->range - 1)
			ret++;
		i++;
	}
	return (ret);
}

/*
**	return -x si next à une plus petite range
**	return 0 si next->range == actual->range
**	sinon +x si actual à une plus petite range
*/

static int	ft_verif_range(t_room *next, t_room *actual)
{
	if (next->type_room == ENTRE)
		return (1);
	if (actual->type_room == ENTRE)
		return (-1);
	return (next->range - actual->range);
}

t_ants		*ft_sort_ant(t_ants *first_ant, t_map *map)
{
	t_ants	*previous;
	t_ants	*actual;
	t_ants	*next;

	actual = first_ant;
	next = actual->next;
	while (next)
	{
		if ((next->actual_room->type_room != ENTRE
			|| actual->actual_room->type_room != ENTRE)
			&& (ft_verif_range(next->actual_room, actual->actual_room) < 0
			|| (ft_verif_range(next->actual_room, actual->actual_room) == 0
			&& ft_count_next_room(next) < ft_count_next_room(actual))))
		{
			ft_make_swap_ant(&first_ant, &previous, &actual, &next);
		}
		previous = actual;
		actual = next;
		next = next->next;
	}
	return (first_ant);
}
