/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoincl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 19:30:53 by jrameau           #+#    #+#             */
/*   Updated: 2023/05/03 22:01:49 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoincl(char *s1, char *s2, int free_both)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	if (!new)
		return (NULL);
	free(s1);
	s1 = NULL;
	if (free_both)
	{
		free(s2);
		s2 = NULL;
	}
	return (new);
}
