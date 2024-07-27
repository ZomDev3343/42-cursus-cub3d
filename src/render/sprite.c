/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:25:48 by tohma             #+#    #+#             */
/*   Updated: 2024/07/27 12:28:11 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	swap_sprites(t_sprite_sort *a, t_sprite_sort *b)
{
	t_sprite_sort	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_sprite_sort	*create_sprites(int *order, float *dist, int amount)
{
	int				i;
	t_sprite_sort	*sprites;

	sprites = (t_sprite_sort *)malloc(amount * sizeof(t_sprite_sort));
	if (!sprites)
		return (NULL);
	i = 0;
	while (i < amount)
	{
		sprites[i].dist = dist[i];
		sprites[i].order = order[i];
		i++;
	}
	return (sprites);
}

void	sort_sprites_array(t_sprite_sort *sprites, int amount)
{
	int	i;
	int	j;

	i = 0;
	while (i < amount - 1)
	{
		j = 0;
		while (j < amount - i - 1)
		{
			if (sprites[j].dist < sprites[j + 1].dist)
				swap_sprites(&sprites[j], &sprites[j + 1]);
			j++;
		}
		i++;
	}
}

void	update_arrays(t_sprite_sort *sprites,
		int *order, float *dist, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[i].dist;
		order[i] = sprites[i].order;
		i++;
	}
}

void	sort_sprites(int *order, float *dist, int amount)
{
	t_sprite_sort	*sprites;

	sprites = create_sprites(order, dist, amount);
	if (!sprites)
		return ;
	sort_sprites_array(sprites, amount);
	update_arrays(sprites, order, dist, amount);
	free(sprites);
}
