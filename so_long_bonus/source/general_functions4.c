/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:31:44 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/05/25 18:01:43 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "../library/so_long.h"

void	movement(int x, int y, char char_1, t_game *so_long)
{
	int	coordinat_x;
	int	coordinat_y;
	int	t;
	int	r;

	r = 1;
	t = 0;
	so_long->map[so_long->i - x][so_long->k - y] = 'P';
	so_long->map[so_long->i - 1][so_long->k - 1] = char_1;
	coordinat_x = (so_long->i - x) * 32;
	coordinat_y = (so_long->k - y) * 32;
	insertimgxpm(so_long->picture->imgplayer[so_long->durum],
		coordinat_y, coordinat_x, so_long);
	coordinat_x = (so_long->i - 1) * 32;
	coordinat_y = (so_long->k - 1) * 32;
	insertimgxpm(so_long->picture->imgground, coordinat_y,
		coordinat_x, so_long);
}

void	write_1(t_game *so_long)
{
	char	*str;
	char	*str1;

	str = ft_itoa(so_long->g_hareket);
	str1 = ft_itoa(so_long->g_coin);
	insertimgxpm(so_long->picture->imgwall, 0, 0, so_long);
	insertimgxpm(so_long->picture->imgwall, 32, 0, so_long);
	insertimgxpm(so_long->picture->imgwall, 64, 0, so_long);
	mlx_string_put(so_long->mlx, so_long->window, 6, 15, 0, "h:");
	mlx_string_put(so_long->mlx, so_long->window, 20, 15, 0, str);
	mlx_string_put(so_long->mlx, so_long->window, 50, 15, 0, "c:");
	mlx_string_put(so_long->mlx, so_long->window, 66, 15, 0, str1);
	free(str);
	free(str1);
}

void	enemy_move(t_game *so_long, int x, int y)
{
	if ((so_long)->map[y][x + 1] == 'P' || (so_long)->map[y][x - 1] == 'P')
		destroy_win_2(so_long, 0, "Yandın", 1);
	else if ((so_long)->map[y][x + 1] == '0')
	{
		insertimgxpm(so_long->picture->imgfire1, (x + 1) * 32, y * 32, so_long);
		insertimgxpm(so_long->picture->imgground, x * 32, y * 32, so_long);
		(so_long)->map[y][x] = '0';
		(so_long)->map[y][x + 1] = 'N';
	}
	else
	{
		insertimgxpm(so_long->picture->imgground, x * 32, y * 32, so_long);
		(so_long)->map[y][x] = '0';
		while ((so_long)->map[y][x] != '1' && x)
			x--;
		if ((so_long)->map[y][x + 1] == 'P')
			destroy_win_2(so_long, 0, "Yandın", 1);
		insertimgxpm(so_long->picture->imgfire1, (x + 1) * 32, y * 32, so_long);
		(so_long)->map[y][x + 1] = 'N';
	}
}

int	animation(t_game *so_long)
{
	(so_long)->dki++;
	(so_long)->enemy_speed++;
	if ((so_long)->dki >= 3000)
	{
		is_enemy(so_long, -1, -1);
		(so_long)->dki = 0;
	}
	if (so_long->enemy_speed >= 2000)
	{
		is_enemy_move(so_long, -1, -1);
		so_long->enemy_speed = 0;
	}
	return (0);
}

void	is_enemy_move(t_game *so_long, int x, int y)
{
	while (++y < so_long->uz_y - 1)
	{
		x = -1;
		while (++x < so_long->uz_x - 1)
		{
			if (so_long->map[y][x] == 'N')
			{
				enemy_move(so_long, x, y);
				x++;
			}
		}
	}
}
