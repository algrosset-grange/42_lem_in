/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:14:48 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/02 22:52:54 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*mem;
	int		i;

	if (!(mem = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i])
		mem[i] = f(s[i]);
	mem[i] = '\0';
	return (mem);
}
