/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_and_ceiling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:00:51 by truello           #+#    #+#             */
/*   Updated: 2024/07/18 15:08:38 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_floor_and_ceiling(t_image *image, int x)
{
	int	y;
	int	c_color;
	int	f_color;

	c_color = rgb(image->global->assets.c_color[0],
			image->global->assets.c_color[1],
			image->global->assets.c_color[2]);
	f_color = rgb(image->global->assets.f_color[0],
			image->global->assets.f_color[1],
			image->global->assets.f_color[2]);
	y = -1;
	while (++y < image->global->win_height / 2)
		draw_pixel(image, x, y, c_color);
	while (++y < image->global->win_height - 1)
		draw_pixel(image, x, y, f_color);
}
