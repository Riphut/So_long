/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:59:46 by rkandiyi          #+#    #+#             */
/*   Updated: 2023/03/07 14:26:18 by rkandiyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image(t_vars *game)
{
	mlx_destroy_image(game->mlx, game->bg);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->exit);
}

/* Window close */
/* flag = 1 -> delete map, window & destroy image */
/* flag = 0 -> free and exit */
int	wclose(t_vars *game, int x, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		free(game->map);
		free(game->vmap);
		ft_printf("Not a valid map!\n");
		exit(x);
	}
	while (game->map[i])
	{
		free(game->map[i]);
		free(game->vmap[i++]);
	}
	free(game->map);
	free(game->vmap);
	if (flag == 1)
	{
		destroy_image(game);
		mlx_destroy_window(game->mlx, game->win);
	}
	ft_printf("Bye Bye");
	exit(x);
}
