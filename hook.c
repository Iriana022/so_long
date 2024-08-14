/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:24:13 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/14 11:48:33 by irazafim         ###   ########.fr       */
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
	if (data->nb_collectible == 0)
		data->map[data->pos_exit->y][data->pos_exit->x] = 'E';
	if (data->nb_collectible == 0
		&& data->map[data->pos_pers->y][data->pos_pers->x] == 'E')
	{
		ft_putstr_fd("Game over!\n", 1);
		on_destroy(data);
	}
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
	if (data->nb_collectible == 0)
		data->map[data->pos_exit->y][data->pos_exit->x] = 'E';
	if (data->nb_collectible == 0
		&& data->map[data->pos_pers->y][data->pos_pers->x] == 'E')
	{
		ft_putstr_fd("Game over!\n", 1);
		on_destroy(data);
	}
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
	if (data->nb_collectible == 0)
		data->map[data->pos_exit->y][data->pos_exit->x] = 'E';
	if (data->nb_collectible == 0
		&& data->map[data->pos_pers->y][data->pos_pers->x] == 'E')
	{
		ft_putstr_fd("Game over!\n", 1);
		on_destroy(data);
	}
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
	if (data->nb_collectible == 0)
		data->map[data->pos_exit->y][data->pos_exit->x] = 'E';
	if (data->nb_collectible == 0
		&& data->map[data->pos_pers->y][data->pos_pers->x] == 'E')
	{
		ft_putstr_fd("Game over!\n", 1);
		on_destroy(data);
	}
}

int	key_press(int keycode, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	if (keycode == XK_Escape)
		on_destroy(data);
	else if (keycode == XK_d || keycode == XK_Right)
		move_right(data);
	else if (keycode == XK_a || keycode == XK_Left)
		move_left(data);
	else if (keycode == XK_w || keycode == XK_Up)
		move_up(data);
	else if (keycode == XK_s || keycode == XK_Down)
		move_down(data);
	put_pos(data->map, *data);
	return (0);
}
