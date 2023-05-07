/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 01:11:53 by jrameau           #+#    #+#             */
/*   Updated: 2023/05/03 21:59:05 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t prev_size, size_t new_size)
{
	void	*new;
	size_t	n;

	if (!ptr)
		return (NULL);
	new = ft_memalloc(new_size);
	if (!new)
	{
		free(ptr);
		return (NULL);
	}
	if (prev_size < new_size)
		n = prev_size;
	else
		n = new_size;
	ft_memcpy(new, ptr, n);
	free(ptr);
	return (new);
}
