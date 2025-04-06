/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:37:15 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/02/27 15:22:27 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_double_char(char *base, long base_size)
{
	int	current_index;
	int	check_index;

	current_index = 0;
	while (current_index < base_size - 1)
	{
		check_index = current_index + 1;
		while (check_index < base_size)
		{
			if (base[current_index] == base[check_index])
				return (0);
			check_index++;
		}
		current_index++;
	}
	return (1);
}

long	ft_check_base(char *base)
{
	long	base_size;

	base_size = 0;
	while (base[base_size] != '\0')
	{
		if (base[base_size] == '-' || base[base_size] == '+'
			|| base[base_size] < ' ' || base[base_size] > '~')
			return (-1);
		base_size++;
	}
	if (ft_check_double_char(base, base_size) == 0)
		return (-1);
	return (base_size);
}

void	ft_print_base(char *base, long rest, int base_size)
{
	if (rest > base_size - 1)
	{
		ft_print_base(base, rest / base_size, base_size);
		write(1, &base[rest % base_size], 1);
	}
	else
		write(1, &base[rest % base_size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	base_size;
	long	long_nbr;

	long_nbr = (long) nbr;
	base_size = ft_check_base(base);
	if (base_size <= 1)
		return ;
	if (long_nbr < 0)
	{
		write(1, "-", 1);
		long_nbr *= -1;
	}
	ft_print_base(base, long_nbr, base_size);
}
