/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:10:35 by imurugar          #+#    #+#             */
/*   Updated: 2024/04/21 15:10:38 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

void	*gc_malloc(size_t size)
{
	void	*ptr;
	t_Node	*node;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	node = create_node(ptr, size);
	if (node == NULL)
		return (NULL);
	node->next = get_gb()->head;
	get_gb()->head = node;
	return (ptr);
}

struct s_Node	*create_node(void *ptr, int size)
{
	t_Node	*node;

	node = malloc(sizeof(t_Node));
	if (node == NULL)
		return (NULL);
	node->ptr = ptr;
	node->size = size;
	node->next = NULL;
	return (node);
}

t_GarbageCollector	*get_gb(void)
{
	static t_GarbageCollector	gc = {0};

	return (&gc);
}

void	gc_init(void)
{
	get_gb()->head = NULL;
}

void	gc_free(void)
{
	t_Node	*temp;

	while (get_gb()->head != NULL)
	{
		temp = get_gb()->head;
		get_gb()->head = get_gb()->head->next;
		free(temp->ptr);
		free(temp);
		temp = NULL;
	}
}
