/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:11:30 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/02 14:03:08 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	flood_fill(char **map, t_coord size, t_coord begin)
{
	size.x = ft_strlen(map[0]);
	size.y = ft_len(map);
	fill(map, size, map.pos_pers, '0');
}
