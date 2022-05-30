/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:27:30 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/05/25 18:03:35 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/so_long.h"

int	coin_number(t_game *so_long)
{
	int	i;
	int	k;
	int	c;

	i = 0;
	k = 0;
	c = 0;
	while (so_long->map[i])
	{
		k = 0;
		while (so_long->map[i][k] != '\n')
		{
			if (so_long->map[i][k] == 'C')
				c++;
			k++;
		}
		i++;
	}
	return (c);
}

void	error_status(t_game *so_long)
{
	if (so_long->index != 2)
		destroy_win_2(so_long, 1,
			"Lütfen tek seferde bir harita eklenebilir", 0);
	if (so_long->fd == -1)
		destroy_win_2(so_long, 1, "***hata (dosya bulunamadı)***", 0);
	if (so_long->ik == -1)
		destroy_win_2(so_long, 1, "harita .ber uzantılı olmalıdır", 0);
	if (so_long->hk == -1)
		destroy_win_2(so_long, 1,
			"!!!!! hata lütfen harita dizaynını kurallara uygun girin !!!!!!!!",
			0);
	if (so_long->hfk == -1)
		destroy_win_2(so_long, 1,
			"Haritada kurallara uymayan kullanımlar var Lütfen Düzeltin", 0);
}

void	destroy_win_2(t_game *so_long, int durum, char *str, int status)
{
	printf("%s", str);
	free(so_long->map);
	if (status == 1)
	{
		free(so_long->picture);
		free(so_long->picture->imgplayer);
	}
	free(so_long);
	exit(durum);
}

t_img	*insertimgpath(void)
{
	t_img	*picture;

	picture = malloc(sizeof(t_img));
	picture->imgplayer = (char **)malloc(sizeof(char *) * 4);
	picture->imgwall = "./img/tree.xpm";
	picture->imgcoin = "./img/potion.xpm";
	picture->imgdoor = "./img/portal.xpm";
	picture->imgground = "./img/floor.xpm";
	picture->imgplayer[0] = "./img/static/down.xpm";
	picture->imgplayer[1] = "./img/static/up.xpm";
	picture->imgplayer[2] = "./img/static/left.xpm";
	picture->imgplayer[3] = "./img/static/right.xpm";
	return (picture);
}
