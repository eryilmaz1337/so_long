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

void	write_1(int movement, int coin)
{
	ft_putstr_fd("\033[0;96mtoplam hamle sayısı=", 1);
	ft_putnbr_fd(movement, 1);
	write(1, " ", 1);
	ft_putstr_fd("toplam coin sayısı=", 1);
	ft_putnbr_fd(coin, 1);
	write(1, "\n", 1);
}

void	l(t_game *so, int k, int a)
{
	if (so->map[k][a] == 'P')
		so->i++;
	if (so->map[k][a] == 'C')
		so->b++;
	if (so->map[k][a] == 'E')
		so->g++;
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

void	assignment(t_game *so_long, char **data, int index)
{
	so_long->g_coin = 0;
	so_long->index = index;
	so_long->g_hareket = 0;
	so_long->g = 0;
	so_long->b = 0;
	so_long->i = 0;
	so_long->durum = 0;
	so_long->ik = name_check(&data[1][2]);
	if (so_long->ik == -1)
		error_status(so_long);
	so_long->uz_y = uz_y(&data[1][2]);
	map(so_long, &data[1][2]);
	so_long->uz_x = strlen(so_long->map[0]);
	so_long->hk = chack_map(so_long, 0, 0, 0);
	so_long->hfk = char_chack(so_long, 0, 0);
	so_long->coin = coin_number(so_long);
	error_status(so_long);
	so_long->picture = insertimgpath();
	so_long->mlx = mlx_init();
	so_long->window = mlx_new_window(so_long->mlx,
			(so_long->uz_x - 1) * 32, (so_long->uz_y - 1) * 32, "SO_LONG");
	insertimg(so_long->picture, so_long);
}
