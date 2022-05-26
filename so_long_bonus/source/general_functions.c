/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:50:37 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/05/25 18:00:17 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "../library/so_long.h"

int	name_check(char *str)
{
	int	uz;

	uz = open(str, O_RDONLY);
	close(uz);
	if (uz == -1)
		return (-1);
	else
	{
		uz = 0;
		str = ft_strchr(str, '.');
		if (str == NULL)
			return (-1);
		uz = ft_strlen(str);
		if (uz == 4 && ft_strnstr(str, ".ber", 4))
			return (0);
	}
	return (-1);
}

int	uz_y(char *str)
{
	int		fd;
	int		i;
	char	*str1;

	str1 = "NULL";
	i = 0;
	fd = open(str, O_RDONLY);
	while (str1 != NULL)
	{
		str1 = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

void	map(t_game *so_long, char *str)
{
	int	i;

	i = 0;
	so_long->fd = open(str, O_RDONLY);
	so_long->map = malloc(sizeof(char *) * so_long->uz_y -1);
	while (so_long->uz_y -1 >= i)
	{
		so_long->map[i] = get_next_line(so_long->fd);
		i++;
	}
	close(so_long->fd);
}

int	chack_map(t_game *so_long, int i, int k, int a)
{
	int	*uz;

	uz = malloc(so_long->uz_y * sizeof(int));
	while (i <= so_long->uz_y - 2)
	{
		uz[i] = ft_strlen(so_long->map[i]);
		i++;
	}
	while (k <= i)
	{
		while (a < i)
		{
			if (uz[k] == uz[a])
				a++;
			else
			{
				free(uz);
				return (-1);
			}
		}
		k++;
	}
	free(uz);
	return (0);
}

int	char_chack(t_game *so, int k, int a)
{
	int	de;

	de = 0;
	while (k < so->uz_y - 1)
	{
		de = d(so, k, a);
		k++;
	}
	if (de == -1)
		return (-1);
	if (so->i != 1 || so->g != 1 || so->b == 0 || so->n == 0)
		return (-1);
	return (0);
}
