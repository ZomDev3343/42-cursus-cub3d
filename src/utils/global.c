/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:36:11 by truello           #+#    #+#             */
/*   Updated: 2024/08/15 12:09:05 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	calc_perp_wall_dist(t_ray *ray, t_global *global)
{
	ray->perp_wall_dist = (ray->map_x - global->player.x
			+ ray->wall_xoffset + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	if (ray->side < 2)
		ray->perp_wall_dist = (ray->map_y - global->player.y
				+ ray->wall_xoffset + (1 - ray->step_y) / 2) / ray->ray_dir_y;
}

void	switch_texture(t_global *global)
{
	int	i;

	i = -1;
	if (get_time() - global->time >= 1666)
	{
		while (++i < global->n_sprites)
		{
			mlx_destroy_image(global->mlx, global->sprites[i].texture.img);
			if (global->sprites[i].state == 0)
				get_texture(global, "./textures/greenlight1.xpm",
					&(global->sprites[i].texture));
			else if (global->sprites[i].state == 1)
				get_texture(global, "./textures/greenlight2.xpm",
					&(global->sprites[i].texture));
			else if (global->sprites[i].state == 2)
				get_texture(global, "./textures/greenlight3.xpm",
					&(global->sprites[i].texture));
			else
				get_texture(global, "./textures/greenlight.xpm",
					&(global->sprites[i].texture));
			if (++global->sprites[i].state > 3)
				global->sprites[i].state = 0;
		}
		global->time = get_time();
	}
}

void	free_global(t_global *global)
{
	int	i;

	i = -1;
	while (++i < global->n_sprites)
		mlx_destroy_image(global->mlx, global->sprites[i].texture.img);
	free_assets(global);
	if (global->mlx_win)
		mlx_destroy_window(global->mlx, global->mlx_win);
	if (global->mlx)
		mlx_destroy_display(global->mlx);
	if (global->mlx)
		free(global->mlx);
	if (global->sprites)
		free(global->sprites);
}

void	init_global(t_global *global)
{
	global->mlx = mlx_init();
	if (!global->mlx)
		printf("Error: MLX init error\n");
	global->mlx_win = NULL;
	global->win_width = 800;
	global->win_height = 600;
	global->mouse_x = global->win_width / 2;
	init_assets(&(global->assets));
	global->fps = get_time();
	global->time = get_time();
	global->player.x = -1;
	global->n_sprites = 0;
	global->sprites = NULL;
	global->deltatime = 0;
}

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}
