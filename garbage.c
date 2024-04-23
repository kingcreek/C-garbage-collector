/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 01:56:56 by imurugar          #+#    #+#             */
/*   Updated: 2024/04/23 01:56:56 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

void __attribute__ ((constructor))	gc_init(void)
{
	void	*stack_bottom;

	get_gb()->head = NULL;
	stack_bottom = &stack_bottom;
	get_gb()->stack_bottom = stack_bottom;
}

void __attribute__ ((destructor))	gc_free(void)
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

void	*gc_malloc(size_t size)
{
	void	*ptr;
	t_Node	*node;

	gc_garbage();
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
