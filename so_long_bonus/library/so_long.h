/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:50:16 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/05/07 10:50:17 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	"minilibx/mlx.h"
# include	"libft/libft.h"
# include	"get_next_line/get_next_line.h"
# include	<fcntl.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>

typedef struct s_img
{
	char	*imgwall;
	char	*imgcoin;
	char	*imgground;
	char	*imgdoor;
	char	*imgfire1;
	char	*imgfire2;
	char	*imgfire3;
	char	*imgfire4;
	char	**imgplayer;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*window;

	char	*realitive_patch;
	char	**map;

	int		a;
	int		b;
	int		durum;
	int		g_coin;
	int		g_hareket;
	int		b1;
	int		g;
	int		enemy_speed;
	int		n;
	int		i;
	int		k;
	int		di;
	int		dk;
	int		dki;
	int		dki2;
	int		uz_x;
	int		uz_y;
	int		fd;
	int		an;
	int		hfk;
	int		ik;
	int		dongu;
	int		dongu2;
	int		index;
	int		coin;
	t_img	*picture;
}	t_game;

int		uz_y(char *str);
int		chack_map(t_game *so_long, int i, int k, int a);
int		char_chack(t_game *so, int k, int a);
int		coin_number(t_game *so_long);
int		keycheck(int keycode, t_game *so_long);
int		keycheck_2(t_game *so_long);
int		animation(t_game *so_long);
int		animation(t_game *so_long);
int		d(t_game *so, int k, int a);
int		name_check(char *str);

void	movement(int x, int y, char char_1, t_game *so_long);
void	write_1(t_game *so_long);
void	up(t_game *so_long);
void	down(t_game *so_long);
void	right(t_game *so_long);
void	left(t_game *so_long);
void	player(t_game *so_long);
void	map(t_game *so_long, char *str);
void	destroy_win_2(t_game *so_long, int durum, char *str, int status);
void	error_status(t_game *so_long);
void	insertimg(t_img *piscure, t_game *tmp);
void	insertimgxpm(char *path, int x, int y, t_game *tmp);
void	enemy_anim(t_game *so_long, int x, int y);
void	is_enemy(t_game *so_long, int x, int y);
void	is_enemy_move(t_game *so_long, int x, int y);
void	assignment(t_game *so_long, char **data, int index);
t_img	*insertimgpath(void);
#endif
