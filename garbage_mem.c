/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 02:26:49 by imurugar          #+#    #+#             */
/*   Updated: 2024/04/23 15:30:01 by imurugar         ###   ########.fr       */
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

// Why disable the valgrind report in this section?
// Because the variable ptr_on_stack stores a value collected from the stack 
// directly and is not a variable that we have initialized,
// valgrind will throw errors indicating that said variable is not initialized.
// These reports are false positives, since we only want to verify that it is
// the same address that we have stored in our list
void	mark_from_stack(void)
{
	void	*ptr_on_stack;
	void	*stack_start;
	void	*stack_end;

	VALGRIND_DISABLE_ERROR_REPORTING;
	stack_start = get_stack_address();
	stack_end = get_gb()->stack_bottom;
	if (DEBUG == true)
		printf("cheking from stack %p to %p\n", stack_start, stack_end);
	while (stack_start <= stack_end)
	{
		ptr_on_stack = *(void **)stack_start;
		if (ptr_on_stack != NULL)
			mark_address(*(void **)stack_start);
		stack_start += sizeof(void *);
	}
	VALGRIND_ENABLE_ERROR_REPORTING;
}

static void	sweep_process(t_Node **current, t_Node **prev)
{
	t_Node	*temp;

	temp = (*current);
	(*current) = (*current)->next;
	if (DEBUG == true)
		printf("free unreached memory: %p\n", temp->ptr);
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
