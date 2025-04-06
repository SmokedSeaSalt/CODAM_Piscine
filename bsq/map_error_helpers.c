/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:21:08 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/12 15:18:02 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define I_EMPTY_CHAR 0
#define I_OBSTACLE_CHAR 1
#define I_FILL_CHAR 2

//do atoi for n chars
int	ft_atoin(char *file, int n)
{
	int	index;
	int	ret_nbr;

	index = 0;
	ret_nbr = 0;
	while (index < n)
	{
		ret_nbr += file[index] - '0';
		ret_nbr *= 10;
		index++;
	}
	ret_nbr /= 10;
	return (ret_nbr);
}

//check if the bsq chars are unique
int	ft_check_chars_unique(char *chars)
{
	if (chars[0] < ' ' || chars[0] > '~')
		return (-1);
	if (chars[1] < ' ' || chars[1] > '~')
		return (-1);
	if (chars[2] < ' ' || chars[2] > '~')
		return (-1);
	if (chars[0] == chars [1])
		return (-1);
	else if (chars[0] == chars [2])
		return (-1);
	else if (chars[1] == chars [2])
		return (-1);
	else
		return (1);
}

//check if the chars are numbers for size n
int	ft_check_numbers_n(char *str, int n)
{
	int	index;

	index = 0;
	while (index < n)
	{
		if (str[index] < '0' || str[index] > '9')
			return (-1);
		index++;
	}
	return (1);
}

//check if current char in map is a allowed char
int	ft_check_char_allowed(char c, char *chars)
{
	if (c != chars[I_EMPTY_CHAR] && c != chars[I_OBSTACLE_CHAR]
		&& c != '\n')
		return (-1);
	return (1);
}
