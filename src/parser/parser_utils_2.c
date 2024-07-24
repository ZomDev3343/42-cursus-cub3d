/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:05:25 by truello           #+#    #+#             */
/*   Updated: 2024/07/17 17:32:33 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_assets(t_global *global, int fd)
{
	if (global->assets.n_texture.img == NULL
		|| global->assets.s_texture.img == NULL
		|| global->assets.e_texture.img == NULL
		|| global->assets.w_texture.img == NULL)
		return (free_gnl(fd), error_mess("Incorrect texture images !"));
	return (0);
}

int	count_sprite(char **map)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (map[y][0] != -2)
	{
		while(map[y][x] != -2)
		{
			if (map[y][x] == 5)
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

int	is_sprite(int i)
{
	return (i == 5);
}

int	get_sprite(t_global *global)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	global->sprites = malloc(sizeof(t_sprite) * count_sprite(global->map));
	while (map[y][0] != -2)
        {
                while(map[y][x] != -2)
                {
			if (is_sprite(map[y][x]))
			{
				global->sprites[i].x = x;
				global->sprites[i].y = y;
                        	if (map[y][x] == 5)
					global->sprites[i].texture = get_texture(global, "./textures/greenlight.xpm",
							&(global->assets.door_texture));
				i++;
			}
                        x++;
                }
                x = 0;
                y++;
        }
}
