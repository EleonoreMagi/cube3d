/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:46:58 by esylva            #+#    #+#             */
/*   Updated: 2022/11/05 15:15:14 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <math.h>
# include "../libft/libft.h"

# define BONUS 1
# define NO_BONUS_STR "0NSWE"
# define BONUS_STR "0NSWED"
# define ARGUMENT_OPEN_ERROR 1
# define INIT_ERROR 2
# define MAP_ERROR -10
# define NUMBER_OF_IMAGES 8

# define PI 3.14159265
# define ONE_SIZE 64
# define WOLL 0x0553300
# define UGOL 1.5707963
# define W_PANEL 1280
# define H_PANEL 720
# define W_MAP 210
# define M_GROUND 65355
# define SCALE 3
# define SPEED 0.2
# define BARRIER 3

typedef struct s_image
{
	void	*image;
	void	*addr;
	int		line;
	int		bitpp;
	int		endian;
	char	*loc;
	int		trgb;
	int		size_x;
	int		size_y;
}				t_image;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		ray_x;
	double		ray_y;
	double		look;
}				t_player;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		**coord;
}				t_window;

typedef struct s_map
{
	int		loot;
	int		exit;
	int		x;
	int		y;
	int		size_x;
	int		size_y;
	char	**coord;
}				t_map;

typedef struct s_wall
{
	int			f_dor;
	double		wall;
	double		tmp;
	int			kx;
	int			ky;
	double		dx;
	double		dy;
}				t_wall;

typedef struct s_data
{
	t_window		*window;
	t_map			*map;
	t_player		*player;
	t_image			*mmap;
	t_image			*ground;
	t_image			*cloud;
	t_image			*north;
	t_image			*east;
	t_image			*south;
	t_image			*west;
	t_image			*door;
	t_wall			*wal;
	char			bonus;
	int				*buf;
}				t_data;

/* main.c */
int			ft_cube(char *carta, t_data *data);
int			ft_exit(t_data *data, int keycode);
void		ft_free_all(t_data *data);
void		ft_game(t_data *data);

/* checker.c */
int			ft_name_check(char *carta);
int			ft_check_map(t_data *data, t_list *map, int weght, int hight);
int			ft_check_inside(t_data *data, int weght, int hight, char *str);
int			ft_check_sym(int i, int j, t_data *data);
void		ft_set_look(t_data *data, int i, int j);

/* init.c */
t_data		*ft_data_init(t_data *data);
int			ft_init_main_struct(t_data *data);
t_window	*ft_init_window(t_window *window);
t_image		*ft_init_image(t_image *wall);
int			ft_init_map(t_data *data, int hight, int weght);

/* parcer.c */
t_list		*ft_lstnew_m(char *content);
int			ft_parce_data(t_data *data, int fd);
int			ft_config(t_list **cub, t_data *data);
int			ft_parse_map(t_list *tmp, t_data *data);

/* parcer_utils.c */
int			ft_separate_textures(char *str, t_data *data);
int			ft_separate_textures_1(char *str, t_data *data);
t_image		*ft_save_texture(char *str, t_image *wall);
t_image		*ft_save_texture_c(char *str, t_image *wall, t_data *data);
int			ft_parsing_trgb(char *str, int *trgb);

/* parcer_utils2.c */
int			ft_empty_line(char *str);
void		ft_copy_str(char *dest, char *src, int lim);
int			ft_init_coord(t_data *data, t_list *map, int weght, int hight);
int			ft_check_rect_str(char *str);
int			ft_check_rect_col(char **str, int w, int h);

/* window1.c */
int			ft_win_init(t_data *data);
int			key_kb_hook(int keycode, t_data *data);
void		ft_paint(t_data *data);
void		ft_img_init(t_data *data);
void		ft_img_bonus_init(t_data *data);

/* paint_back.c */
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_back(t_data *data);
void		ft_back_bonus(t_data *data);
void		ft_draw_2d_obj(t_data *data, int x, int y, int color);
void		ft_put_minimap(t_data *data, int x, int y);

/* free.c */
t_window	*ft_free_window(t_window *window);
t_map		*ft_free_map(t_map *map);
t_player	*ft_free_player(t_player *player);
t_image		*ft_free_image(t_image *image);
t_wall		*ft_free_wall(t_wall *wall);

/* action.c */
int			mouse_move(int x, int y, t_data *data);
void		ft_turn_right(t_data *data);
void		ft_turn_left(t_data *data);
t_player	*ft_init_player(t_player *player);
t_wall		*ft_init_wall(t_wall *wall);

/* ft_wasd1.c */
void		ft_go_forward(t_data *data);
void		ft_str_left(t_data *data);
void		ft_go_backward(t_data *data);
void		ft_str_right(t_data *data);

/* cast_rays.c */
int			ft_cycle_paint_walls(t_data *data, int i);
int			ft_walls_paint(t_data *data, int i, double start);
void		ft_cast_rays(t_data *data);
void		ft_rais(t_data *data, double start);
void		ft_cast_rays2(t_data *data, int i, double start, double end);

/* ft_button.c */
void		ft_open_door(t_data *data);

#endif
