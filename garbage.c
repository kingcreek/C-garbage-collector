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

void	*get_stack_address()
{
	void	*stack_start;

	stack_start = (void *)&stack_start;
	return stack_start;
}


void	mark_address(void *ptr)
{
	t_Node	*current;
	
	current = get_gb()->head;
	while (current != NULL) {
		if (current->ptr == ptr) {
			//printf("MARKED TRUE current: %p  ptr: %p\n", ptr, current->ptr);
			current->marked = true;
			return;
		}
		current = current->next;
	}
}

void mark_from_stack()
{
	// Itera sobre el rango de direcciones de memoria del stack
	void *stack_start = get_stack_address();
	// Supongamos que stack_end esta definido correctamente
	void *stack_end = get_gb()->stack_bottom;

	//printf("stack_start: %p  stack_end: %p	otro %p\n", stack_start, stack_end, get_gb()->stack_bottom);

	// Itera sobre el rango de direcciones del stack
	void *stack_ptr = &stack_start;
	while (stack_ptr <= stack_end) {
		//printf("stack_ptr: %p stack_end: %p\n", stack_ptr, stack_end);
		// Obtiene la direccion a la que apunta el puntero en el stack hacia el heap
		void *ptr_on_stack = *(void **)stack_ptr;

		// Marca la direccion de memoria si es alcanzable desde el stack
		if (ptr_on_stack != NULL) {
			mark_address(ptr_on_stack);
		}

		stack_ptr += sizeof(void *);
	}
}

// Barrer el heap y liberar areas no marcadas
void sweep_heap() {
	t_Node *current = get_gb()->head;
	t_Node *prev = NULL;

	while (current != NULL) {
		// Si el nodo no esta marcado, lo liberamos
		if (!current->marked) {
			t_Node *temp = current;
			current = current->next;
			free(temp->ptr);
			temp->ptr = NULL;
			free(temp);
			temp = NULL;
			if (prev != NULL) {
				prev->next = current;
			} else {
				get_gb()->head = current;
			}
		} else {
			// Si el nodo esta marcado, lo desmarcamos para la proxima ronda
			current->marked = false;
			prev = current;
			current = current->next;
		}
	}
}

void	run_gc()
{
	mark_from_stack();
	sweep_heap();
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
	node->marked = false;
	return (node);
}

t_GarbageCollector	*get_gb(void)
{
	static t_GarbageCollector	gc = {0};

	return (&gc);
}

void *get_stack_bottom() {
	static void *stack_bottom = NULL;
	return stack_bottom;
}

void __attribute__ ((constructor))	gc_init(void *ptr)
{
	void	*stack_b;

	get_gb()->head = NULL;

	void *stack_bottom = &stack_bottom;

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