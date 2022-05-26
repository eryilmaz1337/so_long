/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:49:47 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/05/25 18:01:29 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "../library/so_long.h"

void	insertimgxpm(char *path, int x, int y, t_game *tmp)
{
	void	*img;

	img = mlx_xpm_file_to_image(tmp->mlx, path, &tmp->a, &tmp->b1);
	mlx_put_image_to_window(tmp->mlx, tmp->window, img, x, y);
}

void	fi(t_img *piscure, t_game *tmp, int i, int k)
{
	if (tmp->map[i][k] == '1')
		insertimgxpm(piscure->imgwall, k * 32, i * 32, tmp);
	else if (tmp->map[i][k] == '0')
		insertimgxpm(piscure->imgground, k * 32, i * 32, tmp);
	else if (tmp->map[i][k] == 'C')
		insertimgxpm(piscure->imgcoin, k * 32, i * 32, tmp);
	else if (tmp->map[i][k] == 'E')
		insertimgxpm(piscure->imgdoor, k * 32, i * 32, tmp);
	else if (tmp->map[i][k] == 'P')
		insertimgxpm(piscure->imgplayer[tmp->durum], k * 32, i * 32, tmp);
	else if (tmp->map[i][k] == 'N')
		insertimgxpm(piscure->imgfire1, k * 32, i * 32, tmp);
	else
		destroy_win_2(tmp, 1, "Hata Lütfen Haritayı Kontrol Edin", 1);
}

void	insertimg(t_img *piscure, t_game *tmp)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (tmp->map[i])
	{
		k = 0;
		while (tmp->map[i][k] != '\n')
		{
			fi(piscure, tmp, i, k);
			k++;
		}
		i++;
	}
}

int	keycheck(int keycode, t_game *so_long)
{
	if (keycode == 53)
	{
		destroy_win_2(so_long, 0, "Program Basarılı Bir Şekilde Kapatıldı", 1);
	}
	if (keycode == 13)
	{
		up(so_long);
	}
	if (keycode == 1)
	{
		down(so_long);
	}
	if (keycode == 2)
	{
		right(so_long);
	}
	if (keycode == 0)
	{
		left(so_long);
	}
	return (0);
}

int	keycheck_2(t_game *so_long)
{
	destroy_win_2(so_long, 0, "Program Basarılı Bir Şekilde Kapatıldı", 1);
	return (0);
}
