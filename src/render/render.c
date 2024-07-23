/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:18:18 by truello           #+#    #+#             */
/*   Updated: 2024/07/23 15:17:28 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void    check_hit_door(t_ray *ray, t_global *global, t_player *player)
{
        int     map_x;
        int     map_y;

        map_x = (int) player->x;
        map_y = (int) player->y;
        while (ray->hit == 0)
        {
                if (ray->side_dist_x < ray->side_dist_y)
                {
                        ray->side_dist_x += ray->delta_dist_x;
                        map_x += ray->step_x;
                }
                else
                {
                        ray->side_dist_y += ray->delta_dist_y;
                        map_y += ray->step_y;
                }
                if (global->map[map_y][map_x] == MAP_CLOSED_DOOR ||
				global->map[map_y][map_x] == MAP_WALL)
		{
                        ray->hit = 1;
			if (global->map[map_y][map_x] == MAP_CLOSED_DOOR)
			{
				ray->side_dist_x += ray->delta_dist_x / 2;
				ray->side = 5;
			}
		}
        }
}

void    draw_door(t_ray *ray, t_image *image, int x, t_player *player)
{
        t_draw_wall     di;

        di.h = image->global->win_height;
	di.texture = &(image->global->assets.door_texture);
        di.line_height = (int)(di.h / ray->perp_wall_dist);
        di.start_y = -di.line_height / 2 + di.h / 2;
        di.end_y = di.line_height / 2 + di.h / 2;
        if (di.start_y < 0)
                di.start_y = 0;
        if (di.end_y >= di.h)
                di.end_y = di.h - 1;
        if (ray->side >= 2)
                di.wall_x = player->y + ray->perp_wall_dist * ray->ray_dir_y;
        else
                di.wall_x = player->x + ray->perp_wall_dist * ray->ray_dir_x;
        di.wall_x -= floorf(di.wall_x);
        di.tex_x = (int)(di.wall_x * di.texture->width);
        if (ray->side >= 2 && ray->ray_dir_x > 0)
                di.tex_x = di.texture->height - di.tex_x - 1;
        if (ray->side <= 1 && ray->ray_dir_y != 0)
                di.tex_x = di.texture->height - di.tex_x - 1;
        di.step = 1.0 * di.texture->height / di.line_height;
        di.tex_pos = (di.start_y - di.h / 2 + di.line_height / 2) * di.step;
        draw_wall_stripe(&di, image, x);
}


static void	render_raycast(t_image *image, t_global *global, t_player *player)
{
	int		w;
	int		i;
	t_ray	*ray;

	w = image->global->win_width;
	i = -1;
	while (++i < w)
	{
		ray = ft_calloc(1, sizeof(t_ray));
		calculate_ray_dist(ray, player, 2 * i / ((float) w) - 1);
		check_hit_walls(ray, global, player);
		if (ray->side >= 2)
			ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
		else
			ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
		draw_floor_and_ceiling(image, i);
		draw_stripe(ray, image, i, player);


		t_ray *ray2 = ft_calloc(1, sizeof(t_ray));
		calculate_ray_dist(ray2, player, 2 * i / ((float) w) - 1);
                check_hit_door(ray2, global, player);
		if (ray2->side == 5)
		{
			ray2->perp_wall_dist = (ray2->side_dist_x - ray2->delta_dist_x);
			draw_door(ray2, image, i, player);
		}
		free(ray2);
		free(ray);
	}
}

int	render_cub3d(t_global *global)
{
	t_image	main_image;

	update_loop(global);
	main_image.global = global;
	main_image.img = mlx_new_image(global->mlx, global->win_width,
			global->win_height);
	main_image.addr = mlx_get_data_addr(main_image.img,
			&(main_image.bits_per_pixel), &(main_image.line_length),
			&(main_image.endian));
	render_raycast(&main_image, global, &(global->player));
	add_minimap(&main_image, global, &(global->player));
	mlx_put_image_to_window(global->mlx, global->mlx_win, main_image.img, 0, 0);
	mlx_destroy_image(global->mlx, main_image.img);
	return (0);
}
