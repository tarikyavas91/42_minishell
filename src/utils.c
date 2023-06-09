/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:43:29 by tyavas            #+#    #+#             */
/*   Updated: 2023/05/07 19:17:47 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(char x)
{
	if (x == ' ' || x == '\t' || x == '\r' || x == '\f')
		return (1);
	return (0);
}

int	is_quote(char x)
{
	return (x == '"' || x == '\'');
}
