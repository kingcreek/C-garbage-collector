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

typedef struct s_Node {
	void			*ptr;
	int				size;
	struct s_Node	*next;
}	t_Node;

typedef struct s_GarbageCollector{
	t_Node	*head;
}	t_GarbageCollector;

// Functions
void				*gc_malloc(size_t size);
t_Node				*create_node(void *ptr, int size);
t_GarbageCollector	*get_gb(void);
void				gc_init(void);
void				gc_free(void);

#endif