/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_999.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgroos <mgroos@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:35:30 by mgroos            #+#    #+#             */
/*   Updated: 2025/03/09 13:02:21 by mgroos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //to use write

int	ft_str_len(char *str);
int	ft_atoin(char *str, int length);

// function to write 0-20 bc they're all special cases
void	ft_write_20(int nbr, char word_arr[41][40], char nbr_arr[41][40])
{
	int	i;
	int	array_int;
	int	nbr_len;
	int	word_len;

	i = 0;
	while (i <= 20)
	{
		nbr_len = ft_str_len(nbr_arr[i]);
		array_int = ft_atoin(nbr_arr[i], nbr_len);
		if (array_int == nbr)
		{
			word_len = ft_str_len(word_arr[i]);
			write(1, &word_arr[i], word_len);
		}
		i++;
	}
}

// write the second digit from a number >20 and <100
// [3 will write thirty, 5 will write fifty, etc]
// returns nbr at the end in case we want to do something
	// where we modify it at some point? but can be made
	// to return void if not.
void	ft_write_tens(int nbr, char word_arr[41][40], char nbr_arr[41][40])
{
	int	i;
	int	array_int;
	int	nbr_len;
	int	word_len;
	int	second_digit;

	second_digit = nbr / 10 * 10;
	if (second_digit != 0)
	{
		i = 0;
		while (i < 100)
		{
			nbr_len = ft_str_len(nbr_arr[i]);
			array_int = ft_atoin(nbr_arr[i], nbr_len);
			if (array_int == second_digit)
			{
				word_len = ft_str_len(word_arr[i]);
				write(1, &word_arr[i], word_len);
			}
			i++;
		}
	}
}

// write the final digit of a number (1-9) > to be used for any numbers > 20
void	ft_write_final(int nbr, char word_arr[41][40], char nbr_arr[41][40])
{
	int	i;
	int	array_int;
	int	nbr_len;
	int	word_len;
	int	final_digit;

	final_digit = nbr % 10;
	if (final_digit != 0)
	{
		i = 0;
		while (i < 10)
		{
			nbr_len = ft_str_len(nbr_arr[i]);
			array_int = ft_atoin(nbr_arr[i], nbr_len);
			if (array_int == final_digit)
			{
				word_len = ft_str_len(word_arr[i]);
				write(1, &word_arr[i], word_len);
			}
			i++;
		}
	}
}

// function to write large single words
	// only works with words from dict
	// like 'hundred' or 'thousand'
	// (see function call in ft_write_hundreds function)
void	ft_write_large(int nbr, char word_arr[41][40], char nbr_arr[41][40])
{
	int	i;
	int	array_int;
	int	nbr_len;
	int	word_len;

	write(1, " ", 1);
	i = 0;
	while (i < 42)
	{
		nbr_len = ft_str_len(nbr_arr[i]);
		array_int = ft_atoin(nbr_arr[i], nbr_len);
		if (array_int == nbr)
		{
			word_len = ft_str_len(word_arr[i]);
			write(1, &word_arr[i], word_len);
		}
		i++;
	}
}

// function to write the hundreds
// adds the word hundred through a separate function due to length
int	ft_write_hundreds(int nbr, char word_arr[41][40], char nbr_arr[41][40])
{
	int	i;
	int	array_int;
	int	nbr_len;
	int	word_len;
	int	print_digit;

	print_digit = nbr / 100;
	if (print_digit != 0)
	{
		i = 0;
		while (i < 10)
		{
			nbr_len = ft_str_len(nbr_arr[i]);
			array_int = ft_atoin(nbr_arr[i], nbr_len);
			if (array_int == print_digit)
			{
				word_len = ft_str_len(word_arr[i]);
				write(1, &word_arr[i], word_len);
			}
			i++;
		}
	}
	nbr = nbr - print_digit * 100;
	ft_write_large(100, word_arr, nbr_arr);
	return (nbr);
}
