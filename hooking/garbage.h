/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:26:17 by imurugar          #+#    #+#             */
/*   Updated: 2024/04/21 15:10:58 by imurugar         ###   ########.fr       */
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

#endif