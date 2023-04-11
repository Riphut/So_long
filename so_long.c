/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:42:42 by rkandiyi          #+#    #+#             */
/*   Updated: 2023/03/11 16:29:58 by rkandiyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_position(t_vars *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->pi = i;
				game->py = j;
				return ;
			}
			j++;
		}
	}
}

/* Open window and initialize game */
void	game_init(t_vars *game, char *s)
{
	game->ccount = 0;
	game->pos_y = 0;
	game->move_count = 0;
	game->vcount = 0;
	game->vexit = 0;
	check_shape(game);
	check_char(game);
	check_wall(game, 0, 0);
	check_charcount(game, 0, 0, 0);
	game->win_h = (game->count_h) * 64;
	game->win_w = (game->count_w) * 64;
	if (game->win_h > MAX_WINH || game->win_w > MAX_WINW)
		errormsg(game, 2);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win_w, game->win_h, s);
	player_position(game);
	valid_path(game, game->pi, game->py);
	if (game->vcount != game->ccount || game->vexit != 1)
		errormsg(game, 8);
	image_init(game);
	render(game, -1, 0);
	ft_printf("Welcome to the game of life!\n");
}

int	main(int ac, char **av)
{
	t_vars	game;

	if (ac != 2)
	{
		ft_printf("Error!\nWrite it properly loser!\n");
		ft_printf("Here! It should be like: ./so_long maps/lvl1.ber\n");
		exit(1);
	}
	game.path = av[1];
	check_file(&game);
	read_map(&game);
	game_init(&game, "This took so_long!");
	mlx_hook(game.win, 2, 1L << 0, hook_manager, &game);
	mlx_hook(game.win, 17, 1L << 0, wclose, &game);
	mlx_loop(game.mlx);
	return (0);
}
