/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 00:50:46 by jrameau           #+#    #+#             */
/*   Updated: 2023/05/03 23:39:53 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_whitespaces(char *str, int *i, size_t *j)
{
	while (*(str + *i) == ' ' || *(str + *i) == '\t' || *(str + *i) == '\r'
		|| *(str + *i) == '\f')
		(*i)++;
	while (*(str + *j) == ' ' || *(str + *j) == '\t' || *(str + *j) == '\r'
		|| *(str + *j) == '\f')
		(*j)--;
	if (*i || *j < ft_strlen(str))
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s)
{
	int		i;
	size_t	j;
	int		k;
	char	*new_str;
	size_t	new_size;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen(s) - 1;
	if (!has_whitespaces((char *)s, &i, &j) || !ft_strlen(s))
		return ((char *)s);
	if (i == (int)ft_strlen(s))
		new_size = 0;
	else
		new_size = ft_strlen(s) - (size_t)i - (ft_strlen(s) - j);
	new_str = ft_strnew(new_size + 1);
	if (!new_str)
		return (NULL);
	while (i <= (int)j)
		*(new_str + k++) = *(s + i++);
	return (new_str);
}
