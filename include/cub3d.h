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

// Definition of player structure
typedef struct player {
    float x;
    float y;
    float fov; 
} t_player;

// Structure for the texture, color (assets) of map
typedef struct assets{
    int **n_texture;
    int **s_texture;
    int **w_texture;
    int **e_texture;
    int f_color[3];
    int c_color[3];
} t_assets;

// All information of the game
typedef struct global {
    int map[500][500];
    t_player player;
    t_assets assets;
} t_global;

#endif
