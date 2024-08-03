/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:30:32 by truello           #+#    #+#             */
/*   Updated: 2024/07/23 14:57:20 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	set_player_direction(t_player *player, char direction)
{
	if (direction == 'N')
		return (player->dir_x = 0.0f, player->dir_y = -1.0f,
			player->plane_x = -0.66f, player->plane_y = 0.0f, (void)0);
	else if (direction == 'S')
		return (player->dir_x = 0.0f, player->dir_y = 1.0f,
			player->plane_x = 0.66f, player->plane_y = 0.0f, (void)0);
	else if (direction == 'W')
		return (player->dir_x = -1.0f, player->dir_y = 0.0f,
			player->plane_x = 0.0f, player->plane_y = 0.66f, (void)0);
	else if (direction == 'E')
		return (player->dir_x = 1.0f, player->dir_y = 0.0f,
			player->plane_x = 0.0f, player->plane_y = -0.66f, (void)0);
}

/*
 * init_player init the entity player (struct)
 *
 * return status error or succes
 * */
void	init_player(t_global *global, char direction, int y, int x)
{
	global->map[y][x] = 0;
	global->player.x = (float) x + 0.5;
	global->player.y = (float) y + 0.5;
	global->player.move_x = 0;
	global->player.move_y = 0;
	set_player_direction(&(global->player), direction);
}

int	int_abs(int value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}
