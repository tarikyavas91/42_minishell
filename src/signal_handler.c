/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 00:50:10 by jrameau           #+#    #+#             */
/*   Updated: 2023/05/07 19:17:31 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	proc_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, proc_signal_handler);
	}
}

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		ft_putstr("\033[5;91mMini\033[0m\033[5;1;92mShell🔥💯 : \033[0m");
		signal(SIGINT, signal_handler);
	}
}
