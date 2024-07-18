/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:28:10 by truello           #+#    #+#             */
/*   Updated: 2024/07/17 17:43:09 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_assets(t_assets *assets)
{
	assets->n_texture.img = NULL;
	assets->s_texture.img = NULL;
	assets->w_texture.img = NULL;
	assets->e_texture.img = NULL;
}

void	free_assets(t_global *global)
{
	if (global->assets.n_texture.img)
		mlx_destroy_image(global->mlx, global->assets.n_texture.img);
	if (global->assets.s_texture.img)
		mlx_destroy_image(global->mlx, global->assets.s_texture.img);
	if (global->assets.w_texture.img)
		mlx_destroy_image(global->mlx, global->assets.w_texture.img);
	if (global->assets.e_texture.img)
		mlx_destroy_image(global->mlx, global->assets.e_texture.img);
}
