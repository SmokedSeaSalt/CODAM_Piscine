/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:30:29 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/02/19 19:12:55 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comma_space(void)
{
	char	commaspace[2];

	commaspace[0] = ',';
	commaspace[1] = ' ';
	write(1, &commaspace, 2);
}

void	ft_iterate_number(char number[], int n, int i)
{
	while (number[i] < (';' - n + i - 1))
	{
		if (i != n - 1)
		{
			number[i + 1] = number[i] + 1;
			ft_iterate_number(number, n, i + 1);
		}
		write(1, number, n);
		if (number[i - n] != (';' - n))
		{
			ft_print_comma_space();
		}
		number[i]++;
	}
}

void	ft_print_combn(int n)
{
	char	number[10];
	int		i;

	i = 0;
	while (i < n)
	{
		number[i] = '0' + i;
		i++;
	}
	i = 0;
	ft_iterate_number(number, n, i);
	while (i < n)
	{
		number[i] = '0' + 10 - n + i;
		i++;
	}
	write(1, number, n);
}
