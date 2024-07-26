/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:25:56 by tohma             #+#    #+#             */
/*   Updated: 2024/07/26 14:25:57 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	initialize_sprite_distance(t_global *global, int *sprite_order,
		float *sprite_distance)
{
	int	i;

	i = 0;
	while (i < global->n_sprites)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((global->player.y - global->sprites[i].x)
				* (global->player.y - global->sprites[i].x)
				+ (global->player.x - global->sprites[i].y)
				* (global->player.x - global->sprites[i].y));
		i++;
	}
}

void	sort_sprite_distance(t_global *global, int *sprite_order,
		float *sprite_distance)
{
	sort_sprites(sprite_order, sprite_distance, global->n_sprites);
}

void	calculate_transform_values(t_global *global,
		t_sprite_transform *transform, int sprite_order)
{
	transform->sprite_x = global->sprites[sprite_order].x - global->player.y;
	transform->sprite_y = global->sprites[sprite_order].y - global->player.x;
	transform->inv_det = 1.0 / (global->player.plane_y * global->player.dir_x
			- global->player.dir_y * global->player.plane_x);
	transform->transform_x = -transform->inv_det * (global->player.dir_x
			* transform->sprite_x - global->player.dir_y
			* transform->sprite_y);
	transform->transform_y = transform->inv_det * (-global->player.plane_x
			* transform->sprite_x + global->player.plane_y
			* transform->sprite_y);
	transform->sprite_screen_x = (int)((global->win_width / 2)
			* (1 + transform->transform_x
				/ transform->transform_y));
}

void	calculate_draw_dimensions(t_global *global,
		t_sprite_transform *transform)
{
	transform->v_move_screen = (int)(0.0 / transform->transform_y);
	transform->sprite_height = int_abs((int)(global->win_height
				/ (transform->transform_y))) / 1;
	transform->draw_start_y = -transform->sprite_height / 2
		+ global->win_height / 2 + transform->v_move_screen;
	if (transform->draw_start_y < 0)
		transform->draw_start_y = 0;
	transform->draw_end_y = transform->sprite_height / 2
		+ global->win_height / 2 + transform->v_move_screen;
	if (transform->draw_end_y >= global->win_height)
		transform->draw_end_y = global->win_height - 1;
	transform->sprite_width = int_abs((int)(global->win_height
				/ (transform->transform_y))) / 1;
	transform->draw_start_x = -transform->sprite_width / 2
		+ transform->sprite_screen_x;
	if (transform->draw_start_x < 0)
		transform->draw_start_x = 0;
	transform->draw_end_x = transform->sprite_width / 2
		+ transform->sprite_screen_x;
	if (transform->draw_end_x > global->win_width)
		transform->draw_end_x = global->win_width;
}
