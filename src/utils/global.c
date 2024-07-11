/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:36:11 by truello           #+#    #+#             */
/*   Updated: 2024/07/11 15:40:28 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

void init_global(t_global *global)
{
	global->mlx = mlx_init();
	global->win_width = 800;
	global->win_height = 600;
	init_assets(&(global->assets));
}