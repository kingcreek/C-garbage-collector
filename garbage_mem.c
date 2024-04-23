/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 02:26:49 by imurugar          #+#    #+#             */
/*   Updated: 2024/04/23 02:45:31 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

void	mark_address(void *ptr)
{
	t_Node	*current;

	current = get_gb()->head;
	while (current != NULL)
	{
		if (current->ptr == ptr)
		{
			current->marked = true;
			return ;
		}
		current = current->next;
	}
}

void	mark_from_stack(void)
{
	void	*ptr_on_stack;
	void	*stack_ptr;
	void	*stack_start;
	void	*stack_end;

	stack_start = get_stack_address();
	stack_end = get_gb()->stack_bottom;
	stack_ptr = &stack_start;
	while (stack_ptr <= stack_end)
	{
		ptr_on_stack = *(void **)stack_ptr;
		if (ptr_on_stack != NULL)
			mark_address(ptr_on_stack);
		stack_ptr += sizeof(void *);
	}
}

static void	sweep_process(t_Node **current, t_Node **prev)
{
	t_Node	*temp;
	
	temp = (*current);
	(*current) = (*current)->next;
	free(temp->ptr);
	temp->ptr = NULL;
	free(temp);
	temp = NULL;
	if ((*prev) != NULL)
		(*prev)->next = (*current);
	else
		get_gb()->head = (*current);
}

void	sweep_heap(void)
{
	t_Node	*current;
	t_Node	*prev;

	current = get_gb()->head;
	prev = NULL;
	while (current != NULL)
	{
		if (!current->marked)
			sweep_process(&current, &prev);
		else
		{
			current->marked = false;
			prev = current;
			current = current->next;
		}
	}
}

void	gc_garbage(void)
{
	mark_from_stack();
	sweep_heap();
}
