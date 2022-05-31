/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:54:30 by cmilagro          #+#    #+#             */
/*   Updated: 2021/11/09 17:21:42 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	del_nbr(int n)
{
	int	x;

	x = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		++x;
	}
	return (x);
}

static char	*plus_int(int n, int len)
{
	char	*s;

	s = (char *)malloc(sizeof(*s) * (len + 1));
	if (s)
	{
		s[len] = '\0';
		len--;
		while (len >= 0)
		{
			s[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (s);
	}
	return (NULL);
}

static char	*minus_int(int n, int len)
{
	char	*s;

	s = (char *)malloc(sizeof(*s) * (len + 2));
	if (s)
	{
		len++;
		s[len] = '\0';
		len--;
		s[0] = '-';
		while (len > 0)
		{
			s[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (s);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = del_nbr(n);
	if (n >= 0)
		return (s = plus_int(n, len));
	return (s = minus_int((n * -1), len));
}
