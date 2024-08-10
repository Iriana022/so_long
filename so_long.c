/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:13:06 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/08 13:50:47 by irazafim         ###   ########.fr       */
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

int	strchr_and_count(char *str, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			count++;
		i++;
	}
	return (count);
}

int count_lines(int fd)
{
	int	lines;
	int	read_bytes;
	int	i;
	char	buf[BUFFER_SIZE];
	
	read_bytes = 1;
	count = 0;
	while (read_bytes)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		buf[read_bytes] = '\0';
		lines += strchr_and_count(buffer, '\n');
	}
	return (lines);
}

int count_columns(int fd)
{
	int	read_bytes;
	int	i;
	char	buf[BUFFER_SIZE];
	int	col;

	read_bytes = 1;
	col = 0;
	while (read_bytes)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		buf[read_bytes] = '\0';
		i = 0;
		while (buf[i] && buf[i] != '\n')
			i++;
		col += i;
		if (buf[i] == '\n')
			break;
	}
	close(fd);
	return (col);
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
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				coord->x = j;
				coord->y = i;
				return (coord);
			}
			j++;
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

	lines = 0;
	read_bytes = 1;
	i = 0;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
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

int	main(int argc, char **argv)
{
	int		fd;
	t_data	mlx;
	char	**cp;

	if (argc == 2 && is_dotber(argv[1]))
	{
		fd = open(argv[1], O_RDONLY);
	}
	else
	{
		ft_putstr_fd("Invalid parameter\n", 1);
		exit(0);
	}
	if (fd == -1)
		exit(0);
	mlx.map = count_lines_map(fd);
	cp = arr_dup(mlx.map);
	mlx.pos_pers = catch_pos(mlx.map);
	//mlx.pos_exit = catch_posE(mlx.map);
	validation_check(&mlx, cp);
	mlx.pos_exit = catch_posE(mlx.map);
			
	mlx.mlx = mlx_init();
	img_init(&mlx);
	mlx.nb_collectible = sum_collectible(&mlx);
	mlx.nb_moov = 0;
	mlx.win = mlx_new_window(mlx.mlx, 48 * ft_strlen(mlx.map[0]), 48 * ft_len(mlx.map), "solong");
	put_pos(mlx.map, mlx);
	//mlx.pos_exit = catch_posE(mlx.map);
	/*just for debug*/
	//**cp = arr_dup(mlx.map);
	//flood_fill(cp, *mlx.pos_pers);
	//print_debug(cp);
	//printf("%d\n", road_validate(cp));
	//if(!road_validate(cp))
	//	ft_putstr_fd("map not valid", 1);
	//free_double(cp, ft_len(cp));
	/*******////*/
	mlx_hook(mlx.win, DestroyNotify, StructureNotifyMask, &close_window, &mlx);
	mlx_key_hook(mlx.win, key_press, &mlx);
	mlx_loop(mlx.mlx);
}
