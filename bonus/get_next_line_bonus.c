/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <rbiodies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:07:14 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/24 15:52:13 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*make_newbackup(char *backup)
{
	int		i;
	char	*newbackup;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\0')
	{
		free(backup);
		return (NULL);
	}
	newbackup = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!newbackup)
		return (NULL);
	ft_strlcpy(newbackup, backup + i + 1, ft_strlen(backup) - i + 1);
	free(backup);
	return (newbackup);
}

static char	*make_line(char *backup)
{
	int		i;
	char	*line;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	line = malloc(sizeof(char *) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, backup, i + 2);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*make_backup(int fd, char *backup, char *buffer)
{
	char	*tmp;
	int		bytes_was_read;
	int		flag;

	bytes_was_read = 1;
	flag = 0;
	while (flag == 0 && bytes_was_read != 0)
	{
		bytes_was_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_was_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_was_read] = '\0';
		if (!backup)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(backup, buffer);
		free(tmp);
		if (ft_strchr(backup, '\n'))
			flag = 1;
	}
	free(buffer);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*backup;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	backup = make_backup(fd, backup, buffer);
	if (!backup)
		return (NULL);
	line = make_line(backup);
	backup = make_newbackup(backup);
	return (line);
}
