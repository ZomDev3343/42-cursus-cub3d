/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:28:27 by tohma             #+#    #+#             */
/*   Updated: 2024/07/11 16:25:47 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int close_window(t_global *global)
{
	free_global(global);
	return (exit(0), 0);
}

static int manage_input(int keycode, t_global *global)
{
	if (keycode == 65307)
		close_window(global);
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
	global.mlx_win = mlx_new_window(global.mlx, global.win_width,
		global.win_height, "Cub3D by pow(Thomas, 2)");
	mlx_hook(global.mlx_win, 2, 1L << 0, manage_input, &global);
	mlx_hook(global.mlx_win, 17, 0, close_window, &global);
	mlx_loop_hook(global.mlx, render_cub3d, &global);
	mlx_loop(global.mlx);
	free_global(&global);
	return (0);
}
