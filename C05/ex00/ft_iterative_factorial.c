/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:46:40 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/04 11:39:24 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	retval;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	retval = nb;
	nb--;
	while (nb > 0)
	{
		retval *= nb;
		nb--;
	}
	return (retval);
}
