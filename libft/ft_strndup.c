/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:20:20 by jrameau           #+#    #+#             */
/*   Updated: 2023/05/03 22:03:02 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*tmp;

	tmp = ft_strnew(n);
	if (!tmp)
		return (NULL);
	ft_strncpy(tmp, s1, n);
	return (tmp);
}
