/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:05:32 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/02/27 09:35:16 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_int_min(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (1);
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	int		i;
	char	c;

	if (ft_check_int_min(nb))
		return ;
	if (nb < 0)
	{
		nb = nb * -1;
		c = '-';
		write(1, &c, 1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		i = (nb % 10);
		c = '0' + i;
		write(1, &c, 1);
	}
	else
	{
		c = '0' + nb;
		write(1, &c, 1);
	}
}
