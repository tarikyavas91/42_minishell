/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 02:04:57 by jrameau           #+#    #+#             */
/*   Updated: 2023/05/03 21:55:01 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_str_len(int n)
{
	size_t	i;

	i = 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			str_len;
	unsigned int	n_cpy;

	str_len = get_str_len(n);
	n_cpy = n;
	if (n < 0)
	{
		n_cpy = -n;
		str_len++;
	}
	str = ft_strnew(str_len);
	if (!str)
		return (NULL);
	str[--str_len] = n_cpy % 10 + '0';
	while (n_cpy)
	{
		n_cpy /= 10;
		str[--str_len] = n_cpy % 10 + '0';
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
