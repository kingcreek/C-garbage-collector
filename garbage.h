/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:26:17 by imurugar          #+#    #+#             */
/*   Updated: 2024/04/21 10:46:42 by imurugar         ###   ########.fr       */
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

Node	*createNode(void *ptr, int size);
void	gc_init(GarbageCollector *gc);
void	*gc_malloc(GarbageCollector *gc, size_t size);
void	gc_free(GarbageCollector *gc);


#endif