/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:43:30 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/05/12 16:43:31 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int index, char **data)
{
	//harita içerisinde P C E kontrolü yap en ax birer tane olsun
	if(index==2)
	{
		t_game *so_long;
		so_long = malloc(sizeof(t_game));
		so_long->ik = name_check(&data[1][2]);
		so_long->uz_y = uz_y(&data[1][2]);
		so_long->index = index;
		map(so_long, &data[1][2]);
		so_long->uz_x = ft_strlen(so_long->map[0]);
		so_long->hk = chack_map(so_long, 0, 0, 0);
		so_long->hfk = char_chack(so_long, 0, 0, 0);
		so_long->coin = coin_number(so_long);
		hata(so_long);
		error_status(so_long);
		so_long->picture = insertimgpath();
		so_long->mlx = mlx_init();
		so_long->window = mlx_new_window(so_long->mlx, (so_long->uz_x - 1) * 32, (so_long->uz_y-1) * 32, "SO_LONG");
		insertimg(so_long->picture, so_long, 0);
		mlx_hook(so_long->window, 17, (0L),keycheck, so_long);
		mlx_hook(so_long->window, 2, 1L << 0,keycheck, so_long);
		mlx_loop(so_long->mlx);
	}
	else
	{
		printf("lütfen Harita girin");
	}
	return (0);
}
