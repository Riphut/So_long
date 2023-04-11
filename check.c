/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:53:20 by rkandiyi          #+#    #+#             */
/*   Updated: 2023/03/07 14:43:44 by rkandiyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Check if filename is written right*/

#include "so_long.h"

void	check_file(t_vars *game)
{
	int		fd;
	char	*path;

	path = game->path;
	fd = open(path, O_RDONLY);
	if (fd <= 2)
	{
		ft_printf("Map file not found!\n");
		close(fd);
		exit (1);
	}
	path = ft_strchr(path, '.');
	if (ft_strcmp(path, ".ber"))
	{
		ft_printf("Wrong filename bruh!\n");
		close(fd);
		exit(1);
	}
	close(fd);
}

void	check_shape(t_vars *game)
{
	int		i;
	size_t	reflen;

	i = 1;
	reflen = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (reflen != ft_strlen(game->map[i]))
			errormsg(game, 1);
		i++;
	}
}

void	check_char(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!(game->map[i][j] == '1' || game->map[i][j] == 'P' ||
				game->map[i][j] == 'C' || game->map[i][j] == 'E' ||
				game->map[i][j] == '0'))
				errormsg(game, 3);
			j++;
		}
		i++;
	}
}

void	check_wall(t_vars *game, int i, int j)
{
	while (game->map[i])
	{
		if (i == 0 || i == game->count_h - 1)
		{
			j = 0;
			while (game->map[i][j])
			{
				if (game->map[i][j] != '1')
					errormsg(game, 5);
				j++;
			}
		}
		if (game->map[i][0] != '1' || game->map[i][j - 1] != '1')
			errormsg(game, 4);
		i++;
	}
}

void	check_charcount(t_vars *game, int pcount, int ecount, int i)
{
	int	j;

	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				ecount++;
			else if (game->map[i][j] == 'P')
				pcount++;
			else if (game->map[i][j] == 'C')
				game->ccount++;
			j++;
		}
		i++;
	}
	if ((ecount > 1) || (ecount == 0))
		errormsg(game, 5);
	if ((pcount > 1) || (pcount == 0))
		errormsg(game, 6);
	if (game->ccount < 1)
		errormsg(game, 7);
}
