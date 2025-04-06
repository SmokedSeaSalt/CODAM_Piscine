/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:01:16 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/02/24 16:14:56 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		c;
	char	*hexstring;

	hexstring = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= ' ' && str[i] <= '~'))
		{
			c = str[i];
			write(1, &c, 1);
		}
		else
		{
			c = '\\';
			write(1, &c, 1);
			c = str[i];
			write(1, &hexstring[c / 16], 1);
			write(1, &hexstring[c % 16], 1);
		}
		i++;
	}
}
