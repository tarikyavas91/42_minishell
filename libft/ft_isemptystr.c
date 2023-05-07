/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isemptystr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 00:03:25 by jrameau           #+#    #+#             */
/*   Updated: 2023/05/03 21:49:31 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isemptystr(char *str, int consider_space)
{
	int	i;
	int	min;
	int	max;

	i = -1;
	min = 32 + consider_space;
	max = 126;
	while (str[++i])
	{
		if (str[i] >= min && str[i] <= max)
			return (0);
	}
	return (1);
}
