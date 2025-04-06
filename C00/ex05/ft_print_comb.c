/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:48:05 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/02/19 17:47:21 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_digits(char c1, char c2, char c3)
{
	char	dotcomma[2];

	dotcomma[0] = ',';
	dotcomma[1] = ' ';
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, &c3, 1);
	if (!((c1 == '7') && (c2 == '8') && (c3 == '9')))
	{
		write(1, &dotcomma, 2);
	}
}

void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0';
	c2 = '1';
	c3 = '2';
	while (c1 < '8')
	{
		c2 = c1 + 1;
		while (c2 < '9')
		{
			c3 = c2 + 1;
			while (c3 < ':')
			{
				ft_print_digits(c1, c2, c3);
				c3++;
			}
			c2++;
		}
		c1++;
	}
}
