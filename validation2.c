/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:11:30 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/15 07:39:54 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **map, t_coord curr)
{
	if (curr.y <= 0 || curr.y >= ft_len(map) - 1
		|| curr.x <= 0 || curr.x >= ft_strlen(map[0]) - 1
		|| map[curr.y][curr.x] == '1' || map[curr.y][curr.x] == '#')
		return ;
	map[curr.y][curr.x] = '#';
	fill(map, (t_coord){curr.x - 1, curr.y});
	fill(map, (t_coord){curr.x + 1, curr.y});
	fill(map, (t_coord){curr.x, curr.y - 1});
	fill(map, (t_coord){curr.x, curr.y + 1});
}

void	flood_fill(char **map, t_coord begin)
{
	fill(map, begin);
}

char	**arr_dup(char **map)
{
	int		i;
	int		j;
	char	**ret;

	i = -1;
	ret = (char **)malloc(sizeof(char *) * (ft_len(map) + 1));
	if (!ret)
		return (NULL);
	while (++i < ft_len(map))
	{
		ret[i] = (char *)malloc(sizeof(char) * (ft_strlen(map[0]) + 1));
		if (!ret[i])
		{
			while (--i > 0)
				free(ret[i]);
			free(ret);
			return (NULL);
		}
		j = -1;
		while (++j < ft_strlen(map[0]))
			ret[i][j] = map[i][j];
		ret[i][j] = '\0';
	}
	ret[i] = NULL;
	return (ret);
}

int	road_validate(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < ft_len(map))
	{
		j = 0;
		while (j < ft_strlen(map[0]))
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
