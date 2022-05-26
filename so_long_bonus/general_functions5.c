/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:13:40 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/05/22 17:13:41 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void is_enemy2(t_game *so_long, int x, int y)
{
	while (++y < so_long->uz_y-1)
	{
		x = -1;
		while (++x < so_long->uz_x-1)
		{
			if (so_long->map[y][x] == 'N')
				ft_is_move_anim(so_long, x, y);
		}
	}
	so_long->dongu2++;
}

void	ft_is_move_anim(t_game *so_long, int x, int y)
{
	static int i;
	static int a;
	static int b;

	if (so_long->dongu == 3)
	{
		so_long->dongu = 0;
		insertimgxpm(so_long->picture->imgground, x*32, y*32, so_long);
		if(so_long->map[y+1][x]=='0' && a==0)
		{
			//write(1, "*\n", 2);
			so_long->map[y][x] = '0';
			so_long->map[y + 1][x] = 'N';
			i++;
		}
		else if (so_long->map[y-1][x]=='0')
		{
			// write(1, "**\n", 3);
			write(1, ft_itoa(x), 1);
			write(1, "\n", 1);
			write(1, ft_itoa(y), 1);
			write(1, "\n", 1);
			so_long->map[y][x] = '0';
			so_long->map[y-1][x] = 'N';
			a++;
			b++;
			if (a == i)
			{
				write(1, "*", 1);
				a = 0;
				i = 0;
			}
			is_enemy2(so_long, x, y+1);
		}
			
	}
}