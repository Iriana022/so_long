/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:24:13 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/01 09:00:22 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_left(t_data *data, int *found_exit)
{
	if (data->map[data->pos_pers->y][data->pos_pers->x - 1] == '1')
		return ;
	if (data->map[data->pos_pers->y][data->pos_pers->x - 1] == 'C')
		(data->nb_collectible)--;
	(data->nb_moov)++;
	move(data->map, 'l', *(data->pos_pers), found_exit);
	(data->pos_pers->x)--;
	ft_putnbr_fd(data->nb_moov, 1);
	ft_putstr_fd(" mouvement\n", 1);
}

static void	move_right(t_data *data, int *found_exit)
{
	if (data->map[data->pos_pers->y][data->pos_pers->x + 1] == '1')
		return ;
	if (data->map[data->pos_pers->y][data->pos_pers->x + 1] == 'C')
		(data->nb_collectible)--;
	if (data->map[data->pos_pers->y][data->pos_pers->x + 1] == 'E' && data->nb_collectible != 0)
		*found_exit = 1;
	(data->nb_moov)++;
	move(data->map, 'r', *(data->pos_pers), found_exit);
	(data->pos_pers->x)++;
	ft_putnbr_fd(data->nb_moov, 1);
	ft_putstr_fd(" mouvement\n", 1);
}

static void	move_up(t_data *data, int *found_exit)
{
	if (data->map[data->pos_pers->y - 1][data->pos_pers->x] == '1')
		return ;
	if (data->map[data->pos_pers->y - 1][data->pos_pers->x] == 'C')
		(data->nb_collectible)--;
	(data->nb_moov)++;
	move(data->map, 'u', *(data->pos_pers), found_exit);
	(data->pos_pers->y)--;
	ft_putnbr_fd(data->nb_moov, 1);
	ft_putstr_fd(" mouvement\n", 1);
}

static void	move_down(t_data *data, int *found_exit)
{
	if (data->map[data->pos_pers->y + 1][data->pos_pers->x] == '1')
		return ;
	if (data->map[data->pos_pers->y + 1][data->pos_pers->x] == 'C')
		(data->nb_collectible)--;
	move(data->map, 'd', *(data->pos_pers), found_exit);
	(data->nb_moov)++;
	(data->pos_pers->y)++;
	ft_putnbr_fd(data->nb_moov, 1);
	ft_putstr_fd(" mouvement\n", 1);
}

int	key_press(int keycode, void *param)
{
	t_data		*data;
	static int	found_exit;

	data = (t_data *)param;
	if (keycode == XK_Escape)
		on_destroy(data);
	else if (keycode == XK_d)
		move_right(data, &found_exit);
	else if (keycode == XK_a)
		move_left(data, &found_exit);
	else if (keycode == XK_w)
		move_up(data, &found_exit);
	else if (keycode == XK_s)
		move_down(data, &found_exit);
	put_pos(data->map, *data);
	return (0);
}
