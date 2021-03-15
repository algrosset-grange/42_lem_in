/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:40:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/02/22 01:06:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
	int				(void)
{
	t_map *m;

	m = map_init();
	read_map(m);
	add_rooms(m);
	if (!m->good[0] || !m->good[1])
		exit_func(m, 1);
	create_tab(m);
	print_matrix(m);
	if (solution(m, 0))
		result(m);
	else
		exit_func(m, 1);
	exit_func(m, 0);
}
*/

#define FAIL_CREATE_MAP -1

void	ft_error(int error, t_map **map)
{

}

t_map	*ft_init_map()
{
	t_map	*map;

	if ((map = (t_map *)ft_memalloc(sizeof(t_map))) == NULL)
		return (NULL);
	

}

t_map	*ft_get_map()
{
	t_map *map;

	if (map = ft_init_map() == NULL)
		ft_error(FAIL_CREATE_MAP, &map);
	

	return (map);
}

int main(int argc, char **argv)
{
	t_map *map;

	map = ft_get_map();
	ft_solution(map);
	ft_ants_print(map);

	return (0);
}