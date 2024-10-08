/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:28:27 by tohma             #+#    #+#             */
/*   Updated: 2024/07/27 12:51:26 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	close_window(t_global *global)
{
	free_global(global);
	return (exit(0), 0);
}

static int	mouse_manage(int x, int y, t_global *global)
{
	(void) y;
	if (x == global->mouse_x)
		return (0);
	if (x < global->mouse_x)
		manage_left_camera_movement(&(global->player), global->deltatime);
	else if (x > global->mouse_x)
		manage_right_camera_movement(&(global->player), global->deltatime);
	global->mouse_x = x;
	return (0);
}

static int	manage_input_press(int keycode, t_global *global)
{
	if (keycode == 65307)
		close_window(global);
	if (keycode == KEY_LEFT)
		manage_left_camera_movement(&(global->player), global->deltatime);
	if (keycode == KEY_RIGHT)
		manage_right_camera_movement(&(global->player), global->deltatime);
	if (keycode == KEY_E)
		door_input(global->map, &(global->player));
	if (keycode == KEY_W)
		global->player.move_y = 1;
	if (keycode == KEY_S)
		global->player.move_y = -1;
	if (keycode == KEY_A)
		global->player.move_x = -1;
	if (keycode == KEY_D)
		global->player.move_x = 1;
	printf("Key pressed : %d\n", keycode);
	return (0);
}

static int	manage_input_release(int keycode, t_global *global)
{
	if (keycode == KEY_W)
		global->player.move_y = 0;
	if (keycode == KEY_S)
		global->player.move_y = 0;
	if (keycode == KEY_A)
		global->player.move_x = 0;
	if (keycode == KEY_D)
		global->player.move_x = 0;
	printf("Key released : %d\n", keycode);
	return (0);
}

int	main(int ac, char **av)
{
	t_global	global;

	if (ac != 2)
		return (ft_error("Usage: ./cube3d <filename.cub>"));
	if (ft_strcmp(av[1] + (ft_strlen(av[1]) - 4), ".cub") == 0)
		return (error_mess("Invalid file type"));
	init_global(&global);
	if (parser(&global, av) || is_map_closed(&global))
		return (free_global(&global), 1);
	global.mlx_win = mlx_new_window(global.mlx, global.win_width,
			global.win_height, "Cub3D by pow(Thomas, 2)");
	mlx_do_key_autorepeatoff(global.mlx);
	mlx_hook(global.mlx_win, 2, 1L << 0, manage_input_press, &global);
	mlx_hook(global.mlx_win, 3, 1L << 1, manage_input_release, &global);
	mlx_hook(global.mlx_win, 17, 0, close_window, &global);
	mlx_hook(global.mlx_win, 6, 1L << 6, mouse_manage, &global);
	mlx_loop_hook(global.mlx, render_cub3d, &global);
	mlx_loop(global.mlx);
	free_global(&global);
	return (0);
}
