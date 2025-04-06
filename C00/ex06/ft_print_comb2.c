/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:23:17 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/02/19 12:44:25 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_digits(int i)
{
	char	dotcomma[2];
	char	c1;
	char	c2;
	char	c3;
	char	c4;

	c1 = '0' + (i / 10);
	c2 = '0' + (i % 10);
	c3 = '0' + ((i + 1) / 10);
	c4 = '0' + ((i + 1) % 10);
	dotcomma[0] = ',';
	dotcomma[1] = ' ';
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, &dotcomma[1], 1);
	write(1, &c3, 1);
	write(1, &c4, 1);
	write(1, &dotcomma, 2);
}

void	ft_print_comb2(void)
{
	int	i;

	i = 0;
	while (i < 99)
	{
		ft_print_digits(i);
		i++;
	}
}
