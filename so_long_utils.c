/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:05:07 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/08 11:27:40 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_data *data)
{
	data->img[0] = img_return(PLAYER, data);
	data->img[1] = img_return(WALL, data);
	data->img[2] = img_return(COLLECTIBLE, data);
	data->img[3] = img_return(EXIT, data);
	data->img[4] = img_return(BACKGROUND, data);
}

void	validation_check(t_data *data, char **cp)
{
	if (!data->pos_pers)
	{
		ft_putstr_fd("Carte non valide, verifier svp :) !\n", 1);
		free_double(cp, ft_len(cp));
		free_double(data->map, ft_len(data->map));
		exit(1);
	}
	
	flood_fill(cp, *(data->pos_pers));
	if(!road_validate(cp) || !valid_map(data->map))
	{
		ft_putstr_fd("Carte non valide, verifier svp :) !\n", 1);
		free_double(cp, ft_len(cp));
		free_double(data->map, ft_len(data->map));
		free(data->pos_pers);
		//free(data->pos_exit);
		exit(1);
	}
	free_double(cp, ft_len(cp));
}

int		is_dotber(char *name)
{
	int	size;

	size = ft_strlen(name);
	if (name[size - 1] != 'r' || name[size - 2] != 'e'
		|| name[size - 3] != 'b' || name[size - 4] != '.')
	{
		return (0);
	}
	return (1);
}
