/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:30:32 by truello           #+#    #+#             */
/*   Updated: 2024/07/15 13:04:19 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
 * init_player init the entity player (struct)
 *
 * return status error or succes
 * */
void	init_player(t_global *global, char direction, int y, int x)
{
	(void) direction;
	global->map[y][x] = 0;
	global->player.x = (float) x;
	global->player.y = (float) y;
	global->player.dir_x = -1.0f;
	global->player.dir_y = 0.0f;
	global->player.plane_x = 0.0f;
	global->player.plane_y = 0.66f;

}
