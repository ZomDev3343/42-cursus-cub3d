/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:18:18 by truello           #+#    #+#             */
/*   Updated: 2024/07/11 17:27:42 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	render_minimap(t_image *image)
{
	int	i;
	int	j;

	i = 0;
	while (image->global->map[i][0] != -2)
	{
		j = 0;
		while (image->global->map[i][j] != -2)
		{
			if (image->global->map[i][j] == 1)
				draw_square(image, make_square(i * 17, j * 17, 16, rgb(0, 0, 0)));
			j++;
		}
		i++;
	}
}

static void	render_raycast(t_image *image)
{
	(void)image;
}

int	render_cub3d(t_global *global)
{
	t_image	main_image;

	main_image.global = global;
	main_image.img = mlx_new_image(global->mlx, global->win_width, global->win_height);
	main_image.addr = mlx_get_data_addr(main_image.img,
			&(main_image.bits_per_pixel), &(main_image.line_length),
			&(main_image.endian));
	mlx_put_image_to_window(global->mlx, global->mlx_win, main_image.img, 0, 0);
	render_minimap(&main_image);
	render_raycast(&main_image);
	mlx_destroy_image(global->mlx, main_image.img);
	return (0);
}