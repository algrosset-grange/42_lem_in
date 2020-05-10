/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_piles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:14:30 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 13:21:58 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_free_piles(t_piles **piles)
{
	if ((*piles)->col_i_a != NULL)
		ft_memdel((void **)&(*piles)->col_i_a);
	if ((*piles)->col_i_b != NULL)
		ft_memdel((void **)&(*piles)->col_i_b);
	if ((*piles)->col_ui_a != NULL)
		ft_memdel((void **)&(*piles)->col_ui_a);
	if ((*piles)->col_ui_b != NULL)
		ft_memdel((void **)&(*piles)->col_ui_b);
	ft_memdel((void **)piles);
}
