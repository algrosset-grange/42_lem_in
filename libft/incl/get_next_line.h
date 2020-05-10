/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <agrosset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:56:31 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/28 10:39:12 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 8192
# define GNL_END_ERROR -1

# define GNL_NOT_END 0
# define GNL_END_NULL 1
# define GNL_END_JUMP 2

int	get_next_line(int const fd, char **line);

#endif
