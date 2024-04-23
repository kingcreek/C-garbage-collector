/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 02:21:46 by imurugar          #+#    #+#             */
/*   Updated: 2024/04/23 02:21:46 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

void	test(void)
{
	int	*ptr1;

	ptr1 = gc_malloc(sizeof(int));
	if (!ptr1)
		return ;
	printf("memory allocated in test: %p\n", ptr1);
	*ptr1 = 10;
}

int	*test2(void)
{
	int	*ptr1;

	ptr1 = gc_malloc(sizeof(int));
	if (!ptr1)
		return NULL;
	printf("memory allocated in test2: %p\n", ptr1);
	*ptr1 = 4242;
	return (ptr1);
}

int	main(int argc, char *argv[])
{
	int		*ptr1;
	float	*ptr2;
	int		*test_val;
	
	printf("Call forced leak\n");
	test();
	printf("Call malloc 1\n");
	ptr1 = gc_malloc(sizeof(int));
	if (!ptr1)
		return (EXIT_FAILURE);
	*ptr1 = 10;
	printf("Call malloc 2\n");
	ptr2 = gc_malloc(sizeof(float));
	if (!ptr2)
		return (EXIT_FAILURE);
	*ptr2 = 3.14;
	test_val = test2();
	printf("ptr1 %p value: %d\n", ptr1, *ptr1);
	printf("ptr2 %p value: %f\n", ptr2, *ptr2);
	printf("test_val value: %d\n", *test_val);
	printf("Running gforced garbage collector\n");
	gc_garbage();
	printf("Running gforced garbage collector\n");
	printf("ptr1 %p value: %d\n", ptr1, *ptr1);
	printf("ptr2 %p value: %f\n", ptr2, *ptr2);
	printf("test_val value: %d\n", *test_val);
	return (EXIT_SUCCESS);
}
