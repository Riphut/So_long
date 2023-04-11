/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:42:23 by rkandiyi          #+#    #+#             */
/*   Updated: 2023/03/07 14:45:35 by rkandiyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* Error message */
void	errormsg(t_vars *game, int flag)
{
	ft_printf("Error: ");
	if (flag == 1)
	{
		ft_printf("Map is not rectangular!\n");
		exit(1);
	}
	else if (flag == 2)
		ft_printf("Not a valid window size. Maximum size: 1920 x 1080.\n");
	else if (flag == 3)
		ft_printf("Only 0, 1, P, C & E allowed in the map!\n");
	else if (flag == 4)
		ft_printf("Map is not surrounded by walls!\n");
	else if (flag == 5)
		ft_printf("You should have of one exit.\n");
	else if (flag == 6)
		ft_printf("You should have one player.\n");
	else if (flag == 7)
		ft_printf("The map contains no collectibles!\n");
	else if (flag == 8)
		ft_printf("The map does not have a valid path!\n");
	wclose(game, 1, 2);
}
