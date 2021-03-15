/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 18:37:46 by agrosset          #+#    #+#             */
/*   Updated: 2017/05/06 01:28:13 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

#define NO_ERROR 0
#define ERROR_MEMORY 1
#define BEGIN_FIND 2

/*
** type de room
*/
#define ENTRE 1
#define SORTIE 2
#define SIMPLE 0

/*
** find_begin
*/
#define NOT_FIND -1

/*
** room.range
** si room.range != IMPASSE et INCONNU
** alors room est déjà parcourue.
*/
#define IMPASSE -1
#define INCONNU 0

typedef struct	s_ants
{
	t_ants		*prev;
	t_ants		*next;
	int			number;
	int			moved;
	t_room		*actual_room;
}				t_ants;

typedef struct	s_room
{
	char		*nom;
	t_room		*contact;
	int			nb_room_contact;
	int			type_room;
	int			range;
	int			pos_x;
	int			pos_y;
	t_room		*next;
	t_ants		*ant_here;
}				t_room;

typedef struct	s_lroom
{
	t_lroom		*next;
	t_room		*room;
}				t_lroom;


typedef struct	s_map
{
	t_lroom		*l_room_begin;
	t_room		*entre;
	t_room		*sortie;
	int			max_pos_x;
	int			max_pos_y;
	int			begin_find;
	int			nb_ants;
	int			ants_hall;
}				t_map;

void			ft_ants_print(t_map *map);

t_lroom 		*ft_check_list_have_next(t_map *map, t_lroom *list_room);

int				ft_check_room_are_impasse(t_room *room);

int				ft_check_room_have_next(t_room *room);

void			ft_exit_prog(t_map *map, t_lroom *list_room,
					t_lroom *rendu_first_room, int type_error);

int				ft_find_first_new_lroom(t_room *room,
					t_lroom **rendu_first_room);

int				ft_get_all_new_lroom(t_room *room,
					t_lroom **rendu_actual_room);

void			ft_move_ants(t_ants *ant, t_map *map);

void			ft_solution(t_map *the_map);

t_ants			*ft_sort_ant(t_ants *first_ant, t_map *map);


#endif