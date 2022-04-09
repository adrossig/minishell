/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossign <arossign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:00:56 by arossign          #+#    #+#             */
/*   Updated: 2022/03/14 09:46:50 by arossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *str)
{
	free(str);
	str = NULL;
	return (str);
}

static char	*putinline_final(char **saved_fd, char *line)
{
	if (!(*saved_fd)[0])
	{
		*saved_fd = ft_free(*saved_fd);
		return (*saved_fd);
	}
	line = ft_strdup(*saved_fd);
	if (!line)
	{
		if (*saved_fd)
			*saved_fd = ft_free(*saved_fd);
		return (ft_free(line));
	}
	*saved_fd = ft_free(*saved_fd);
	return (line);
}

static char	*putinline(char **saved_fd)
{
	char	*temp;
	char	*line;
	size_t	i;

	i = 0;
	while ((*saved_fd)[i] != '\n' && (*saved_fd)[i] != '\0')
		i++;
	line = NULL;
	if ((*saved_fd)[i] == '\n')
	{
		line = sub_str((*saved_fd), i + 1);
		if (!line)
			return (ft_free(line));
		temp = ft_strdup(&(*saved_fd)[i + 1]);
		if (!temp)
			return (ft_free(temp));
		free(*saved_fd);
		*saved_fd = temp;
	}
	else
		return (putinline_final(saved_fd, line));
	return (line);
}

static int	gnl_loop(char **saved, char *buf, int fd, int ret)
{
	char	*tmp;

	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	if (!saved[fd])
	{
		if (!buf[0])
			return (-1);
		saved[fd] = ft_strdup(buf);
		if (!saved[fd])
			return (-1);
	}
	else
	{
		tmp = ft_strjoin(saved[fd], buf);
		if (!tmp)
		{
			free(tmp);
			return (-1);
		}
		free(saved[fd]);
		saved[fd] = tmp;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*saved[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = gnl_loop(saved, buf, fd, ret);
		if (ret == -1)
			return (NULL);
		if (ft_strchr(saved[fd], '\n'))
			break ;
	}
	return (putinline(&saved[fd]));
}
