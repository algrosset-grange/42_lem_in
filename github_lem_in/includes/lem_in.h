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

#define ERROR_MEMORY 0
/*
** type de room
*/
#define ENTRE 1
#define SORTIE 2
#define SIMPLE 0

/*
**
*/
#define IMPASSE -1
#define INCONNU 0

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
}				t_room;

typedef struct	s_lroom
{
	t_lroom		*next;
	t_room		*room;
}				t_lroom;


typedef struct	s_map
{
	t_room		*entre;
	t_room		*sortie;
	int			max_pos_x;
	int			max_pos_y;
}				t_map;

void			ft_solution(t_map *the_map);


#endif