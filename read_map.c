/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:17:05 by rkandiyi          #+#    #+#             */
/*   Updated: 2023/03/07 17:06:39 by rkandiyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Functions to read map and make it double array */
static char	*read_line(t_vars *game, char *s, int fd, int b)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!s)
		s = ft_strdup("");
	while (b != 0)
	{
		b = read(fd, buffer, BUFFER_SIZE);
		if (b == -1)
			return (free(s), free(buffer), NULL);
		buffer[b] = 0;
		if ((buffer[0] > 8 && buffer[0] < 14) || (buffer[0] == 32))
		{
			free(buffer);
			errormsg(game, 1);
		}
		if (b == 0)
			break ;
		s = ft_strjoin(s, buffer);
	}
	if (buffer)
		free(buffer);
	return (s);
}

static int	count_lines(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c && (s[1] == c || s[1] == '\0'))
			i++;
		s++;
	}
	return (i);
}

static int	linelength(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		if (s[len] == c)
			return (len);
		len++;
	}
	return (ft_strlen(s));
}

static void	map_matrix(t_vars *game, char const *s)
{
	int		i;

	i = 0;
	if ((!game->map) || (!game->vmap))
		return ;
	game->count_w = linelength(s, '\n');
	while (*s)
	{
		while (*s == '\n' && *s)
		{
			if (*s == '\n' && s[1] == '\n')
				wclose(game, 1, 0);
			s++;
		}
		if (i < game->count_h)
		{
			game->map[i] = ft_substr(s, linelength(s, '\n'));
			game->vmap[i++] = ft_substr(s, linelength(s, '\n'));
		}
		while (*s != '\n' && *s)
			s++;
	}
	game->map[i] = NULL;
	game->vmap[i] = NULL;
}

void	read_map(t_vars *game)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(game->path, O_RDONLY);
	if (BUFFER_SIZE < 0 || fd < 0 || BUFFER_SIZE >= INT_MAX)
		return ;
	line = read_line(game, line, fd, 1);
	if (!ft_strlen(line))
	{
		close(fd);
		free(line);
		ft_printf("Empty map file!\n");
		exit(1);
	}
	game->count_h = count_lines(line, '\n');
	game->map = malloc(sizeof(char *) * (game->count_h + 1));
	game->vmap = malloc(sizeof(char *) * (game->count_h + 1));
	map_matrix(game, line);
	close(fd);
	free(line);
}
