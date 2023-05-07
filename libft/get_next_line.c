/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 22:52:30 by jrameau           #+#    #+#             */
/*   Updated: 2023/05/04 01:45:57 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_correct_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int	control_reaf(int fd, char *buf, t_list *curr)
{
	int	ret;

	ret = 0;
	ret = read(fd, buf, BUFF_SIZE);
	while (ret)
	{
		buf[ret] = '\0';
		curr->content = ft_strjoin(curr->content, buf);
		if (curr->content)
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
		ret = read(fd, buf, BUFF_SIZE);
	}
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*file;
	int				i;
	int				ret;
	t_list			*curr;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	curr = get_correct_file(&file, fd);
	*line = ft_strnew(1);
	if (!*line)
		return (-1);
	ret = control_reaf(fd, buf, curr);
	if (ret == -1)
		return (-1);
	if (ret < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);
	i = ft_copyuntil(line, curr->content, '\n');
	if (i < (int)ft_strlen(curr->content))
		curr->content += (i + 1);
	else
		ft_strclr(curr->content);
	return (1);
}
