/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 02:06:11 by imurugar          #+#    #+#             */
/*   Updated: 2024/04/23 15:31:31 by imurugar         ###   ########.fr       */
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

void	*get_stack_address(void)
{
	void	*stack_start;

	stack_start = (void *)&stack_start;
	return (stack_start);
}

void	*get_stack_bottom(void)
{
	void	*stack_bottom;
	void	*tmp;
	void	*tmp_value;

	tmp = (void *)&tmp;
	if (tmp == NULL)
		return (NULL);
	tmp_value = *(char **)tmp;
	while (tmp_value == tmp)
	{
		tmp = (char *)tmp + sizeof(void *);
		tmp_value = *(char **)tmp;
	}
	stack_bottom = (char *)tmp - sizeof(void *);
	return (stack_bottom);
}
