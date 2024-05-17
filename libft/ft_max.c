/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:03:27 by tohma             #+#    #+#             */
/*   Updated: 2024/02/21 16:06:12 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

double	ft_dmax(double x, double y)
{
	if (x > y)
		return (x);
	else
		return (y);
}
