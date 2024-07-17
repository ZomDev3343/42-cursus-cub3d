/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:18:18 by truello           #+#    #+#             */
/*   Updated: 2024/07/17 15:30:47 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
		draw_stripe(ray, image, i);
		free(ray);
	}
}

static void     add_minimap(t_image *image, t_global *global, t_player *player)
{
	int	i = 0;
	int	j = 0;
	
	while (global->map[i][0] != -2)
	{
		while(global->map[i][j] != -2)
		{
			t_square square;

			square.x1 = j*10;
			square.y1 = i*10;
			square.size = 10;
			if (global->map[i][j] == 1)
				square.color = rgb(255, 255, 255);
			else
				square.color = rgb(0, 0, 0);
			draw_square(image, square);
			if (i == (int)player->y && j == (int)player->x)
			{
				t_square s_player;

				s_player.x1 = j * 10 + 4;
				s_player.y1 = i * 10 + 4;
				s_player.size = 2;
				s_player.color = rgb(255, 0, 0);
				draw_square(image, s_player);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	render_cub3d(t_global *global)
{
	t_image	main_image;

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
