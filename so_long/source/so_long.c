/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:43:30 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/05/26 12:21:18 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/so_long.h"

int	main(int index, char **data)
{
	t_game	*so_long;

	if (index == 2)
	{
		so_long = malloc(sizeof(t_game));
		assignment(so_long, data, index);
		mlx_hook(so_long->window, 17, (0L), keycheck_2, so_long);
		mlx_hook(so_long->window, 2, 1L << 0, keycheck, so_long);
		mlx_loop(so_long->mlx);
	}
	else
	{
		printf("lütfen Harita girin");
	}
	return (0);
}
