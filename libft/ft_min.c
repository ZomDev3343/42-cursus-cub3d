/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:01:19 by tohma             #+#    #+#             */
/*   Updated: 2024/02/21 16:06:01 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

double	ft_dmin(double x, double y)
{
	if (x < y)
		return (x);
	else
		return (y);
}
