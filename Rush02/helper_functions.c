/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:13:54 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/09 12:15:19 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //to use write

//print entire str using write
void	ft_putstr(char *str)
{
	int		str_len;

	str_len = 0;
	while (str[str_len] != '\0')
	{
		str_len++;
	}
	write(1, str, str_len);
}

// function to calculate a power
int	power(int base, int exp)
{
	int	counter;
	int	answer;

	answer = 1;
	counter = 0;
	while (counter < exp)
	{
		answer = answer * base;
		counter++;
	}
	return (answer);
}

// input: cleaned string with only integers
//		  (for our use it'll be 0-999, but works for large numbers too)
// input: length of string section that needs to be parsed
// output: int value of those characters
int	ft_atoin(char *str, int length)
{
	int	number;
	int	i;

	i = 0;
	number = 0;
	while (i < length)
	{
		number = number + (str[i] - 48) * power(10, (length - i - 1));
		i++;
	}
	return (number);
}

// quick str_len function
int	ft_str_len(char *str)
{
	int		str_len;

	str_len = 0;
	while (str[str_len] != '\0')
	{
		str_len++;
	}
	return (str_len);
}
