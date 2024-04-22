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

void test()
{
    int *ptr1 = gc_malloc(sizeof(int));
    if (!ptr1)
        return;
    *ptr1 = 10;
}

int main(int argc, char* argv[]) {
    //gc_init(&argc);
    
    test();
    int *ptr1 = gc_malloc(sizeof(int));
    if (!ptr1)
        return EXIT_FAILURE;
    *ptr1 = 10;

    float *ptr2 = gc_malloc(sizeof(float));
    if (!ptr2)
        return EXIT_FAILURE;
    *ptr2 = 3.14;

    printf("Valor de ptr1: %d\n", *ptr1);
    printf("Valor de ptr2: %f\n", *ptr2);

    // Free mem
    //gc_free();
    run_gc();

    printf("Valor de ptr1: %d\n", *ptr1);
    printf("Valor de ptr2: %f\n", *ptr2);

    return EXIT_SUCCESS;
}