/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:55:15 by irazafim          #+#    #+#             */
/*   Updated: 2024/07/16 10:15:58 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_array_image(int size, t_data *mlx)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_destroy_image(mlx->mlx, mlx->img[i]);
		i++;
	}
}

int	on_destroy(t_data *data)
{
	free(data->pos_pers);
	free_array_image(5, data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_double(data->map, ft_len(data->map));
	exit(0);
	return (0);
}
