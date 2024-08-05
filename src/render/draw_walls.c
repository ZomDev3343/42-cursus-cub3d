/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 23:58:45 by truello           #+#    #+#             */
/*   Updated: 2024/07/18 01:06:10 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_image	*choose_texture(t_global *global, int side)
{
	if (side == 0)
		return (&(global->assets.n_texture));
	else if (side == 1)
		return (&(global->assets.s_texture));
	else if (side == 2)
		return (&(global->assets.e_texture));
	else if (side == 3)
		return (&(global->assets.w_texture));
	else
		return (&(global->assets.door_texture));
}

void	draw_wall_stripe(t_draw_wall *drawinfos, t_image *screen, int x)
{
	int	y;
	int	tex_y;
	int	color;

	y = drawinfos->start_y - 1;
	while (++y < drawinfos->end_y)
	{
		tex_y = (int)(drawinfos->tex_pos) & (drawinfos->texture->width - 1);
		drawinfos->tex_pos += drawinfos->step;
		color = get_pixel_color(drawinfos->texture, drawinfos->tex_x, tex_y);
		draw_pixel(screen, x, y, color);
	}
}

void	edit_cord_for_door(t_ray *ray)
{
	if (ray->side < 2)
	{
		check_side(ray, 3);
		ray->WallXOffSet = 0.5 * ray->step_y;
		if (ray->side_dist_y - ray->delta_dist_y / 2 >= ray->side_dist_x)
		{
			ray->mapX += ray->step_x;
			ray->WallXOffSet = 0;
			check_side(ray, 0);
		}
	}
	else
	{
		check_side(ray, 3);
		ray->WallXOffSet = 0.5 * ray->step_x;
		if (ray->side_dist_x - ray->delta_dist_x / 2 >= ray->side_dist_y)
		{
			ray->mapY += ray->step_y;
			ray->WallXOffSet = 0;
			check_side(ray, 1);
		}
	}
}
