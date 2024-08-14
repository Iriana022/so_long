/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:12:45 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/14 12:16:21 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *msg, int code)
{
	ft_putstr_fd(msg, 1);
	exit(code);
}

void	validate_lines(int *lines, char *buf, int *col)
{
	if (!*lines)
		ft_exit("Carte non valide\n", 1);
	if (buf[*col - 1] == '\n' && buf[*col - 2] == '\n')
	{
		*lines -= 1;
		*col -= 1;
	}
}

void	init_array(char *buf)
{
	int	i;

	i = -1;
	while (++i < BUFFER_SIZE)
		buf[i] = 0;
}

void	draw_map(char **map, t_data mlx, t_coord point, t_coord curr_pos)
{
	if (map[curr_pos.y][curr_pos.x] == 'P')
		put_img(mlx.mlx, mlx.win, mlx.img[0], point);
	else if (map[curr_pos.y][curr_pos.x] == '1')
		put_img(mlx.mlx, mlx.win, mlx.img[1], point);
	else if (map[curr_pos.y][curr_pos.x] == 'C')
		put_img(mlx.mlx, mlx.win, mlx.img[2], point);
	else if (map[curr_pos.y][curr_pos.x] == 'E')
	{
		if (mlx.nb_collectible == 0)
			put_img(mlx.mlx, mlx.win, mlx.img[3], point);
		else
			put_img(mlx.mlx, mlx.win, mlx.img[4], point);
	}
	else if (map[curr_pos.y][curr_pos.x] == '0')
		put_img(mlx.mlx, mlx.win, mlx.img[4], point);
}
