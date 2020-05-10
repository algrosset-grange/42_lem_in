/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 13:45:58 by agrosset          #+#    #+#             */
/*   Updated: 2017/02/22 04:12:39 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstswap(t_list *lst1, t_list *lst2)
{
	lst1->next = lst2->next;
	lst2->next = lst1;
	return (lst2);
}
