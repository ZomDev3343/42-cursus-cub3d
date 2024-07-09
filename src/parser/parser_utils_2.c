/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:05:25 by truello           #+#    #+#             */
/*   Updated: 2024/07/09 17:11:14 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_assets(t_global *global, int fd)
{
	if (global->assets.n_texture == NULL
		|| global->assets.s_texture == NULL
		|| global->assets.e_texture == NULL
		|| global->assets.w_texture == NULL)
		return(free_gnl(fd), error_mess("Incorrect texture images !"));
	return (0);
}