/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:49:03 by rkandiyi          #+#    #+#             */
/*   Updated: 2023/03/07 13:28:52 by rkandiyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hook_manager(int keycode, t_vars *game)
{
	if ((keycode == 126) || (keycode == KEY_W))
		move_player(game, -1, 0);
	else if ((keycode == 125) || (keycode == KEY_S))
		move_player(game, 1, 0);
	else if ((keycode == 123) || (keycode == KEY_A))
		move_player(game, 0, -1);
	else if ((keycode == 124) || (keycode == KEY_D))
		move_player(game, 0, 1);
	else if (keycode == KEY_ESC)
		wclose(game, 0, 1);
	game->pos_y = 0;
	destroy_image(game);
	image_init(game);
	render(game, -1, 0);
	return (0);
}

/* UP => x = -1, y = 0
   DOWN => x = 1, y = 0
   LEFT => x = 0, y = -1
   RIGHT => x = 0, y = 1 */
void	move_player(t_vars *game, int x, int y)

{
	if (game->map[game->pi + x][game->py + y] == 'C')
	{
		game->ccount--;
		ft_printf("Project completed successfully!\n");
	}
	if (game->map[game->pi + x][game->py + y] == 'E' && game->ccount == 0)
	{
		game->map[game->pi][game->py] = '0';
		game->move_count++;
		ft_printf("You win!\n");
		wclose(game, 0, 1);
	}
	else if (game->map[game->pi + x][game->py + y] == 'E' && game->ccount != 0)
		ft_printf("Complete all the projects! Game ain't over lol\n");
	else if (game->map[game->pi + x][game->py + y] == '1')
		ft_printf("Can't move ouch!\n");
	else if ((game->map[game->pi + x][game->py + y] == '0')
			|| (game->map[game->pi + x][game->py + y] == 'C'))
	{
		game->map[game->pi + x][game->py + y] = 'P';
		game->map[game->pi][game->py] = '0';
		game->move_count++;
		ft_printf("No: of moves: %d\n", game->move_count);
	}
}
