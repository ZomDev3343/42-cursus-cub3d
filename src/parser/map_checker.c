/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:53:38 by truello           #+#    #+#             */
/*   Updated: 2024/07/10 16:21:05 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_case_valid(int value)
{
	return (value == 0 || value == 1 || value == 2);
}

static int	is_enclosed(int map[500][500], t_queue_node *qnode)
{
	int	enclosed_status;

	enclosed_status = 0;
	if (qnode->value != 0)
		return (0);
	if ((qnode->y == 0 && qnode->value == 0)
		|| (qnode->x == 0 && qnode->value == 0))
		enclosed_status = 1;
	if (!is_case_valid(map[qnode->y][qnode->x + 1]))
		enclosed_status = 1;
	if (qnode->x > 0 && !is_case_valid(map[qnode->y][qnode->x - 1]))
		enclosed_status = 1;
	if (map[qnode->y + 1][0] != -2 && !is_case_valid(map[qnode->y + 1][qnode->x]))
		enclosed_status = 1;
	if (qnode->y > 0 && !is_case_valid(map[qnode->y - 1][qnode->x]))
		enclosed_status = 1;
	return (enclosed_status);
}

void flood_fill(int map[500][500], int y, int x)
{
	t_queue			*queue;
	t_queue_node	*node;

	queue = ft_calloc(1, sizeof(t_queue));
	enqueue(queue, create_qnode(map[y][x], x, y));
	while (!is_queue_empty(queue))
	{
		node = dequeue_q(queue);
		printf("Node X: %d Y: %d\n", node->x, node->y);
		if (is_enclosed(map, node) == 0)
		{
			if (map[node->y][node->x] == 0)
				map[node->y][node->x] = 2;
			if (map[node->y][node->x + 1] != -2)
				enqueue(queue, create_qnode(map[node->y][node->x + 1], node->x + 1, node->y));
			if (map[node->y + 1][0] != -2 && map[node->y + 1][node->x] > -1)
				enqueue(queue, create_qnode(map[node->y + 1][node->x], node->x, node->y + 1));
		}
		free(node);
	}
	free(queue);
}
