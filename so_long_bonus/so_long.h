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

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct img
{
	char *imgwall;
	char *imgcoin;
	char *imgground;
	char *imgdoor;
	char *imgfire1;
	char *imgfire2;
	char *imgfire3;
	char *imgfire4;
	char **imgplayer;
} img;

typedef struct s_game
{
	void *mlx;
	void *window;
	char *realitive_patch;
	int a;
	int b;
	img *picture;
	int i;
	int k;
	int di;
	int dk;
	int dki;
	int uz_x;
	int uz_y;
	int fd;
	int hk;
	int hfk;
	int ik;
	int pc;
	int dongu;
	int index;
	int coin;
	char **map;
} t_game;
void hata(t_game *so);
ssize_t name_check(char *str);
int uz_y(char *str);
void map(t_game *so_long, char *str);
int chack_map(t_game *so_long, int i, int k, int a);
int char_chack(t_game *so, int k, int a, int i);
void destroy_win_2(t_game *so_long, int durum, char *str, int status);
void error_status(t_game *so_long);
int coin_number(t_game *so_long);
void insertimg(img *piscure, t_game *tmp, int x);
void insertimgxpm(char *path, int x, int y, t_game *tmp);
int keycheck(int keycode, t_game *so_long);
void movement(int x, int y, int i, int k, char char_1, t_game *so_long, int durum);
void write_1(int movement, int coin);
void up(t_game *so_long);
void down(t_game *so_long);
void right(t_game *so_long);
void left(t_game *so_long);
void player(t_game *so_long);
int player_chack(t_game *so);
int keycheck_2(t_game *so_long);
int animation(t_game *so_long);
void anima(t_game *tmp);
void enemy_move(t_game *so_long, int x, int y);
void is_enemy(t_game *so_long, int x, int y);
int animation(t_game *so_long);
img *insertimgpath();
#include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#endif
