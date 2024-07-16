/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:20:56 by truello           #+#    #+#             */
/*   Updated: 2024/07/16 20:35:18 by tohma            ###   ########.fr       */
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

void	draw_square(t_image *image, t_square square)
{
	int	i;
	int	j;

	i = square.x1 - 1;
	while (++i < square.x1 + square.size)
	{
		j = square.y1 - 1;
		while (++j < square.y1 + square.size)
			draw_pixel(image, i, j, square.color);
	}
}

void	draw_circle(t_image *image, t_circle circle)
{
	float	i;

	i = 0;
	while (i < PI * 2)
	{
		draw_pixel(image, (circle.x * 32) + cosf(i) * circle.radius,
			(circle.y * 32) + sinf(i) * circle.radius, circle.color);
		i += PI / 360.0;
	}
}
