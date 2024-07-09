/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:29:03 by tohma             #+#    #+#             */
/*   Updated: 2024/07/09 17:44:10 by truello          ###   ########.fr       */
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

// Definition of player structure
typedef struct player {
    float x;
    float y;
    float fov;
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
} t_global;

int	    parser(t_global *global, char **av);
int	    error_mess(char *str);
void    free_tab(char **tab);
int	    copy_color(t_global *global, char **split_color, char *color);
void	init_player(t_global *global, char direction, int y, int x);
int	    copy_line_map(t_global *global, int i, char *line);
int     copy_assets(t_global *global, char **split_line);
int	    must_skip_line(char *line);
int     check_assets(t_global *global, int fd);

/* Colors */

int     is_color_correct(int r, int g, int b);

/* Assets */

void    free_assets(t_global *global);
void	init_assets(t_assets *assets);

#endif
