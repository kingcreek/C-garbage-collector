/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:53:24 by imurugar          #+#    #+#             */
/*   Updated: 2024/04/21 10:52:48 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"
///////TEST//////

int main() {
    GarbageCollector gc;
    gc_init(&gc);

    // Malloc used to alloc memory, 
    int *ptr1 = gc_malloc(&gc, sizeof(int));
    *ptr1 = 10;

    float *ptr2 = gc_malloc(&gc, sizeof(float));
    *ptr2 = 3.14;

    printf("Valor de ptr1: %d\n", *ptr1);
    printf("Valor de ptr2: %f\n", *ptr2);

    // Free mem
    gc_free(&gc);

    return 0;
}