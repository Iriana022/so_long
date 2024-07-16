/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:13:30 by irazafim          #+#    #+#             */
/*   Updated: 2024/07/16 15:40:36 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <unistd.h>
# include <X11/keysym.h>
# define BUFFER_SIZE 1024
# define PLAYER "./assets/Terrain/characters.xpm"
# define WALL "./assets/Terrain/wall.xpm"
# define COLLECTIBLE "./assets/Terrain/strawberry.xpm"
# define EXIT "./assets/Terrain/exit.xpm"
# define BACKGROUND "./assets/Terrain/bg.xpm"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;
typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img[5];
	t_coord	*pos_pers;
	int		nb_collectible;
	int		nb_moov;
}	t_data;
void	free_double(char **arr, int size);
void	free_array_image(int size, t_data *mlx);
int		on_destroy(t_data *data);
int		ft_len(char **s);
int		ft_strlen(char *s);
void	move(char **map, char direction, t_coord pos);
int		invalid_move(int x, int y, char **map);
void	put_pos(char **matrix_map, t_data mlx);
int		key_press(int keycode, void *param);
int		close_window(t_data *data);
void	*img_return(char *path, t_data *mlx);
int		ft_len(char **s);
int		sum_collectible(t_data *mlx);
int		ft_strlen(char *s);
int		invalid_move(int x, int y, char **map);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);
#endif
