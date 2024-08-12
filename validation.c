/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:33:59 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/12 10:27:32 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_notstrange_char(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C'
				|| map[i][j] == 'P' || map[i][j] == '1'
				|| map[i][j] == '0' || map[i][j] == '\n')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int is_rectangular(char **map)
{
	int	col;
	int	i;
	int	size;
	
	size = ft_len(map);
	col = ft_strlen(map[0]);
	i = 1;
	while (i < size)
	{
		if (ft_strlen(map[i]) != col)
			return (0);
		i++;
	}
	return (1);
}

int is_not_double(char **map)
{
	int	i;
	int j;
	int count_e;
	int	count_p;
	int	count_c;

	count_e = 0;
	count_p = 0;
	count_c = 0;
	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				count_e++;
			if (map[i][j] == 'P')
				count_p++;
			if (map[i][j] == 'C')
				count_c++;
			j++;
		}
		i++;
	}
	return (count_e == 1 && count_p == 1 && count_c >= 1);
}

int	is_wall_ext(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if ((i == 0 || i == ft_len(map) - 1) && (map[i][j] != '1'))
				return (0);
			else if (j == 0 && map[i][j] != '1')
				return (0);
			else if ((j == (ft_strlen(map[i]) - 1)) && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int valid_map(char **map)
{
	return (is_notstrange_char(map) && is_rectangular(map) && is_not_double(map) && is_wall_ext(map));
}
