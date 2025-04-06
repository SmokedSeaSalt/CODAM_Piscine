/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:36:23 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/05 10:01:59 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	index;

	index = 0;
	if (min >= max)
		return ((void *)0);
	arr = malloc((max - min) * sizeof(int));
	if (arr == (void *)0)
		return (0);
	while (min < max)
	{
		arr[index] = min;
		min++;
		index++;
	}
	return (arr);
}
