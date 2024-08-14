/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:52:35 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/14 12:11:28 by irazafim         ###   ########.fr       */
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
	t_coord	curr_pos;

	curr_pos.y = -1;
	while (matrix_map[++curr_pos.y] != NULL)
	{
		curr_pos.x = -1;
		while (matrix_map[curr_pos.y][++curr_pos.x] != '\0')
		{
			point.x = curr_pos.x * 48;
			point.y = curr_pos.y * 48;
			draw_map(matrix_map, mlx, point, curr_pos);
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
