/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:29:03 by tohma             #+#    #+#             */
/*   Updated: 2024/07/14 11:32:50 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/ft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <math.h>

# define PI 3.14159265
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

// Definition of player structure
typedef struct player {
    float x;
    float y;
    float fov;
    float angle;
} t_player;

// Structure for the texture, color (assets) of map
typedef struct assets{
    void	*n_texture;
    int		n_w;
    int		n_h;
    void	*s_texture;
    int         s_w;
    int         s_h;
    void	*w_texture;
    int         w_w;
    int         w_h;
    void	*e_texture;
    int         e_w;
    int         e_h;
    int f_color[3];
    int c_color[3];
} t_assets;

// All information of the game
typedef struct global {
    int map[500][500];
    t_player player;
    t_assets assets;
    void	*mlx;
    void    *mlx_win;
    int     win_width;
    int     win_height;
} t_global;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
    int         endian;
	t_global	*global;
}	t_image;

typedef struct s_queue_node
{
	int					value;
	int					x;
	int					y;
	struct s_queue_node	*next;
}	t_queue_node;

typedef struct s_queue
{
	t_queue_node	*front;
	t_queue_node	*rear;
}	t_queue;

typedef struct s_square
{
    int x1;
    int y1;
    int size;
    int color;
}   t_square;

typedef struct s_circle
{
    int x;
    int y;
    int radius;
    int color;
}   t_circle;

int	    parser(t_global *global, char **av);
int	    error_mess(char *str);
void    free_tab(char **tab);
int	    copy_color(t_global *global, char **split_color, char *color);
void	init_player(t_global *global, char direction, int y, int x);
int	    copy_line_map(t_global *global, int i, char *line);
int     copy_assets(t_global *global, char **split_line);
int	    must_skip_line(char *line);
int     check_assets(t_global *global, int fd);
int     is_map_closed(t_global *global);

/* Colors */

int     is_color_correct(int r, int g, int b);
int     rgba(int r, int g, int b, int a);
int     rgb(int r, int g, int b);

/* Assets */

void    free_assets(t_global *global);
void	init_assets(t_assets *assets);

/* Queue */

t_queue_node	*create_qnode(int value, int x, int y);
void			enqueue(t_queue *queue, t_queue_node *qnode);
void			dequeue(t_queue *queue);
t_queue_node	*dequeue_q(t_queue *queue);
int				is_queue_empty(t_queue *queue);

/* Global */

void	print_global(t_global *global);
void	free_global(t_global *global);
void    init_global(t_global *global);

/* Draw */

void	draw_pixel(t_image *img, int x, int y, int color);
void	draw_square(t_image *image, t_square square);
void    draw_circle(t_image *image, t_circle circle);
t_square	make_square(int x1, int y1, int size, int color);
t_circle    make_circle(int x, int y, int radius, int color);

/* Render */

int	render_cub3d(t_global *global);


#endif
