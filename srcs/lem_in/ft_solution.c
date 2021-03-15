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

/*
** pour le premier appel
** map : contient tout la map + autre info
** list_room : toutes les salle relié à la sortie
** range = 1
*/

static int	ft_solution_p4(t_map *map, t_lroom *list_room)
{
	int		iterator;
	t_lroom	*lroom;

	iterator = 0;
	while (list_room != NULL && !map->begin_find
		|| (map->begin_find
		&& list_room->room->range - map->begin_find + 1 < map->nb_ants))
	{
		lroom = check_list_have_next(map, list_room);
		ft_memdel_lroom(&list_room);
		list_room = lroom;
	}
	return (1);
}

void		ft_solution_p3(t_lroom *actual_lroom, t_map *map,
	t_lroom *lroom, int iterator)
{
	if (actual_lroom->next = (t_lroom *)ft_memalloc(sizeof(t_lroom))
		== NULL)
		ft_exit_prog(map, lroom, NULL, ERROR_MEMORY);
	actual_lroom->next->room = &(map->sortie->contact[iterator]);
	actual_lroom = actual_lroom->next;
	if (actual_lroom->room->type_room == ENTRE)
		map->begin_find = 1;
	else
		actual_lroom->room->range = 1;
	actual_lroom->next = NULL;
}

/*
**	on prépare une liste_de room
**	qui sont en contact avec la sortie
*/

void		ft_solution_p2(t_map *map, int iterator)
{
	t_lroom	*lroom;
	t_lroom	*actual_lroom;

	if (lroom != (t_lroom *)ft_memalloc(sizeof(t_lroom)))
		ft_exit_prog(map, NULL, NULL, ERROR_MEMORY);
	lroom->room = &(map->sortie->contact[iterator]);
	lroom->room->range = 1;
	actual_lroom = lroom;
	actual_lroom->next = NULL;
	iterator++;
	while (iterator < map->sortie->nb_room_contact)
	{
		if ((&(map->sortie->contact[iterator]))->type_room == ENTRE)
			map->begin_find = 1;
		else
			ft_solution_p3(actual_lroom, map, lroom, iterator);
		iterator++;
	}
	ft_solution_p4(map, lroom);
}

/*
**	ft_solution
**	première étape : trouver un tunel qui ne relie pas directement 
**	la sortie et l'entre
**	au passage on vérifie aussi si on trouve un tunel direct,
**	on l'indique dans find_begin
*/

void		ft_solution_begin(t_map *the_map)
{
	int			iterator;
	int			type_room;

	iterator = 0;
	type_room = (&(the_map->sortie->contact[iterator]))->type_room;
	while (type_room == ENTRE && iterator < the_map->sortie->nb_room_contact)
	{
		the_map->begin_find = 1;
		iterator++;
		type_room = (&(the_map->sortie->contact[iterator]))->type_room;
	}
	if (iterator >= the_map->sortie->nb_room_contact)
		return ;
	ft_solution_p2(the_map, iterator);
}


/*
** étape 1 - remplir la liste des salle de rang 1 : l_room_1 (marqué leur rang à 1)
** étape 2 - récursive :
**		tant que l_room_1 n'est pas vide
**			pour chaque room de l_room_1
**				chercher s'ils sont en contact avec l'entré la sortie
**				vérifier qu'ils ont une suite inexploré et, si l'entré est découverte, à porté
**				mettez le rang de porté sur ces nouvelles salles
**				ajouter ces salle inexplorés à l_room_2
**			l_room_1 = l_room_2
**		répétez
*/

void		ft_solution(t_map *the_map)
{
	t_lroom	*actual_l_room;
	t_room	*actual_room;

	actual_l_room = ft_solution_room_end(the_map);
	the_map->l_room_begin = actual_l_room;
	while(actual_l_room->room)
	{
		actual_room = actual_l_room->room;
		while (actual_room)
		{
			/**/
			
			actual_room = NULL;
			if (actual_l_room->next)
			{	actual_l_room = actual_l_room->next;
				actual_room = actual_l_room->room;
			}
		}
		ft_lroom_next_to_lroom_actual();
	}

}