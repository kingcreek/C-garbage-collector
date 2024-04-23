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

// Not sure if __attribute__ is allowed because it's not c standard
void __attribute__ ((constructor))	gc_init(void)
{
	get_gb()->head = NULL;
	get_gb()->stack_bottom = get_stack_bottom();
	if (DEBUG == true)
		printf("GC initialized, stack base: %p\n", get_gb()->stack_bottom);
}

// void	gc_init(void)
// {
// 	void	*stack_bottom;

// 	get_gb()->stack_bottom = stack_bottom + (sizeof(void *) * 100);
// 	get_gb()->head = NULL;
// 	if (DEBUG == true)
// 		printf("GC initialized, stack base: %p\n", get_gb()->stack_bottom);
// }
void __attribute__ ((destructor))	gc_exit(void)
// void	gc_end(void)
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
	if (DEBUG == true)
		printf("GC finished, all memory released <3\n");
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
