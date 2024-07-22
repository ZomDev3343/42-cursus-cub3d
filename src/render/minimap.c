/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:55:42 by truello           #+#    #+#             */
/*   Updated: 2024/07/22 15:59:12 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	choose_square_color(int map_case)
{
	if (map_case == MAP_WALL)
		return (rgb(255, 255, 255));
	else if (map_case == MAP_OPENED_DOOR)
		return (rgb(0, 200, 50));
	else if (map_case == MAP_CLOSED_DOOR)
		return (rgb(200, 50, 0));
	return (rgb(0, 0, 0));
}

void	add_minimap(t_image *image, t_global *global, t_player *player)
{
	int			i;
	int			j;
	t_square	square;

	i = 0;
	while (global->map[i][0] != -2)
	{
		j = 0;
		while (global->map[i][j] != -2)
		{
			square.x1 = j * 10;
			square.y1 = i * 10;
			square.size = 10;
			square.color = choose_square_color(global->map[i][j]);
			draw_square(image, square);
			if (i == (int)player->y && j == (int)player->x)
				draw_square(image, make_square(j * 10 + 4, i * 10 + 4,
						2, rgb(255, 0, 0)));
			j++;
		}
		i++;
	}
}
