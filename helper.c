/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:34:34 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/14 12:20:39 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*img_return(char *path, t_data *mlx)
{
	int	width;
	int	height;

	return (mlx_xpm_file_to_image(mlx->mlx, path, &width, &height));
}

int	ft_len(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

int	close_window(t_data *data)
{
	on_destroy(data);
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

t_coord	*catch_pos_e(char **map)
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
			if (map[i][j] == 'E')
			{
				coord->x = j;
				coord->y = i;
				return (coord);
			}
		}
	}
	return (coord);
}
