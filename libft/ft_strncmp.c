/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:25:42 by cmilagro          #+#    #+#             */
/*   Updated: 2021/10/21 18:02:19 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t count)
{
	size_t	i;

	i = 0;
	if (count == 0)
		return (0);
	while (str1[i] != '\0' && str1[i] == str2[i] && i < count - 1)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
