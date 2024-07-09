/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:28:10 by truello           #+#    #+#             */
/*   Updated: 2024/07/09 17:43:03 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_assets(t_assets *assets)
{
	assets->n_texture = NULL;
	assets->s_texture = NULL;
	assets->w_texture = NULL;
	assets->e_texture = NULL;
}

void	free_assets(t_global *global)
{
	if (global->assets.n_texture)
		mlx_destroy_image(global->mlx, global->assets.n_texture);
	if (global->assets.s_texture)
		mlx_destroy_image(global->mlx, global->assets.s_texture);
	if (global->assets.w_texture)
		mlx_destroy_image(global->mlx, global->assets.w_texture);
	if (global->assets.e_texture)
		mlx_destroy_image(global->mlx, global->assets.e_texture);
}
