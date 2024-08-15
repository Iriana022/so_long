/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@studend.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:13:06 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/15 09:00:11 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mtoa(char ***arr, int lines, int col, char *buf)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	*arr = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!(*arr))
		return ;
	while (i < lines)
	{
		(*arr)[i] = (char *)malloc(sizeof(char) * (col + 1));
		if (!((*arr)[i]))
			return ;
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
	if (!coord)
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

	lines = 0;
	read_bytes = 1;
	i = -1;
	init_array(buf);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		while (i < read_bytes)
			if (buf[++i] == '\n')
				lines++;
	}
	validate_lines(&lines, buf, &i);
	if (!lines || buf[0] == '\n' || (i) % lines != 0)
		ft_exit("Carte non valide\n", 1);
	mtoa(&arr, lines, (i - 1) / lines, buf);
	return (arr);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	mlx;
	char	**cp;

	check_arg(argc, argv[1], &fd);
	check_fd(fd);
	mlx.map = count_lines_map(fd);
	malloc_exit(mlx.map);
	cp = arr_dup(mlx.map);
	mlx.pos_pers = catch_pos(mlx.map);
	malloc_exit(mlx.pos_pers);
	validation_check(&mlx, cp);
	mlx.pos_exit = catch_pos_e(mlx.map);
	mlx.mlx = mlx_init();
	malloc_exit(mlx.mlx);
	img_init(&mlx);
	mlx.nb_collectible = sum_collectible(&mlx);
	mlx.nb_moov = 0;
	mlx.win = mlx_new_window(mlx.mlx, 48 * ft_strlen(mlx.map[0]),
			48 * ft_len(mlx.map), "solong");
	put_pos(mlx.map, mlx);
	mlx_hook(mlx.win, DestroyNotify, StructureNotifyMask, &close_window, &mlx);
	mlx_key_hook(mlx.win, key_press, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
