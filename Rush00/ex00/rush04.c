/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:38:21 by gshekari          #+#    #+#             */
/*   Updated: 2025/02/23 11:16:13 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	ft_check_b(int x, int y, int x_index, int y_index)
{
	char	c;

	if (x_index != 1 && y_index != 1 && x_index != x && y_index != y)
	{
		c = ' ';
	}
	else
	{
		c = 'B';
	}
	return (c);
}

char	ft_check_ac(int x, int y, int x_index, int y_index)
{
	char	c;

	if ((x_index == x && y_index == y))
	{
		c = 'A';
	}
	if ((x_index == x && y_index == 1) || (x_index == 1 && y_index == y))
	{
		c = 'C';
	}
	if ((x_index == 1 && y_index == 1))
	{
		c = 'A';
	}
	return (c);
}

void	rush(int x, int y)
{
	int		y_index;
	int		x_index;
	char	c;

	y_index = 1;
	x_index = 1;
	while (y_index <= y && x != 0)
	{
		x_index = 1;
		while (x_index <= x)
		{
			c = ft_check_b(x, y, x_index, y_index);
			c = ft_check_ac(x, y, x_index, y_index);
			ft_putchar(c);
			x_index++;
		}
		y_index++;
		ft_putchar('\n');
	}
}
