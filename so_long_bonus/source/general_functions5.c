/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:16:20 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/05/25 18:02:12 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "../library/so_long.h"

void	l(t_game *so, int k, int a)
{
	if (so->map[k][a] == 'P')
		so->i++;
	if (so->map[k][a] == 'C')
		so->b++;
	if (so->map[k][a] == 'E')
		so->g++;
	if (so->map[k][a] == 'N')
		so->n++;
}

int	d(t_game *so, int k, int a)
{
	while (a <= so->uz_x - 2)
	{
		if (so->map[0][a] != '1')
			return (-1);
		if (so->map[so->uz_y - 2][a] != '1')
			return (-1);
		a++;
	}
	a = 0;
	while (a < so->uz_y - 2)
	{
		if (so->map[a][0] != '1' || so->map[a][so->uz_x - 2] != '1')
			return (-1);
		a++;
	}
	a = 0;
	while (a < so->uz_x - 2)
	{
		l(so, k, a);
		a++;
	}
	return (0);
}

void	enemy_anim(t_game *so_long, int x, int y)
{
	if (so_long->dongu == 0)
		insertimgxpm(so_long->picture->imgfire1,
			x * 32, y * 32, so_long);
	if (so_long->dongu == 1)
		insertimgxpm(so_long->picture->imgfire2,
			x * 32, y * 32, so_long);
	if (so_long->dongu == 2)
		insertimgxpm(so_long->picture->imgfire3,
			x * 32, y * 32, so_long);
	if (so_long->dongu == 3)
	{
		insertimgxpm(so_long->picture->imgfire4,
			x * 32, y * 32, so_long);
		so_long->dongu = 0;
	}
}

void	is_enemy(t_game *so_long, int x, int y)
{
	while (++y < so_long->uz_y - 1)
	{
		x = -1;
		while (++x < so_long->uz_x - 1)
		{
			if (so_long->map[y][x] == 'N')
				enemy_anim(so_long, x, y);
		}
	}
	so_long->dongu++;
}

void	assignment(t_game *so_long, char **data, int index)
{
	so_long->g_coin = 0;
	so_long->g_hareket = 0;
	so_long->g = 0;
	so_long->b = 0;
	so_long->n = 0;
	so_long->i = 0;
	so_long->enemy_speed = 0;
	so_long->durum = 0;
	so_long->index = index;
	so_long->ik = name_check(&data[1][2]);
	if (so_long->ik == -1)
		error_status(so_long);
	so_long->uz_y = uz_y(&data[1][2]);
	map(so_long, &data[1][2]);
	so_long->uz_x = strlen(so_long->map[0]);
	so_long->hfk = char_chack(so_long, 0, 0);
	so_long->hk = chack_map(so_long, 0, 0, 0);
	so_long->coin = coin_number(so_long);
	error_status(so_long);
	so_long->picture = insertimgpath();
	so_long->mlx = mlx_init();
	so_long->window = mlx_new_window(so_long->mlx,
			(so_long->uz_x - 1) * 32, (so_long->uz_y - 1) * 32, "SO_LONG");
	insertimg(so_long->picture, so_long);
}
