/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:23:41 by truello           #+#    #+#             */
/*   Updated: 2024/07/16 20:33:38 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	manage_right_camera_movement(t_player *player)
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

void	manage_left_camera_movement(t_player *player)
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

void	manage_movements(int map[500][500], t_player *player, int keycode)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)player->x;
	pos_y = (int)player->y;
	if (keycode == KEY_W)
	{
		printf("Pos X : %f, Pos Y : %f\n", player->x, player->y);
		if (map[pos_y][(int)(player->x + player->dir_x * MOVE_SPEED)] == 2)
			player->x += player->dir_x * MOVE_SPEED;
		if (map[(int)(player->y + player->dir_y * MOVE_SPEED)][pos_x] == 2)
			player->y += player->dir_y * MOVE_SPEED;
	}
	if (keycode == KEY_S)
	{
		printf("Pos X : %f, Pos Y : %f\n", player->x, player->y);
		if (map[pos_y][(int)(player->x - player->dir_x * MOVE_SPEED)] == 2)
			player->x -= player->dir_x * MOVE_SPEED;
		if (map[(int)(player->y - player->dir_y * MOVE_SPEED)][pos_x] == 2)
			player->y -= player->dir_y * MOVE_SPEED;
	}
}