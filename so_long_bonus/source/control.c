/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:02:54 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/05/25 17:59:17 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "../library/so_long.h"

void	up(t_game	*so_long)
{
	player (so_long);
	if (so_long->map[so_long->i - 2][so_long->k - 1] == '0')
	{
		so_long->durum = 1;
		movement(2, 1, '0', so_long);
		so_long->g_hareket++;
		write_1(so_long);
	}
	else if (so_long->map[so_long->i - 2][so_long->k - 1] == 'C')
	{
		so_long->durum = 1;
		movement(2, 1, '0', so_long);
		so_long->g_coin++;
		so_long->g_hareket++;
		write_1 (so_long);
	}
	else if (so_long->map[so_long->i - 2][so_long->k - 1] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
			destroy_win_2 (so_long, 0, "Oyun Bitti Tebrikler", 1);
		else
			write (1, "Lütfen Tüm İksirleri toplayın\n", 34);
	}
	else if (so_long->map[so_long->i - 2][so_long->k - 1] == 'N')
		destroy_win_2 (so_long, 0, "Oyun Bitti Yandınız", 1);
}

void	down(t_game	*so_long)
{
	player (so_long);
	if (so_long->map[so_long->i][so_long->k - 1] == '0')
	{
		so_long->durum = 0;
		movement(0, 1, '0', so_long);
		so_long->g_hareket++;
		write_1(so_long);
	}
	else if (so_long->map[so_long->i][so_long->k - 1] == 'C')
	{
		so_long->durum = 0;
		movement(0, 1, '0', so_long);
		so_long->g_coin++;
		so_long->g_hareket++;
		write_1(so_long);
	}
	else if (so_long->map[so_long->i][so_long->k - 1] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
			destroy_win_2 (so_long, 0, "Oyun Bitti Tebrikler", 1);
		else
			write (1, "Lütfen Tüm İksirleri toplayın\n", 34);
	}
	else if (so_long->map[so_long->i][so_long->k - 1] == 'N')
		destroy_win_2 (so_long, 0, "Oyun Bitti Yandınız", 1);
}

void	right(t_game	*so_long)
{
	player (so_long);
	if (so_long->map[so_long->i - 1][so_long->k] == '0')
	{
		so_long->durum = 3;
		movement(1, 0, '0', so_long);
		so_long->g_hareket++;
		write_1 (so_long);
	}
	else if (so_long->map[so_long->i - 1][so_long->k] == 'C')
	{
		so_long->durum = 3;
		movement(1, 0, '0', so_long);
		so_long->g_coin++;
		so_long->g_hareket++;
		write_1 (so_long);
	}
	else if (so_long->map[so_long->i - 1][so_long->k] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
			destroy_win_2 (so_long, 0, "Oyun Bitti Tebrikler", 1);
		else
			write (1, "Lütfen Tüm İksirleri toplayın\n", 34);
	}
	else if (so_long->map[so_long->i - 1][so_long->k] == 'N')
		destroy_win_2 (so_long, 0, "Oyun Bitti Yandınız", 1);
}

void	left(t_game	*so_long)
{
	player (so_long);
	if (so_long->map[so_long->i - 1][so_long->k - 2] == '0')
	{
		so_long->durum = 2;
		movement(1, 2, '0', so_long);
		so_long->g_hareket++;
		write_1(so_long);
	}
	else if (so_long->map[so_long->i - 1][so_long->k - 2] == 'C')
	{
		so_long->durum = 2;
		movement(1, 2, '0', so_long);
		so_long->g_coin++;
		so_long->g_hareket++;
		write_1(so_long);
	}
	else if (so_long->map[so_long->i - 1][so_long->k - 2] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
			destroy_win_2(so_long, 0, "Oyun Bitti Tebrikler", 1);
		else
			write(1, "Lütfen Tüm İksirleri toplayın\n", 34);
	}
	else if (so_long->map[so_long->i - 1][so_long->k - 2] == 'N')
		destroy_win_2(so_long, 0, "Oyun Bitti Yandınız", 1);
}

void	player(t_game *so_long)
{
	int	anahtar;

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
