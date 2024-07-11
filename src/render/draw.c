/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:20:56 by truello           #+#    #+#             */
/*   Updated: 2024/07/11 16:03:16 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
	Draws a pixel
*/
void	draw_pixel(t_image *img, int x, int y, int color)
{
	int		pos;
	char	*dest;

	if (x > img->global->win_width || x < 0
		|| y > img->global->win_height || y < 0)
		return ;
	pos = (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	dest = img->addr + pos;
	*((unsigned int *)dest) = color;
}
