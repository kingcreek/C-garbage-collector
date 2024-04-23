/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 02:06:11 by imurugar          #+#    #+#             */
/*   Updated: 2024/04/23 02:31:00 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

struct s_Node	*create_node(void *ptr, int size)
{
	t_Node	*node;

	node = malloc(sizeof(t_Node));
	if (node == NULL)
		return (NULL);
	node->ptr = ptr;
	node->size = size;
	node->next = NULL;
	node->marked = false;
	return (node);
}

t_GarbageCollector	*get_gb(void)
{
	static t_GarbageCollector	gc = {0};

	return (&gc);
}

void	*get_stack_bottom(void)
{
	static void	*stack_bottom = NULL;

	return (stack_bottom);
}

void	*get_stack_address(void)
{
	void	*stack_start;

	stack_start = (void *)&stack_start;
	return (stack_start);
}
