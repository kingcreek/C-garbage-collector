/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:26:22 by imurugar          #+#    #+#             */
/*   Updated: 2024/04/21 10:46:54 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

Node *createNode(void *ptr, int size) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
		return NULL;
    node->ptr = ptr;
    node->size = size;
    node->next = NULL;
    return node;
}

void gc_init(GarbageCollector *gc) {
    gc->head = NULL;
}

void *gc_malloc(GarbageCollector *gc, size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL)
		return (NULL);
    Node *node = createNode(ptr, size);
	if (node == NULL)
		return (NULL);
    node->next = gc->head;
    gc->head = node;
    return ptr;
}

void gc_free(GarbageCollector *gc) {
    while (gc->head != NULL) {
        Node *temp = gc->head;
        gc->head = gc->head->next;
        free(temp->ptr);
        free(temp);
    }
}
