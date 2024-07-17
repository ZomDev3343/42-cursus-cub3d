/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:07:55 by truello           #+#    #+#             */
/*   Updated: 2024/07/18 01:04:36 by truello          ###   ########.fr       */
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
		ray->side_dist_x = (((int)player->x) + 1.0 - player->x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ((int)player->y)) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (((int)player->y) + 1.0 - player->y)
			* ray->delta_dist_y;
	}
}

void	calculate_ray_dist(t_ray *ray, t_player *player, float cameraX)
{
	ray->ray_dir_x = player->dir_x + player->plane_x * -cameraX;
	ray->ray_dir_y = player->dir_y + player->plane_y * -cameraX;
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

static void	check_side(t_ray *ray, int axis)
{
	if (axis == 0)
	{
		if (ray->ray_dir_x > 0.0f)
			ray->side = 2;
		else
			ray->side = 3;
		return ;
	}
	if (ray->ray_dir_y > 0.0f)
		ray->side = 0;
	else
		ray->side = 1;
}

/* Orientations
	0 : N
	1 : S
	2 : E
	3 : W
*/
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
			check_side(ray, 0);
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			map_y += ray->step_y;
			check_side(ray, 1);
		}
		if (global->map[map_y][map_x] == MAP_WALL
			|| global->map[map_y][map_x] == MAP_CLOSED_DOOR)
			ray->hit = 1;
	}
}

void	draw_stripe(t_ray *ray, t_image *image, int x, t_player *player)
{
	t_draw_wall	di;

	di.h = image->global->win_height;
	di.texture = choose_texture(image->global, ray->side);
	di.line_height = (int)(di.h / ray->perp_wall_dist);
	di.start_y = -di.line_height / 2 + di.h / 2;
	di.end_y = di.line_height / 2 + di.h / 2;
	if (di.start_y < 0)
		di.start_y = 0;
	if (di.end_y >= di.h)
		di.end_y = di.h - 1;
	if (ray->side <= 1)
		di.wall_x = player->y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		di.wall_x = player->x + ray->perp_wall_dist * ray->ray_dir_x;
	di.wall_x -= floorf(di.wall_x);
	di.tex_x = (int)(di.wall_x * di.texture->width);
	// if(ray->side >= 2 && ray->ray_dir_x > 0)
	// 	di.tex_x = di.texture->height - di.tex_x - 1;
    if(ray->side <= 1 && ray->ray_dir_y < 0)
		di.tex_x = di.texture->height - di.tex_x - 1;
	di.step = 1.0 * di.texture->height / di.line_height;
	di.tex_pos = (di.start_y - di.h / 2 + di.line_height / 2) * di.step;
	draw_wall_stripe(&di, image, x);
}
