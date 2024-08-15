/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:13:30 by irazafim          #+#    #+#             */
/*   Updated: 2024/08/15 09:03:58 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <unistd.h>
# include <X11/keysym.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef PLAYER
#  define PLAYER "./assets/Terrain/characters.xpm"
# endif
# ifndef WALL
#  define WALL "./assets/Terrain/wall.xpm"
# endif
# ifndef COLLECTIBLE
#  define COLLECTIBLE "./assets/Terrain/strawberry.xpm"
# endif
# ifndef EXIT
#  define EXIT "./assets/Terrain/exit.xpm"
# endif
# ifndef BACKGROUND
#  define BACKGROUND "./assets/Terrain/bg.xpm"
# endif

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
	t_coord	*pos_exit;
	int		nb_collectible;
	int		nb_moov;
}	t_data;

void	free_double(char **arr, int size);
void	free_array_image(int size, t_data *mlx);
int		on_destroy(t_data *data);
int		ft_len(char **s);
int		ft_strlen(char *s);
void	move(t_data mlx, char direction, t_coord pos);
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
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		valid_map(char **map);
char	**arr_dup(char **map);
void	flood_fill(char **map, t_coord begin);
int		road_validate(char **map);
t_coord	*catch_pos_e(char **map);
void	img_init(t_data *data);
void	validation_check(t_data *data, char **cp);
int		is_dotber(char *name);
void	ft_exit(char *msg, int code);
void	validate_lines(int *lines, char *buf, int *col);
void	init_array(char *buf);
void	draw_map(char **map, t_data mlx, t_coord point, t_coord curr_pos);
void	put_img(void *mlx, void *win, void *img, t_coord p);
void	malloc_exit(void *ptr);
void	check_fd(int fd);
void	check_arg(int arg, char *name, int *fd);
#endif
