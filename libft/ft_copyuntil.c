/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyuntil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 05:49:22 by jrameau           #+#    #+#             */
/*   Updated: 2023/05/03 21:51:20 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_copyuntil(char **dst, char *src, char c)
{
	int	i;
	int	count;
	int	pos;

	i = -1;
	count = 0;
	while (src[++i])
		if (src[i] == c)
			break ;
	pos = i;
	*dst = ft_strnew(i);
	if (!*dst)
		return (0);
	while (src[count] && count < i)
	{
		*dst = ft_strjoinch(*dst, src[count]);
		if (!*dst)
			return (0);
		count++;
	}
	return (pos);
}
