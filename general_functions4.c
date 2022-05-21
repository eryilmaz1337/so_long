/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:31:44 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/05/20 17:31:46 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void movement(int x, int y, int i, int k, char char_1, t_game *so_long, int durum)
{
	int t;
	int r;

	r = 1;
	t = 0;
	so_long->map[i - x][k - y] = 'P';
	so_long->map[i-1][k-1] = char_1;
	int coordinat_x;
	int coordinat_y;
	coordinat_x = (i - x) * 32;
	coordinat_y = (k - y) * 32;
	insertimgxpm(so_long->picture->imgplayer[durum], coordinat_y, coordinat_x, so_long);
	coordinat_x = (i - 1) * 32;
	coordinat_y = (k - 1) * 32;
	insertimgxpm(so_long->picture->imgground, coordinat_y, coordinat_x, so_long);
}

void write_1(int movement,int coin)
{
	ft_putstr_fd("\033[0;96mtoplam hamle sayısı=", 1);
	ft_putnbr_fd(movement, 1);
	write(1, " ", 1);
	ft_putstr_fd("toplam coin sayısı=", 1);
	ft_putnbr_fd(coin, 1);
	write(1, "\n", 1);
}