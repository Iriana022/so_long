/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:24:13 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/06 12:51:09 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_left(t_data *data)
{
	if (data->map[data->pos_pers->y][data->pos_pers->x - 1] == '1')
		return ;
	if (data->map[data->pos_pers->y][data->pos_pers->x - 1] == 'C')
		(data->nb_collectible)--;
	(data->nb_moov)++;
	move(*data, 'l', *(data->pos_pers));
	(data->pos_pers->x)--;
	ft_putnbr_fd(data->nb_moov, 1);
	ft_putstr_fd(" mouvement\n", 1);
}

static void	move_right(t_data *data)
{
	if (data->map[data->pos_pers->y][data->pos_pers->x + 1] == '1')
		return ;
	if (data->map[data->pos_pers->y][data->pos_pers->x + 1] == 'C')
		(data->nb_collectible)--;
	(data->nb_moov)++;
	move(*data, 'r', *(data->pos_pers));
	(data->pos_pers->x)++;
	ft_putnbr_fd(data->nb_moov, 1);
	ft_putstr_fd(" mouvement\n", 1);
}

static void	move_up(t_data *data)
{
	if (data->map[data->pos_pers->y - 1][data->pos_pers->x] == '1')
		return ;
	if (data->map[data->pos_pers->y - 1][data->pos_pers->x] == 'C')
		(data->nb_collectible)--;
	(data->nb_moov)++;
	move(*data, 'u', *(data->pos_pers));
	(data->pos_pers->y)--;
	ft_putnbr_fd(data->nb_moov, 1);
	ft_putstr_fd(" mouvement\n", 1);
}

static void	move_down(t_data *data)
{
	if (data->map[data->pos_pers->y + 1][data->pos_pers->x] == '1')
		return ;
	if (data->map[data->pos_pers->y + 1][data->pos_pers->x] == 'C')
		(data->nb_collectible)--;
	move(*data, 'd', *(data->pos_pers));
	(data->nb_moov)++;
	(data->pos_pers->y)++;
	ft_putnbr_fd(data->nb_moov, 1);
	ft_putstr_fd(" mouvement\n", 1);
}

int	key_press(int keycode, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	if (keycode == XK_Escape)
		on_destroy(data);
	else if (keycode == XK_d)
		move_right(data);
	else if (keycode == XK_a)
		move_left(data);
	else if (keycode == XK_w)
		move_up(data);
	else if (keycode == XK_s)
		move_down(data);
	put_pos(data->map, *data);
	return (0);
}
