/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:19:44 by truello           #+#    #+#             */
/*   Updated: 2024/07/16 20:35:06 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_queue_node	*create_qnode(int value, int x, int y)
{
	t_queue_node	*qnode;

	qnode = ft_calloc(1, sizeof(t_queue_node));
	qnode->value = value;
	qnode->x = x;
	qnode->y = y;
	return (qnode);
}

void	enqueue(t_queue *queue, t_queue_node *qnode)
{
	if (queue->rear == NULL)
		return (queue->front = qnode, queue->rear = qnode, (void) 0);
	queue->rear->next = qnode;
	queue->rear = qnode;
}

void	dequeue(t_queue *queue)
{
	t_queue_node	*tmp;

	if (queue->front == NULL)
		return ;
	tmp = queue->front;
	queue->front = queue->front->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	free(tmp);
}

t_queue_node	*dequeue_q(t_queue *queue)
{
	t_queue_node	*tmp;

	if (queue->front == NULL)
		return (NULL);
	tmp = queue->front;
	queue->front = queue->front->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	return (tmp);
}

int	is_queue_empty(t_queue *queue)
{
	return (queue && queue->front == NULL);
}
