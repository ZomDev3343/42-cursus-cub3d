/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:07:25 by truello           #+#    #+#             */
/*   Updated: 2024/07/23 15:13:29 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	update_loop(t_global *global)
{
	if (global->player.move_x != 0)
		manage_strafe_movements(global->map, &(global->player),
			global->player.move_x);
	if (global->player.move_y != 0)
		manage_forward_movements(global->map, &(global->player),
			global->player.move_y);
	return (0);
}
