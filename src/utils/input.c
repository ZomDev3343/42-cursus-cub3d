/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:23:41 by truello           #+#    #+#             */
/*   Updated: 2024/07/26 14:53:48 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	manage_left_camera_movement(t_player *player, double dt)
{
	float	old_dir_x;
	float	old_plane_x;
	double	rot_speed;

	rot_speed = ROT_SPEED * dt;
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-rot_speed) - player->dir_y
		* sin(-rot_speed);
	player->dir_y = old_dir_x * sin(-rot_speed) + player->dir_y
		* cos(-rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-rot_speed) - player->plane_y
		* sin(-rot_speed);
	player->plane_y = old_plane_x * sin(-rot_speed) + player->plane_y
		* cos(-rot_speed);
}

void	manage_right_camera_movement(t_player *player, double dt)
{
	float	old_dir_x;
	float	old_plane_x;
	double	rot_speed;

	rot_speed = ROT_SPEED * dt;
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed) - player->dir_y
		* sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed) + player->dir_y
		* cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed) - player->plane_y
		* sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed) + player->plane_y
		* cos(rot_speed);
}

int	is_so(int map_case)
{
	return (map_case == 1 || map_case == MAP_CLOSED_DOOR);
}

void	manage_strafe_movements(int map[500][500], t_player *player,
	int move, double dt)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)player->x;
	pos_y = (int)player->y;
	if (move == -1)
	{
		if (!is_so(map[pos_y][(int)(player->x + player->plane_x
				* MOVE_SPEED * dt)]))
			player->x += player->plane_x * MOVE_SPEED * dt;
		if (!is_so(map[(int)(player->y + player->plane_y
					* MOVE_SPEED * dt)][pos_x]))
			player->y += player->plane_y * MOVE_SPEED * dt;
	}
	if (move == 1)
	{
		if (!is_so(map[pos_y][(int)(player->x - player->plane_x
				* MOVE_SPEED * dt)]))
			player->x -= player->plane_x * MOVE_SPEED * dt;
		if (!is_so(map[(int)(player->y - player->plane_y
					* MOVE_SPEED * dt)][pos_x]))
			player->y -= player->plane_y * MOVE_SPEED * dt;
	}
}

void	manage_forward_movements(int map[500][500], t_player *player,
	int move, double dt)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)player->x;
	pos_y = (int)player->y;
	if (move == 1)
	{
		if (!is_so(map[pos_y][(int)(player->x + player->dir_x
				* MOVE_SPEED * dt)]))
			player->x += player->dir_x * MOVE_SPEED * dt;
		if (!is_so(map[(int)(player->y + player->dir_y
					* MOVE_SPEED * dt)][pos_x]))
			player->y += player->dir_y * MOVE_SPEED * dt;
	}
	if (move == -1)
	{
		if (!is_so(map[pos_y][(int)(player->x - player->dir_x
				* MOVE_SPEED * dt)]))
			player->x -= player->dir_x * MOVE_SPEED * dt;
		if (!is_so(map[(int)(player->y - player->dir_y
					* MOVE_SPEED * dt)][pos_x]))
			player->y -= player->dir_y * MOVE_SPEED * dt;
	}
}
