/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:49:00 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/02/23 16:47:36 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //to use printf

void	*ft_print_memory(void *addr, unsigned int size)
{
	long	adressvalue;

	adressvalue = (long) addr;

	printf("size = %d %lx", size, adressvalue);


	return (addr);
}
