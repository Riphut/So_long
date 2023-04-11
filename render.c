/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:29:26 by rkandiyi          #+#    #+#             */
/*   Updated: 2023/03/11 16:33:21 by rkandiyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Initialize images */
void	image_init(t_vars *g)
{
	g->w = 64;
	g->bg = mlx_xpm_file_to_image(g->mlx, BG, &g->w, &g->w);
	g->wall = mlx_xpm_file_to_image(g->mlx, WALL, &g->w, &g->w);
	g->exit = mlx_xpm_file_to_image(g->mlx, EXIT, &g->w, &g->w);
	g->player = mlx_xpm_file_to_image(g->mlx, PLAYER, &g->w, &g->w);
	g->coin = mlx_xpm_file_to_image(g->mlx, COIN, &g->w, &g->w);
	if (g->bg == NULL || g->coin == NULL
		|| g->wall == NULL || g->exit == NULL
		|| g->player == NULL)
	{
		ft_printf("Image does not exist!\n");
		wclose(g, 1, 0);
	}
}

/* Draw images */
static void	draw_img(t_vars *game, void *img, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, img, i, j);
}

void	render(t_vars *game, int i, int j)
{
	while (game->map[++i])
	{
		j = 0;
		game->pos_x = 0;
		while (game->map[i][j])
		{
			draw_img(game, game->bg, game->pos_x, game->pos_y);
			if (game->map[i][j] == '1')
				draw_img(game, game->wall, game->pos_x, game->pos_y);
			else if (game->map[i][j] == 'P')
			{
				draw_img(game, game->player, game->pos_x, game->pos_y);
				game->pi = i;
				game->py = j;
			}
			else if (game->map[i][j] == 'C')
				draw_img(game, game->coin, game->pos_x, game->pos_y);
			else if (game->map[i][j] == 'E')
				draw_img(game, game->exit, game->pos_x, game->pos_y);
			game->pos_x += 64;
			j++;
		}
		game->pos_y += 64;
	}
}
