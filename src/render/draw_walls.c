/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 23:58:45 by truello           #+#    #+#             */
/*   Updated: 2024/07/18 00:38:44 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_image	*choose_texture(t_global *global, int side)
{
	if (side == 0)
		return (&(global->assets.n_texture));
	else if (side == 1)
		return (&(global->assets.s_texture));
	else if (side == 2)
		return (&(global->assets.e_texture));
	else
		return (&(global->assets.w_texture));
}

void	draw_wall_stripe(t_draw_wall *drawinfos, t_image *screen, int x)
{
	int	y;
	int	tex_y;
	int	color;

	y = drawinfos->start_y - 1;
	while (++y < drawinfos->end_y)
	{
		tex_y = (int) drawinfos->tex_pos & (drawinfos->texture->height);
		drawinfos->tex_pos += drawinfos->step;
		color = get_pixel_color(drawinfos->texture, drawinfos->tex_x, tex_y);
		draw_pixel(screen, x, y, color);
	}
}
