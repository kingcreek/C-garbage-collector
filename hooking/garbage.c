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

void	*my_malloc_hook(size_t size, void *caller)
{
	void	*ptr;
	Node	*node;

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

void	*malloc(size_t size)
{
	static int	malloc_hook_active = 1;
	
	void		*ptr;
	void		*caller;

	ptr = NULL;
	caller = __builtin_return_address(0);
	if (malloc_hook_active)
	{
		malloc_hook_active = 0;
		ptr = my_malloc_hook(size, caller);
		malloc_hook_active = 1;
		return (ptr);
	}
	return (__libc_malloc(size));
}

Node	*create_node(void *ptr, int size)
{
	Node	*node;

	node = __libc_malloc(sizeof(Node));
	if (node == NULL)
		return (NULL);
	node->ptr = ptr;
	node->size = size;
	node->next = NULL;
	return (node);
}

GarbageCollector	*get_gb(void)
{
	static GarbageCollector gc = {0};
	return (&gc);
}

void	gc_init(void)
{
	get_gb()->head = NULL;
}

void	gc_free(void)
{
	Node *temp;

	while (get_gb()->head != NULL)
	{
		temp = get_gb()->head;
		get_gb()->head = get_gb()->head->next;
		free(temp->ptr);
		free(temp);
		temp = NULL;
	}
}
