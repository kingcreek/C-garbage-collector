/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:53:24 by imurugar          #+#    #+#             */
/*   Updated: 2024/04/21 15:15:28 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

int main() {
    // Initialice garbage collector
    gc_init();

    // normal malloc
    int *ptr1 = malloc(sizeof(int));
	if (ptr1)
	{
    	*ptr1 = 10;
		printf("Valor de ptr1: %d\n", *ptr1);
	}
    int *ptr2 = malloc(sizeof(int));
	if(ptr2)
	{
		*ptr2 = 3;
		printf("Valor de ptr2: %d\n", *ptr2);
	}
    // Free memory
    gc_free();

    return 0;
}