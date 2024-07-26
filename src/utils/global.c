/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:36:11 by truello           #+#    #+#             */
/*   Updated: 2024/07/26 14:42:23 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	switch_texture(t_global *global)
{
	int	i;

	i = -1;
	if (get_time() - global->time >= 1666)
	{
		while (++i < global->n_sprites)
		{
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
			global->sprites[i].state++;
			if (global->sprites[i].state > 3)
				global->sprites[i].state = 0;
		}
		global->time = get_time();
	}
}

void	free_global(t_global *global)
{
	free_assets(global);
	if (global->mlx_win)
		mlx_destroy_window(global->mlx, global->mlx_win);
	mlx_destroy_display(global->mlx);
	free(global->mlx);
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
	global->deltatime = 0;
}

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}
