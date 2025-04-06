/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:34:57 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/05 10:02:39 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		index;
	int		size;

	size = max - min;
	index = 0;
	if (min >= max)
	{
		*range = (void *)0;
		return (0);
	}
	*range = malloc((size) * sizeof(int));
	if (*range == (void *)0)
		return (0);
	while (min < max)
	{
		(*range)[index] = min;
		min++;
		index++;
	}
	return (size);
}
