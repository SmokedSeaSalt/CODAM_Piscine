/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:53:58 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/06 17:03:08 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks the base for - printable characters
//					   - double characters
//					   - forbidden characters (+ and -)
// return value if error 	= -1
// return value if correct 	= length of base
long	ft_check_base(char *base)
{
	long	base_size;
	long	current_index;
	long	check_index;

	base_size = 0;
	while (base[base_size] != '\0')
	{
		if (base[base_size] == '-' || base[base_size] == '+'
			|| base[base_size] < '!' || base[base_size] > '~')
			return (-1);
		base_size++;
	}
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
	return (base_size);
}

// find char c in the base
// return value if error 	= -1 (char not in base)
// return value if correct 	= c value according to base
long	ft_find_char_value(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

// parses the input string 	- remove trailing spaces.
//					  		- counting amount of "-"
//					  		- gives start of integer string
// return value if error 	= -1
// return value if correct 	= length of valid integer string
long	ft_check_str(char *str, int *minus_counter)
{
	int		str_index;

	str_index = 0;
	while ((str[str_index] >= '\t' && str[str_index] <= '\r')
		|| str[str_index] == ' ')
	{
		str_index++;
	}
	while (str[str_index] == '+' || str[str_index] == '-')
	{
		if (str[str_index] == '-')
			(*minus_counter)++;
		str_index++;
	}
	return (str_index);
}

// goes through the valid str	- gets the correct char value for the position
//								  and add to value
//								- checks until str char doesn't match
//								  any chars in base
// return value is size of the integer in str according to base
// result is always positive
// negative check and apply should still happen after this function
long	ft_str_value(char *str, char *base, long base_size)
{
	int		index;
	long	value;

	index = 0;
	value = 0;
	while (ft_find_char_value(base, str[index]) >= 0)
	{
		value += ft_find_char_value(base, str[index]);
		value *= base_size;
		index++;
	}
	value /= base_size;
	return (value);
}

//you dont have to print. only return the int.
//check if every char in str is in base? (exept + and -)
int	ft_atoi_base(char *str, char *base, int *error_flag)
{
	long	base_size;
	int		str_start;
	int		minus_counter;
	long	returnval;

	minus_counter = 0;
	base_size = ft_check_base(base);
	str_start = ft_check_str(str, &minus_counter);
	if (base_size <= 1)
		*error_flag = 1;
	returnval = ft_str_value(&str[str_start], base, base_size);
	if (minus_counter % 2 == 1)
		returnval *= -1;
	return ((int)returnval);
}
