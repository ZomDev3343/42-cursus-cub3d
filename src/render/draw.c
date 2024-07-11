/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:20:56 by truello           #+#    #+#             */
/*   Updated: 2024/07/11 15:32:08 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
	Draws a pixel
*/
void	draw_pixel(t_img *img, t_draw_info info)
{
	int		pos;
	char	*dest;

	if (info.start_x > img->vars->win_width || info.start_x < 0
		|| info.start_y > img->vars->win_height || info.start_y < 0)
		return ;
	pos = (info.start_y * img->line_length
			+ info.start_x * (img->bits_per_pixel / 8));
	dest = img->addr + pos;
	*((unsigned int *)dest) = info.color;
}
