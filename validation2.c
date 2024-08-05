/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:11:30 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/05 12:40:13 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **array_dup(char **map, int size_h, int size_l)
{
	int		i;
	int		j;
	char	**array_ret;

	i = 0;
	j = 0;
	**array_ret = (char **)malloc(sizeof(char *) * size_h);
	if (!array_ret)
		return (NULL);
	while (i < size_h)
	{
		array_ret[i] = (char *)malloc(sizeof(char) * size_l);
		if (!array_ret[i])
		{
			while (j < i)
			{
				free(array_ret[j]);
				j++;
			}
			free(array_ret);
		}
		j = 0;
		while (j < size_l)
		{
			array_ret[i][j] = '0';
			j++;
		}
		i++;
	}
	return (array_ret);
}

void	fill(char **tab, t_coord size, t_coord cur, char tofill)
{
	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y || tab[cur.y][cur.x] != tofill)
		return;
	tab[cur.y][cur.x] = 'P';
	fill(tab, size, (t_coord){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_coord){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_coord){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_coord){cur.x, cur.y + 1}, to_fill);
}

void debug_map(char **map)
{
	int i = 0;
	int j = 0;
	while(i < ft_len(map))
	{
		j = 0;
		while (j < ft_strlen(map))
		{
			printf("%c", map[i][j]);
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, t_coord size, t_coord begin)
{
	char	**cpy_map;

	cpy_map = array_dup(map, ft_len(map), ft_strlen(map[0]));
	size.x = ft_strlen(map[0]);
	size.y = ft_len(map);
	fill(map, size, map.pos_pers, 'X');
	debug_map(cpy_map);
}


