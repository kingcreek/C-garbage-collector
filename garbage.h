/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:26:17 by imurugar          #+#    #+#             */
/*   Updated: 2024/04/21 13:42:56 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/resource.h>
# include <valgrind/valgrind.h>

# define DEBUG 1

typedef struct s_Node {
	void			*ptr;
	int				size;
	bool			marked;
	struct s_Node	*next;
}	t_Node;

typedef struct s_GarbageCollector{
	t_Node	*head;
	void	*stack_bottom;
}	t_GarbageCollector;

// Internal functions
t_Node				*create_node(void *ptr, int size);
t_GarbageCollector	*get_gb(void);
void				mark_address(void *ptr);
void				*get_stack_address(void);
void				*get_stack_bottom(void);
void				mark_from_stack(void);

// Functions
void				gc_garbage(void);
// void				gc_init(void);
void				gc_init(void);
void				*gc_malloc(size_t size);
void				gc_end(void);

#endif