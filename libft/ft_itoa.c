/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:29:26 by tohma             #+#    #+#             */
/*   Updated: 2024/05/17 14:48:41 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char	*init_str(int n, unsigned int *minus, size_t *n_len)
{
	char	*r;

	*n_len = 0;
	*minus = 0;
	if (n < 0)
		*minus = 1;
	while (n != 0)
	{
		(*n_len)++;
		n /= 10;
	}
	r = (char *) ft_calloc(*n_len + *minus + 1 + (*n_len == 0), 1);
	if (!r)
		return (0);
	if (*minus)
		r[0] = '-';
	return (r);
}

char	*ft_itoa(int n)
{
	long int		nbr;
	size_t			i;
	size_t			n_len;
	char			*r;
	unsigned int	minus;

	nbr = n;
	i = 0;
	r = init_str(n, &minus, &n_len);
	if (!r)
		return (0);
	if (minus == 1)
		nbr *= -1;
	if (n_len == 0)
		r[0] = '0';
	while (i < n_len)
	{
		r[minus + n_len - i - 1] = '0' + nbr % 10;
		nbr /= 10;
		i++;
	}
	return (r);
}
