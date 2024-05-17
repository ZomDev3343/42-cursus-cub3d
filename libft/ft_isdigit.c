/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:05:13 by truello           #+#    #+#             */
/*   Updated: 2024/04/22 12:13:34 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (FALSE);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (TRUE);
		i++;
	}
	return (TRUE);
}

int	ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_isalphanum_c(char c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

int	ft_isalphanum(char *str)
{
	while (*str)
	{
		if (!ft_isalphanum_c(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
