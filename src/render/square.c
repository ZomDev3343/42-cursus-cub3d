/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:54:40 by truello           #+#    #+#             */
/*   Updated: 2024/07/11 17:02:04 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_square	make_square(int x1, int y1, int size, int color)
{
	t_square square;

	square.x1 = x1;
	square.y1 = y1;
	square.size = size;
	square.color = color;
	return (square);
}

