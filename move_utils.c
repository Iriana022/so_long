/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:52:35 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/06 12:51:47 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data mlx, char direction, t_coord pos)
{
	if (direction == 'l')
	{
		mlx.map[pos.y][pos.x] = '0';
		mlx.map[pos.y][pos.x - 1] = 'P';
	}
	else if (direction == 'r')
	{
		mlx.map[pos.y][pos.x] = '0';
		mlx.map[pos.y][pos.x + 1] = 'P';
	}
	else if (direction == 'u')
	{
		mlx.map[pos.y][pos.x] = '0';
		mlx.map[pos.y - 1][pos.x] = 'P';
	}
	else if (direction == 'd')
	{
		mlx.map[pos.y][pos.x] = '0';
		mlx.map[pos.y + 1][pos.x] = 'P';
	}
}

int	invalid_move(int x, int y, char **map)
{
	return (x < 0 || y < 0 || x > ft_strlen(map[0]) - 1 || y > ft_len(map) - 1);
}

void	put_img(void *mlx, void *win, void *img, t_coord p)
{
	mlx_put_image_to_window(mlx, win, img, p.x, p.y);
}

void	put_pos(char **matrix_map, t_data mlx)
{
	t_coord	point;
	int		x;
	int		y;

	y = -1;
	while (matrix_map[++y] != NULL)
	{
		x = -1;
		while (matrix_map[y][++x] != '\0')
		{
			point.x = x * 48;
			point.y = y * 48;
			if (matrix_map[y][x] == 'P')
				put_img(mlx.mlx, mlx.win, mlx.img[0], point);
			else if (matrix_map[y][x] == '1')
				put_img(mlx.mlx, mlx.win, mlx.img[1], point);
			else if (matrix_map[y][x] == 'C')
				put_img(mlx.mlx, mlx.win, mlx.img[2], point);
			else if (matrix_map[y][x] == 'E')
			{
				if (mlx.nb_collectible == 0)
					put_img(mlx.mlx, mlx.win, mlx.img[3], point);
				else
					put_img(mlx.mlx, mlx.win, mlx.img[4], point);
			}
			else if (matrix_map[y][x] == '0')
				put_img(mlx.mlx, mlx.win, mlx.img[4], point);
		}
	}
}

int	sum_collectible(t_data *mlx)
{
	int	x;
	int	y;

	mlx->nb_collectible = 0;
	y = 0;
	while (mlx->map[y] != NULL)
	{
		x = 0;
		while (mlx->map[y][x] != '\0')
		{
			if (mlx->map[y][x] == 'C')
				mlx->nb_collectible++;
			x++;
		}
		y++;
	}
	return (mlx->nb_collectible);
}
