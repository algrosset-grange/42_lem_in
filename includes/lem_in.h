/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 21:42:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/08/09 17:46:24 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <limits.h>
# include <stdio.h>

/*
typedef struct	s_map
{
	char		**rooms;		// array of room names
	char		*rooms_list;	// list of rooms that was passed at the beginning
	char		*ants_str;		// list of ants that was passed at the beginning
	char		*links;			// list of links that was passed at the beginning
	int			q_rooms;		// quantity of rooms
	int			ants;			// quantity of ants
	int			started;		// a part of validation
	int			curr_room;		// an index of current room we're in
	int			p_ind;			// last path index, current size of path
	int			*path;			// path
	int			**tab;			// edge table
	int			good[2];		// a part of validation
	int			new_line;		// a part of validation
	int			init_2;			// a part of validation
}				t_map;
*/

/*
** type de room
*/
#define ENTRE 1
#define SORTIE 2
#define SIMPLE 0

/*
** range 
*/
#define IMPASSE -1
#define INCONNU 0

typedef struct	s_room
{
	char	*nom;
	t_room	*contact;
	int		nb_room_contact;
	int		type_room;
	int		range;
	//int		*etat_room; //pas bon
	int		pos_x;
	int		pos_y;
}				t_room;

typedef struct	s_map
{
	t_room	*entre;
	t_room	*sortie;
	int		max_pos_x;
	int		max_pos_y;
}				t_map;

void			ft_solution(t_map *the_map);

/*
void			count_ants(t_map *m, char *line);
void			rooms(t_map *m, char *line);
void			links(t_map *m, char *line);

void			add_rooms(t_map *m);
void			create_tab(t_map *m);
int				solution(t_map *m, int i);

char			*join_str(char *s1, char *s2, int clean);
void			free_array(char **array, t_map *m, int error);
int				room_index(t_map *m, char *room_name, int start);

void			result(t_map *m);
void			print_matrix(t_map *m);
void			exit_func(t_map *m, int error);
*/

#endif
