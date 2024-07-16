/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:44:33 by truello           #+#    #+#             */
/*   Updated: 2024/07/16 20:25:03 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_color_correct(int r, int g, int b)
{
	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
		return (0);
	return (1);
}

int	rgba(int r, int g, int b, int a)
{
	if (is_color_correct(r, g, b) || a < 0 || a > 255)
		return (-1);
	return (a << 24 | r << 16 | g << 8 | b);
}

int	rgb(int r, int g, int b)
{
	return (rgba(r, g, b, 255));
}
