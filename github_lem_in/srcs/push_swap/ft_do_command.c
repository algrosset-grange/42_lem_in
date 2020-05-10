/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:58:36 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 12:43:01 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_do_command(t_piles *piles, char *str_comm, int nu_com)
{
	piles->tab_comm[nu_com](piles);
	ft_putstr(str_comm);
	return (1);
}
