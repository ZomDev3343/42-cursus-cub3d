/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:07:55 by truello           #+#    #+#             */
/*   Updated: 2024/07/15 13:17:04 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	calculate_side_dist(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - ((int)player->x)) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (((int)player->x) + 1.0 - player->x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ((int)player->y)) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (((int)player->y) + 1.0 - player->y) * ray->delta_dist_y;
	}
}

void	calculate_ray_dist(t_ray *ray, t_player *player, int cameraX)
{
	ray->ray_dir_x = player->dir_x + player->plane_x * cameraX;
	ray->ray_dir_y = player->dir_y + player->plane_y * cameraX;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 9999.0f;
	else
		ray->delta_dist_x = fabsf(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 9999.0f;
	else
		ray->delta_dist_y = fabsf(1 / ray->ray_dir_y);
	calculate_side_dist(ray, player);
}

void	check_hit_walls(t_ray *ray, t_global *global, t_player *player)
{
	int	map_x;
	int	map_y;

	map_x = (int) player->x;
	map_y = (int) player->y;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			map_y += ray->step_y;
			ray->side = 1;
		}
		if (global->map[map_x][map_y] == MAP_WALL
			|| global->map[map_x][map_y] == MAP_CLOSED_DOOR)
			ray->hit = 1;
	}
}
