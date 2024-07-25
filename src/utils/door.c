/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:31:34 by truello           #+#    #+#             */
/*   Updated: 2024/07/22 15:48:04 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_door(int map_case)
{
	return (!(map_case == MAP_CLOSED_DOOR || map_case == MAP_OPENED_DOOR));
}

static void	toggle_door(int *map_case)
{
	printf("pointer : %p\n", map_case);
	*map_case = !(*map_case - MAP_OPENED_DOOR) + MAP_OPENED_DOOR;
	printf("Door at %d toggled !\n", *map_case);
}

void	door_input(int map[500][500], t_player *player)
{
	float	px;
	float	py;

	px = player->x;
	py = player->y;
	if (is_door(map[(int)py][(int)(px + DOOR_DIST)]) == 0)
		toggle_door(&(map[(int)py][(int)(px + DOOR_DIST)]));
	else if (is_door(map[(int)py][(int)(px - DOOR_DIST)]) == 0)
		toggle_door(&(map[(int)py][(int)(px - DOOR_DIST)]));
	else if (is_door(map[(int)(py + DOOR_DIST)][(int)px]) == 0)
		toggle_door(&(map[(int)(py + DOOR_DIST)][(int)px]));
	else if (is_door(map[(int)(py - DOOR_DIST)][(int)px]) == 0)
		toggle_door(&(map[(int)(py - DOOR_DIST)][(int)px]));
	if (map[(int)player->y][(int)player->x] == MAP_CLOSED_DOOR)
	{
		if (!is_so(map[(int)player->y][(int)player->x + 1]))
			player->x += 1.0f;
		else if (!is_so(map[(int)player->y][(int)player->x - 1]))
			player->x -= 1.0f;
		else if (!is_so(map[(int)player->y + 1][(int)player->x]))
			player->y += 1.0f;
		else if (!is_so(map[(int)player->y - 1][(int)player->x + 1]))
			player->y -= 1.0f;
	}
}
