/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:29:03 by tohma             #+#    #+#             */
/*   Updated: 2024/05/17 19:38:47 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/ft.h"

// Definition of player structure
typedef struct player {
    float x;
    float y;
    float fov; 
} t_player;

// Structure for the texture, color (assets) of map
typedef struct assets{
    void	*n_texture;
    void	*s_texture;
    void	*w_texture;
    void	*e_texture;
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

int	parser(t_global *global, char **av);
int	error_mess(char *str);
void    free_tab(char **tab);
int	copy_color(t_global *global, char **split_color, char *color);
void	init_player(t_global *global, char direction, int y, int x);
int	copy_line_map(t_global *global, int i, char *line);

#endif
