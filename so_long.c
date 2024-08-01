/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:13:06 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/01 10:04:09 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>
#include <stdio.h>

void	mtoa(char ***arr, int lines, int col, char *buf)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	*arr = (char **)malloc(sizeof(char *) * (lines + 1));
	while (i < lines)
	{
		(*arr)[i] = (char *)malloc(sizeof(char) * (col + 1));
		k = 0;
		while (k < col + 1)
		{
			(*arr)[i][k] = buf[j];
			k++;
			j++;
		}
		(*arr)[i][k - 1] = '\0';
		i++;
	}
	(*arr)[lines] = NULL;
}

t_coord	*catch_pos(char **map)
{
	int		i;
	int		j;
	t_coord	*coord;

	i = -1;
	coord = malloc(sizeof(t_coord));
	if (NULL == coord)
		return (NULL);
	coord->x = 0;
	coord->y = 0;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				coord->x = j;
				coord->y = i;
				return (coord);
			}
		}
	}
	return (coord);
}

char	**count_lines_map(int fd)
{
	int		read_bytes;
	char	buf[BUFFER_SIZE];
	char	**arr;
	int		i;
	int		lines;

	i = 0;
	lines = 0;
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		while (i < read_bytes)
		{
			if (buf[i] == '\n')
			{
				lines++;
			}
			i++;
		}
	}
	mtoa(&arr, lines, (i - 1) / lines, buf);
	return (arr);
}

int	main(void)
{
	int		fd;
	t_data	mlx;

	mlx.mlx = mlx_init();
	fd = open("invalidmap.ber", O_RDONLY);
	mlx.img[0] = img_return(PLAYER, &mlx);
	mlx.img[1] = img_return(WALL, &mlx);
	mlx.img[2] = img_return(COLLECTIBLE, &mlx);
	mlx.img[3] = img_return(EXIT, &mlx);
	mlx.img[4] = img_return(BACKGROUND, &mlx);
	mlx.map = count_lines_map(fd);
	printf("----------------------------\nmap validation : %d\n------------------------", valid_map(mlx.map));
	mlx.nb_collectible = sum_collectible(&mlx);
	mlx.nb_moov = 0;
	mlx.win = mlx_new_window(mlx.mlx,
			48 * ft_strlen(mlx.map[0]), 48 * ft_len(mlx.map), "solong");
	put_pos(mlx.map, mlx);
	mlx.pos_pers = catch_pos(mlx.map);
	mlx_hook(mlx.win, DestroyNotify, StructureNotifyMask, &close_window, &mlx);
	mlx_key_hook(mlx.win, key_press, &mlx);
	ft_putnbr(mlx.nb_moov);
	mlx_loop(mlx.mlx);
}
