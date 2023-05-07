/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:18:35 by jrameau           #+#    #+#             */
/*   Updated: 2023/05/03 23:39:55 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_len(char const *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	while (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f') && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_strsplitall(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	**str2;

	str2 = (char **)malloc(sizeof(*str2) * (ft_countwordsall(s) + 1));
	if (!s || !str2)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_countwordsall(s))
	{
		k = 0;
		str2[i] = ft_strnew(get_word_len(&s[j]) + 1);
		if (!str2[i])
			str2[i] = NULL;
		while (s[j] == ' ' || s[j] == '\t' || s[j] == '\r' || s[j] == '\f')
			j++;
		while (!(s[j] == ' ' || s[j] == '\t' || s[j] == '\r' || s[j] == '\f')
			&& s[j])
			str2[i][k++] = s[j++];
		str2[i][k] = '\0';
	}
	str2[i] = 0;
	return (str2);
}
