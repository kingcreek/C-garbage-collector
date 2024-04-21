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
#define GARBAGE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void *ptr;
    int size;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} GarbageCollector;


// Malloc real func
extern void *__libc_malloc(size_t size);

// Functions
void				*my_malloc_hook(size_t size, void *caller);
void				*malloc(size_t size);
Node				*create_node(void *ptr, int size);
GarbageCollector	*get_gb(void);
void				gc_init(void);
void				gc_free(void);

// Node	*createNode(void *ptr, int size);
// void	gc_init();
// //void	*gc_malloc(size_t size);
// void	*my_malloc(size_t size);
// void	*gc_calloc(size_t num, size_t size);
// void	*gc_realloc(void *ptr, size_t size);
// void	gc_free();

//#define malloc my_malloc

// Node	*createNode(void *ptr, int size);
// void	gc_init(GarbageCollector *gc);
// void	*gc_malloc(GarbageCollector *gc, size_t size);
// void	*gc_calloc(GarbageCollector *gc, size_t num, size_t size);
// void	*gc_realloc(GarbageCollector *gc, void *ptr, size_t size);
// void	gc_free(GarbageCollector *gc);


#endif