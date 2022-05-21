/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kontrol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:02:54 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/04/27 19:02:56 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
int g_coin = 0;
int g_hareket = 0;
void up(t_game *so_long)
{
	player(so_long);
	if (so_long->map[so_long->i - 2][so_long->k - 1] == '0')
	{
		movement(2, 1, so_long->i, so_long->k, '0', so_long, 1);
		g_hareket++;
		write_1(g_hareket, g_coin);
	}
	else if (so_long->map[so_long->i - 2][so_long->k - 1] == 'C')
	{
		movement(2, 1, so_long->i, so_long->k, '0', so_long, 1);
		g_coin++;
		g_hareket++;
		write_1(g_hareket, g_coin);
		
	}
	else if(so_long->map[so_long->i - 2][so_long->k-1] == 'E')
	{
		if(so_long->coin==g_coin)
			destroy_win_2(so_long,0,"Oyun Bitti Tebrikler", 1);
		else
			write(1, "Lütfen Tüm İksirleri toplayın\n", 34);
	}
}

void down(t_game *so_long)
{

	player(so_long);

	if (so_long->map[so_long->i][so_long->k-1] == '0')
	{
		movement(0, 1, so_long->i, so_long->k, '0', so_long, 0);
		g_hareket++;
		write_1(g_hareket, g_coin);
	}
	else if(so_long->map[so_long->i][so_long->k-1] == 'C')
	{
		movement(0, 1, so_long->i, so_long->k, '0', so_long, 0);
		g_coin++;
		g_hareket++;
		write_1(g_hareket, g_coin);
	}
	else if(so_long->map[so_long->i][so_long->k-1] == 'E')
	{
		if(so_long->coin==g_coin)
			destroy_win_2(so_long,0,"Oyun Bitti Tebrikler", 1);
		else
			write(1, "Lütfen Tüm İksirleri toplayın\n", 34);
	}
}

void right(t_game *so_long)
{
	player(so_long);

	if (so_long->map[so_long->i - 1][so_long->k] == '0')
	{
		movement(1, 0, so_long->i, so_long->k, '0', so_long, 3);
		g_hareket++;
		write_1(g_hareket, g_coin);
	}
		
	else if (so_long->map[so_long->i - 1][so_long->k] == 'C')
	{
		
		movement(1, 0, so_long->i, so_long->k, '0', so_long, 3);
		g_coin++;
		g_hareket++;
		write_1(g_hareket, g_coin);
	}
	else if(so_long->map[so_long->i - 1][so_long->k] == 'E')
	{
		if(so_long->coin==g_coin)
			destroy_win_2(so_long,0,"Oyun Bitti Tebrikler", 1);
		else
			write(1, "Lütfen Tüm İksirleri toplayın\n", 34);
	}
}

void left(t_game *so_long)
{
	player(so_long);
	if (so_long->map[so_long->i-1][so_long->k-2] == '0')
	{
		movement(1, 2, so_long->i, so_long->k, '0', so_long, 2);
		g_hareket++;
		write_1(g_hareket, g_coin);
	}
	else if (so_long->map[so_long->i - 1][so_long->k - 2] == 'C')
	{
		movement(1, 2, so_long->i, so_long->k, '0', so_long, 2);
		g_coin++;
		g_hareket++;
		write_1(g_hareket, g_coin);
	}
	else if(so_long->map[so_long->i - 1][so_long->k-2] == 'E')
	{
		if(so_long->coin==g_coin)
			destroy_win_2(so_long,0,"Oyun Bitti Tebrikler", 1);
		else
			write(1, "Lütfen Tüm İksirleri toplayın\n", 34);
	}
}

void player(t_game *so_long)
{
	int anahtar;
	anahtar = 0;
	so_long->i = 0;
	while (so_long->map[so_long->i] && anahtar == 0)
	{
		so_long->k = 0;
		while (so_long->map[so_long->i][so_long->k] && anahtar == 0)
		{
			if (so_long->map[so_long->i][so_long->k] == 'P')
				anahtar = 1;
			so_long->k++;
		}
		so_long->i++;
	}
}