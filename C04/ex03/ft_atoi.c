/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:39:05 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/02/27 11:06:41 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_calculate_int(char *str, int minus)
{
	int		str_index;
	int		char_size;
	long	int_ret;

	str_index = 0;
	char_size = 0;
	int_ret = 0;
	while (str[char_size] >= '0' && str[char_size] <= '9')
	{
		char_size++;
	}
	while (str_index < char_size)
	{
		int_ret += (str[str_index] - '0');
		int_ret *= 10;
		str_index++;
	}
	int_ret /= 10;
	if (minus)
		int_ret *= -1;
	return (int_ret);
}

int	ft_atoi(char *str)
{
	int	str_index;
	int	minus_counter;

	str_index = 0;
	minus_counter = 0;
	while ((str[str_index] >= '\t' && str[str_index] <= '\r')
		|| str[str_index] == ' ')
	{
		str_index++;
	}
	while (str[str_index] == '+' || str[str_index] == '-')
	{
		if (str[str_index] == '-')
			minus_counter++;
		str_index++;
	}
	return (ft_calculate_int(&str[str_index], (minus_counter % 2)));
}
