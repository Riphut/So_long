/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:05:34 by rkandiyi          #+#    #+#             */
/*   Updated: 2023/03/11 16:20:52 by rkandiyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
/* Declare some default variables */
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define BUFFER_SIZE 2048
# define MAX_WINH 1080
# define MAX_WINW 1920
# define BG "./images/floor.xpm"
# define WALL "./images/wall.xpm"
# define EXIT "./images/exit.xpm"
# define PLAYER "./images/ply.xpm"
# define COIN "./images/coin.xpm"

/* header files */
# include <stdarg.h>
# include <unistd.h>	//read, write
# include <fcntl.h>		//open, close
# include <stdio.h>		//perror
# include <string.h>	//strerror
# include <stdlib.h>	//malloc, free, exit
# include <limits.h>	//limits.h
# include "./mlx/mlx.h"	//minilibx files

/* structs */
typedef struct s_vars {
	void		*mlx;
	void		*win;
	char		**map;
	char		**vmap;
	char		*path;
	int			w;
	int			count_w;
	int			count_h;
	int			ccount;
	int			vcount;
	int			vexit;
	int			win_w;
	int			win_h;
	int			pi;
	int			py;
	int			pos_x;
	int			pos_y;
	int			move_count;
	void		*bg;
	void		*coin;
	void		*exit;
	void		*player;
	void		*wall;
}				t_vars;

/* Function prototypes */
/* ft_printf.c*/
int		ft_printf(const char *s, ...);
/* so_long.c*/
void	game_init(t_vars *game, char *s);
/* check_utils.c */
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
/* gnl_utils.c */
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
/* msg.c */
void	errormsg(t_vars *game, int flag);
/* free.c */
void	destroy_image(t_vars *game);
int		wclose(t_vars *game, int x, int flag);
/* maps.c */
void	read_map(t_vars *game);
/* render.c */
void	image_init(t_vars *game);
void	render(t_vars *game, int i, int j);
/* move_player.c */
int		hook_manager(int keycode, t_vars *game);
void	move_player(t_vars *game, int i, int j);
/* check.c */
void	check_file(t_vars *game);
void	check_shape(t_vars *game);
void	check_charcount(t_vars *game, int pcount, int ecount, int i);
void	check_char(t_vars *game);
void	check_wall(t_vars *game, int i, int j);
/* vaid_path.c */
void	valid_path(t_vars *game, int i, int j);

#endif
