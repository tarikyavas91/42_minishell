/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwordsall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 15:17:40 by jrameau           #+#    #+#             */
/*   Updated: 2023/05/03 23:39:01 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwordsall(char const *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f')
			i++;
		if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
				|| str[i] == '\f') && str[i] != '\0')
			count++;
		while (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
				|| str[i] == '\f') && str[i] != '\0')
			i++;
	}
	return (count);
}
