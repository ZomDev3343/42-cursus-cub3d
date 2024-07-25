/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:18:18 by truello           #+#    #+#             */
/*   Updated: 2024/07/23 16:31:02 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_stripe_sprite(t_image *img,
		t_sprite_transform *transform, int sprite_index, int stripe)
{
	int	tex_x;
	int	y;
	int	d;
	int	tex_y;
	int	color;

	tex_x = (int)(256 * (stripe - (-transform->sprite_width / 2
					+ transform->sprite_screen_x)) * 64
			/ transform->sprite_width) / 256;
	if (transform->transform_y > 0 && transform->transform_y
		< img->global->zbuffer[stripe])
	{
		y = transform->draw_start_y;
		while (y < transform->draw_end_y)
		{
			d = (y - transform->v_move_screen) * 256 - img->global->win_height
				* 128 + transform->sprite_height * 128;
			tex_y = ((d * 64) / transform->sprite_height) / 256;
			color = get_pixel_color(&img->global->sprites[sprite_index].texture,
					tex_x, tex_y);
			if (color)
				draw_pixel(img, stripe, y, color);
			y++;
		}
	}
}

void	draw_sprite_stripes(t_global *global, t_image *image,
		t_sprite_transform *transform, int sprite_index)
{
	int	stripe;

	(void)global;
	stripe = transform->draw_start_x;
	while (stripe < transform->draw_end_x)
	{
		draw_stripe_sprite(image, transform, sprite_index, stripe);
		stripe++;
	}
}

void	draw_sprite(t_global *global, t_image *image)
{
	int					i;
	int					*sprite_order;
	float				*sprite_distance;
	t_sprite_transform	transform;

	sprite_order = malloc(sizeof(int) * global->n_sprites);
	sprite_distance = malloc(sizeof(float) * global->n_sprites);
	initialize_sprite_distance(global, sprite_order, sprite_distance);
	sort_sprite_distance(global, sprite_order, sprite_distance);
	i = 0;
	while (i < global->n_sprites)
	{
		calculate_transform_values(global, &transform, sprite_order[i]);
		calculate_draw_dimensions(global, &transform);
		draw_sprite_stripes(global, image, &transform, sprite_order[i]);
		i++;
	}
	free(sprite_order);
	free(sprite_distance);
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
		global->zbuffer[i] = ray->perp_wall_dist;
		free(ray);
	}
	draw_sprite(global, image);
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
