/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:23:11 by lbard             #+#    #+#             */
/*   Updated: 2024/12/18 16:15:28 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <string.h>

/*
 * @Read from fd and accumulate the text in saved.
 */
static char	*read_and_accumulate(int fd, char *saved)
{
	char	*tmp;
	char	*buffer;
	int		b;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	b = read(fd, buffer, BUFFER_SIZE);
	while (b > 0)
	{
		buffer[b] = '\0';
		tmp = ft_strjoin(saved, buffer);
		if (!tmp)
			return (NULL);
		free(saved);
		saved = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
		b = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (saved);
}

/*
 * @Fetch line in new char and updates saved for the next call.
 */
static char	*fetch_line(char *saved)
{
	char	*line;
	char	*newline_pos;

	if (!saved || *saved == '\0')
		return (NULL);
	newline_pos = ft_strchr(saved, '\n');
	if (newline_pos)
	{
		line = ft_substr(saved, 0, newline_pos - saved + 1);
		ft_strlcpy(saved, newline_pos + 1, gnl_ft_strlen(newline_pos));
	}
	else
	{
		line = ft_substr(saved, 0, gnl_ft_strlen(saved));
		saved[0] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = read_and_accumulate(fd, saved);
	line = fetch_line(saved);
	if (saved && *saved == '\0')
	{
		free(saved);
		saved = NULL;
	}
	return (line);
}

