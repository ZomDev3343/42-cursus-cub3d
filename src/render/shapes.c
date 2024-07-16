/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:54:40 by truello           #+#    #+#             */
/*   Updated: 2024/07/16 20:37:26 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_square	make_square(int x1, int y1, int size, int color)
{
	t_square	square;

	square.x1 = x1;
	square.y1 = y1;
	square.size = size;
	square.color = color;
	return (square);
}

t_circle	make_circle(int x, int y, int radius, int color)
{
	t_circle	circle;

	circle.x = x;
	circle.y = y;
	circle.radius = radius;
	circle.color = color;
	return (circle);
}
