/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:39:17 by rkandiyi          #+#    #+#             */
/*   Updated: 2023/03/11 16:30:08 by rkandiyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int	traversed_path(t_vars *game, int i, int j)
// {
// 	if (game->vmap[i][j] == 'C')
// 		game->vcount++;
// 	if (game->vmap[i][j] != '1' && game->vmap[i][j] != 'X'
// 		&& (game->vmap[i][j] == '0' || game->vmap[i][j] == 'C'))
// 	{
// 		game->vmap[i][j] = 'X';
// 		return (1);
// 	}
// 	return (0);
// }

void	valid_path(t_vars *game, int i, int j)
{
	if (game->vmap[i][j] == 'C')
		game->vcount++;
	if (game->vmap[i][j] == 'E')
		game->vexit++;
	if (game->vmap[i][j] == '1' || game->vmap[i][j] == 'X')
		return ;
	game->vmap[i][j] = 'X';
	// if (traversed_path(game, i - 1, j))
		valid_path(game, (i - 1), j);
	// if (traversed_path(game, i, j + 1))
		valid_path(game, i, (j + 1));
	// if (traversed_path(game, i + 1, j))
		valid_path(game, (i + 1), j);
	// if (traversed_path(game, i, j - 1))
		valid_path(game, i, (j - 1));
	// return ;
}
