/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:46:37 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/12 13:48:15 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base, int *error_flag);
long	ft_check_base(char *base);

// Fills in the malloc with the correct ascii.
void	ft_fill_malloc(char *result, long temp_nbr, char *base, int max_index)
{
	int	index;
	int	base_size;
	int	offset;

	offset = 2;
	base_size = ft_check_base(base);
	index = 0;
	if (temp_nbr < 0)
	{
		result[index] = '-';
		temp_nbr *= -1;
		offset = 1;
		index++;
	}
	while (temp_nbr != 0)
	{
		result[max_index - index - offset] = base[temp_nbr % base_size];
		temp_nbr /= base_size;
		index++;
	}
	result[max_index] = '\0';
}

int	ft_get_malloc_size(long long_nbr, int *minus_flag, int base_size)
{
	int	malloc_size;

	malloc_size = 1;
	if (long_nbr < 0)
	{
		malloc_size++;
		*minus_flag = 1;
	}
	while (long_nbr != 0)
	{
		malloc_size++;
		long_nbr /= base_size;
	}
	return (malloc_size);
}

// Calculates the needed size to malloc for the resulting string.
int	ft_create_result(char **result, int temp_nbr, char *base)
{
	int		base_size;
	int		malloc_size;
	int		minus_flag;
	long	long_nbr;

	long_nbr = (long) temp_nbr;
	minus_flag = 0;
	base_size = ft_check_base(base);
	if (base_size <= 1)
		return (-1);
	malloc_size = ft_get_malloc_size(long_nbr, &minus_flag, base_size);
	*result = malloc(malloc_size * sizeof(char));
	if (result == ((void *)0))
		return (-1);
	ft_fill_malloc(*result, (long)temp_nbr, base, malloc_size);
	return (1);
}

// Convert a ascii number to an int from a base
// to then convert back to ascii in another base
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		temp_nbr;
	char	*result;
	int		error_flag;

	error_flag = 0;
	temp_nbr = ft_atoi_base(nbr, base_from, &error_flag);
	if (error_flag == 1)
		return ((void *)0);
	if (ft_create_result(&result, temp_nbr, base_to) == -1)
		return ((void *)0);
	return (result);
}
