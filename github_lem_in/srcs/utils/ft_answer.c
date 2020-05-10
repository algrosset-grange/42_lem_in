/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_answer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:11:36 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 13:16:45 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_answer(int a)
{
	if (a == INT_MESSAGE_ERROR)
		ft_putstr_fd("Error\n", 2);
	if (a == INT_MESSAGE_KO)
		ft_putstr("KO\n");
	if (a == INT_MESSAGE_OK)
		ft_putstr("OK\n");
	return (0);
}
