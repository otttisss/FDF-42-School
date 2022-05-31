/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:25:59 by cmilagro          #+#    #+#             */
/*   Updated: 2021/11/11 21:22:36 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*s;

	i = 0;
	s = (char *)s1;
	n_len = ft_strlen(s2);
	if (n_len == 0 || s1 == s2)
		return (s);
	while (s[i] != '\0' && i < n)
	{
		j = 0;
		while (s[i + j] != '\0' && s2[j] != '\0'
			&& s[i + j] == s2[j] && i + j < n)
			j++;
		if (j == n_len)
			return (s + i);
		i++;
	}
	return (0);
}
