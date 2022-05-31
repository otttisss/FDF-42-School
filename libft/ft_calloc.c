/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:24:12 by cmilagro          #+#    #+#             */
/*   Updated: 2021/10/22 20:04:18 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*res;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	res = malloc(num * size);
	if (res)
		ft_bzero(res, num * size);
	return (res);
}
