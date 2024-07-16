/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:28:27 by tohma             #+#    #+#             */
/*   Updated: 2024/07/16 23:38:52 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	close_window(t_global *global)
{
	free_global(global);
	return (exit(0), 0);
}

static int	manage_input(int keycode, t_global *global)
{
	if (keycode == 65307)
		close_window(global);
	if (keycode == KEY_A)
		manage_left_camera_movement(&(global->player));
	if (keycode == KEY_D)
		manage_right_camera_movement(&(global->player));
	manage_movements(global->map, &(global->player), keycode);
	printf("Key pressed : %d\n", keycode);
	return (0);
}

int	main(int ac, char **av)
{
	t_global	global;

	if (ac != 2)
		return (ft_error("Usage: ./cube3d <filename.cub>"));
	init_global(&global);
	if (parser(&global, av) || is_map_closed(&global))
		return (free_global(&global), 1);
	printf("Player Pos X: %f, Y: %f\n", global.player.x, global.player.y);
	global.mlx_win = mlx_new_window(global.mlx, global.win_width,
			global.win_height, "Cub3D by pow(Thomas, 2)");
	mlx_hook(global.mlx_win, 2, 1L << 0, manage_input, &global);
	mlx_hook(global.mlx_win, 17, 0, close_window, &global);
	mlx_loop_hook(global.mlx, render_cub3d, &global);
	mlx_loop(global.mlx);
	free_global(&global);
	return (0);
}
