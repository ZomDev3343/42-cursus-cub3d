/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:23:41 by truello           #+#    #+#             */
/*   Updated: 2024/07/15 15:27:23 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void manage_camera_input(t_player *player, int keycode)
{
	float	old_dir_x;
	float	old_plane_x;

  if (keycode == KEY_D)
  {
    old_dir_x = player->dir_x;
    player->dir_x = player->dir_x * cos(-ROT_SPEED) - player->dir_y * sin(-ROT_SPEED);
    player->dir_y = old_dir_x * sin(-ROT_SPEED) + player->dir_y * cos(-ROT_SPEED);
    old_plane_x = player->plane_x;
    player->plane_x = player->plane_x * cos(-ROT_SPEED) - player->plane_y * sin(-ROT_SPEED);
    player->plane_y = old_plane_x * sin(-ROT_SPEED) + player->plane_y * cos(-ROT_SPEED);
  }
  if (keycode == KEY_A)
  {
    old_dir_x = player->dir_x;
    player->dir_x = player->dir_x * cos(ROT_SPEED) - player->dir_y * sin(ROT_SPEED);
    player->dir_y = old_dir_x * sin(ROT_SPEED) + player->dir_y * cos(ROT_SPEED);
    old_plane_x = player->plane_x;
    player->plane_x = player->plane_x * cos(ROT_SPEED) - player->plane_y * sin(ROT_SPEED);
    player->plane_y = old_plane_x * sin(ROT_SPEED) + player->plane_y * cos(ROT_SPEED);
  }
}

void  manage_movements(int map[500][500], t_player *player, int keycode)
{
  if (keycode == KEY_W)
  {
    if (map[(int)(player->y)][(int)(player->x + player->dir_x * MOVE_SPEED)] == 0)
      player->x += player->dir_x * MOVE_SPEED;
    if (map[(int)(player->y + player->dir_y * MOVE_SPEED)][(int)(player->x)] == 0)
      player->y += player->dir_y * MOVE_SPEED;
  }
  if (keycode == KEY_S)
  {
    if (map[(int)(player->y)][(int)(player->x - player->dir_x * MOVE_SPEED)] == 0)
      player->x -= player->dir_x * MOVE_SPEED;
    if (map[(int)(player->y - player->dir_y * MOVE_SPEED)][(int)(player->x)] == 0)
      player->y -= player->dir_y * MOVE_SPEED;
  }
}
