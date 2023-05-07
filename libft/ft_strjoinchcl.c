/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchcl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 19:30:53 by jrameau           #+#    #+#             */
/*   Updated: 2023/05/03 22:01:22 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchcl(char *s1, char c)
{
	char	*new;

	new = ft_strjoinch(s1, c);
	if (!new)
		return (NULL);
	free(s1);
	s1 = NULL;
	return (new);
}
