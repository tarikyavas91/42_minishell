/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:35:14 by jrameau           #+#    #+#             */
/*   Updated: 2023/05/07 19:17:45 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(void)
{
	int		i;

	i = -1;
	while (g_envv[++i])
		ft_putendl(g_envv[i]);
}

static	int	envv_len(char **envv)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (envv[++i])
		count++;
	return (count);
}

void	init_envv(int ac, char **av, char **envv)
{
	int		i;

	(void)ac;
	(void)av;
	g_envv = (char **)ft_memalloc(sizeof(char *) * (envv_len(envv) + 1));
	i = -1;
	while (envv[++i])
	{
		g_envv[i] = ft_strdup(envv[i]);
		if (!g_envv[i])
			exit_shell();
	}
}

static	void	remove_env_var(int var_pos)
{
	int		i;
	int		var_count;

	free(g_envv[var_pos]);
	g_envv[var_pos] = NULL;
	i = var_pos;
	var_count = var_pos + 1;
	while (g_envv[i + 1])
	{
		g_envv[i] = ft_strdup(g_envv[i + 1]);
		free(g_envv[i + 1]);
		i++;
		var_count++;
	}
	g_envv = realloc_envv(var_count - 1);
}

int	unsetenv_builtin(char **args)
{
	int			i;
	int			var_pos;

	if (!args[0])
	{
		ft_putendl("unsetenv: Too few arguments.");
		return (1);
	}
	i = -1;
	while (args[++i])
	{
		var_pos = find_env_var(args[i]);
		if (g_envv[var_pos])
			remove_env_var(var_pos);
	}
	return (1);
}
