/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 02:25:46 by agrosset          #+#    #+#             */
/*   Updated: 2017/05/01 02:25:59 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_realloc(char *str, size_t size)
{
	char	*ret;

	if (str == NULL || size <= 0)
		return (NULL);
	if (!(ret = malloc(size)))
		return (NULL);
	ft_strncpy(ret, str, size);
	free(str);
	return (ret);
}
