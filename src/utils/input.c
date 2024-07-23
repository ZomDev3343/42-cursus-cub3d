/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:23:41 by truello           #+#    #+#             */
/*   Updated: 2024/07/23 15:10:37 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	manage_left_camera_movement(t_player *player)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-ROT_SPEED) - player->dir_y
		* sin(-ROT_SPEED);
	player->dir_y = old_dir_x * sin(-ROT_SPEED) + player->dir_y
		* cos(-ROT_SPEED);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-ROT_SPEED) - player->plane_y
		* sin(-ROT_SPEED);
	player->plane_y = old_plane_x * sin(-ROT_SPEED) + player->plane_y
		* cos(-ROT_SPEED);
}

void	manage_right_camera_movement(t_player *player)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(ROT_SPEED) - player->dir_y
		* sin(ROT_SPEED);
	player->dir_y = old_dir_x * sin(ROT_SPEED) + player->dir_y * cos(ROT_SPEED);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(ROT_SPEED) - player->plane_y
		* sin(ROT_SPEED);
	player->plane_y = old_plane_x * sin(ROT_SPEED) + player->plane_y
		* cos(ROT_SPEED);
}

int	is_air(int map_case)
{
	return (map_case == 2 || map_case == MAP_OPENED_DOOR);
}

void	manage_strafe_movements(int map[500][500], t_player *player,
	int move)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)player->x;
	pos_y = (int)player->y;
	if (move == -1)
	{
		if (is_air(map[pos_y][(int)(player->x + player->plane_x * MOVE_SPEED)]))
			player->x += player->plane_x * MOVE_SPEED;
		if (is_air(map[(int)(player->y + player->plane_y * MOVE_SPEED)][pos_x]))
			player->y += player->plane_y * MOVE_SPEED;
	}
	if (move == 1)
	{
		if (is_air(map[pos_y][(int)(player->x - player->plane_x * MOVE_SPEED)]))
			player->x -= player->plane_x * MOVE_SPEED;
		if (is_air(map[(int)(player->y - player->plane_y * MOVE_SPEED)][pos_x]))
			player->y -= player->plane_y * MOVE_SPEED;
	}
}

void	manage_forward_movements(int map[500][500], t_player *player,
	int move)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)player->x;
	pos_y = (int)player->y;
	if (move == 1)
	{
		if (is_air(map[pos_y][(int)(player->x + player->dir_x * MOVE_SPEED)]))
			player->x += player->dir_x * MOVE_SPEED;
		if (is_air(map[(int)(player->y + player->dir_y * MOVE_SPEED)][pos_x]))
			player->y += player->dir_y * MOVE_SPEED;
	}
	if (move == -1)
	{
		if (is_air(map[pos_y][(int)(player->x - player->dir_x * MOVE_SPEED)]))
			player->x -= player->dir_x * MOVE_SPEED;
		if (is_air(map[(int)(player->y - player->dir_y * MOVE_SPEED)][pos_x]))
			player->y -= player->dir_y * MOVE_SPEED;
	}
}
