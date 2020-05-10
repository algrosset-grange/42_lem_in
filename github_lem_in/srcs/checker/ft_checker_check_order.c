/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_check_order.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:14:30 by agrosset          #+#    #+#             */
/*   Updated: 2019/05/13 13:21:58 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static int	ft_checker_check_order_p2(char *command)
{
	int			counter_command;
	char		*the_command;
	static char	tab_com_1[6][3] = { "sa", "sb", "ss", "pa", "pb", "ra"};
	static char	tab_com_2[5][4] = {"rb", "rr", "rra", "rrb", "rrr"};

	counter_command = 0;
	while (counter_command < 11)
	{
		if (counter_command <= 5)
			the_command = tab_com_1[counter_command];
		else
			the_command = tab_com_2[counter_command - 6];
		if (!ft_strcmp(command, the_command))
			return (counter_command);
		counter_command++;
	}
	return (CHECK_COMMAND_ERROR);
}

int			ft_checker_check_order(char *command)
{
	int			counter_command;

	counter_command = 0;
	if ((counter_command =
		ft_checker_check_order_p2(command)) != CHECK_COMMAND_ERROR)
		return (counter_command);
	return (CHECK_COMMAND_ERROR);
}
