/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:49:47 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/05/18 18:49:48 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
void insertimgxpm(char *path,int x, int y, t_game *tmp)
{
	void *img;
	img = mlx_xpm_file_to_image(tmp->mlx, path, &tmp->a, &tmp->b);
	mlx_put_image_to_window(tmp->mlx, tmp->window, img, x, y);
}

// void insertimgxpm2(char *path,int x, int y, t_game *tmp)
// {
// 	mlx_destroy_image(tmp->mlx, tmp->img);
// 	tmp->img = mlx_xpm_file_to_image(tmp->mlx, path, &tmp->a, &tmp->b);
// 	mlx_put_image_to_window(tmp->mlx, tmp->window, tmp->img, x, y);
// }

void insertimg(img *piscure, t_game *tmp, int x)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (tmp->map[i])
	{
		k = 0;
		while (tmp->map[i][k] != '\n')
		{
			if (tmp->map[i][k] == '1')
				insertimgxpm(piscure->imgwall, k * 32, i*32, tmp);
			else if (tmp->map[i][k] == '0')
				insertimgxpm(piscure->imgground, k * 32, i*32, tmp);
			else if (tmp->map[i][k] == 'C')
				insertimgxpm(piscure->imgcoin, k * 32, i*32, tmp);
			else if (tmp->map[i][k] == 'E')
				insertimgxpm(piscure->imgdoor, k * 32, i*32, tmp);
			else if (tmp->map[i][k] == 'P')
				insertimgxpm(piscure->imgplayer[x], k * 32, i * 32, tmp);
			else if (tmp->map[i][k] == 'N')
				insertimgxpm(piscure->imgfire1, k * 32, i * 32, tmp);
			else
				destroy_win_2(tmp,1,"Hata Lütfen Haritayı Kontrol Edin ya haritanın sonuna enter koymayı unuttunuz yada Haritada olmaması Gerken Başka Bir Karakter Var", 1);
			k++;
		}
		i++;
	}
}

int	keycheck(int keycode,t_game *so_long)
{
	if (keycode == 53)
	{
		destroy_win_2(so_long,0,"Program Basarılı Bir Şekilde Kapatıldı",1);
	}
	if(keycode == 13)
	{
		up(so_long);
	}
	if(keycode == 1)
	{
		down(so_long);
	}
	if(keycode==2)
	{
		right(so_long);
	}
	if(keycode==0)
	{
		left(so_long);
	}
	return (0);
}

int	keycheck_2(t_game *so_long)
{
	destroy_win_2(so_long, 0, "Program Basarılı Bir Şekilde Kapatıldı",1);
	return (0);
}