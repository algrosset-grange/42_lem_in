/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 14:42:14 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/01 22:23:19 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dst);
	while (*src && n--)
		dst[i++ + len] = *src++;
	dst[i + len] = '\0';
	return (dst);
}
