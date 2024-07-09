/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:28:27 by tohma             #+#    #+#             */
/*   Updated: 2024/07/09 17:44:30 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 * Print_global a print global struct information function
 *
 * return void
 * */
void	print_global(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	printf("====Map====\n");
	while (global->map[i][0] != -2)
	{
		j = 0;
		while (global->map[i][j] != -2)
		{
			printf("%d", global->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("====Colors====\n");
	printf("%d:%d:%d\n", global->assets.f_color[0],
		global->assets.f_color[1], global->assets.f_color[2]);
	printf("%d:%d:%d\n", global->assets.c_color[0],
		global->assets.c_color[1], global->assets.c_color[2]);
	printf("====Player====\n");
	printf("x = %f, y = %f\n", global->player.x, global->player.y);
}

void	free_global(t_global *global)
{
	free_assets(global);
	free(global->mlx);
}

int	main(int ac, char **av)
{
	t_global	global;

	if (ac != 2)
		return (ft_error("Usage: ./cube3d <filename.cub>"));
	global.mlx = mlx_init();
	init_assets(&(global.assets));
	if (parser(&global, av))
		return (free_global(&global), 1);
	print_global(&global);
	free_global(&global);
	return (0);
}
