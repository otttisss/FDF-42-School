/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_get_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:07:34 by cmilagro          #+#    #+#             */
/*   Updated: 2022/05/08 17:18:15 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	push(t_pos **coords_stack, t_pos *new)
{
	if (coords_stack)
	{
		if (new)
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

t_pos	*get_elem(t_pos **coords_stack)
{
	t_pos	*elem;

	elem = NULL;
	if (coords_stack && *coords_stack)
	{
		elem = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return (elem);
}
