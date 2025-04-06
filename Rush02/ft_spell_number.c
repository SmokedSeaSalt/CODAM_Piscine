/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_1000up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgroos <mgroos@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:38:04 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/09 16:38:09 by mgroos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //to use write

void	ft_putstr(char *str);
int		ft_str_len(char *str);
int		ft_atoin(char *str, int length);
int		ft_write_hundreds(int nbr, char word_arr[41][40], char nbr_arr[41][40]);
void	ft_write_final(int nbr, char word_arr[41][40], char nbr_arr[41][40]);
void	ft_write_tens(int nbr, char word_arr[41][40], char nbr_arr[41][40]);
void	ft_write_20(int nbr, char word_arr[41][40], char nbr_arr[41][40]);
void	try_write_below_1000(int nbr_under_1000, char word_arr[41][40],
			char nbr_arr[41][40]);
void	try_write_xillion(int nbr_under_1000, char word_arr[41][40],
			char nbr_arr[41][40], char *nbrstr);

// workflow for printing the number if it's <1000
// input is number as int
void	ft_write_999(int nbr, char word_arr[41][40], char nbr_arr[41][40])
{
	while (nbr >= 0)
	{
		if (nbr <= 20)
		{
			ft_write_20(nbr, word_arr, nbr_arr);
			break ;
		}
		else if (nbr < 100)
		{
			ft_write_tens(nbr, word_arr, nbr_arr);
			if (nbr % 10 != 0)
			{
				write(1, "-", 1);
				ft_write_final(nbr, word_arr, nbr_arr);
			}
			break ;
		}
		else if (nbr < 1000)
		{
			nbr = ft_write_hundreds(nbr, word_arr, nbr_arr);
			if (nbr % 100 == 0)
				break ;
			write(1, " and ", 5);
		}
	}
}

//check the size of the nbr in xillion list
//stop when you find one bigger then restlen
//print the according word.
void	print_xillion(char word_arr[41][40], char nbr_arr[41][40], int restlen)
{
	int	index;

	index = 0;
	while (ft_str_len(nbr_arr[index]) < restlen + 1)
		index++;
	ft_putstr(word_arr[index]);
	write(1, " ", 1);
}

//input: input number as str
//prints all the numbers in xillion and calls write_999 for each of them
//finishes with the last call to write_999
void	ft_write_1000(char *nbrstr, char word_arr[41][40], char nbr_arr[41][40])
{
	int	parselen;
	int	printed;
	int	first_loop;
	int	nbr_under_1000;

	printed = 0;
	first_loop = 0;
	parselen = (ft_str_len(nbrstr) % 3);
	while (ft_str_len(&nbrstr[printed]) > 3)
	{
		nbr_under_1000 = ft_atoin(&nbrstr[printed], parselen);
		try_write_below_1000(nbr_under_1000, word_arr, nbr_arr);
		if (first_loop == 0)
		{
			printed += parselen;
			parselen = 3;
			first_loop = 1;
		}
		else
			printed += 3;
		try_write_xillion(nbr_under_1000, word_arr, nbr_arr, &nbrstr[printed]);
	}
	nbr_under_1000 = ft_atoin(&nbrstr[printed], parselen);
	if (nbr_under_1000 != 0)
		ft_write_999(nbr_under_1000, word_arr, nbr_arr);
}

void	spell_number(char *nbrstr, char word_arr[41][40], char nbr_arr[41][40])
{
	if (ft_str_len(nbrstr) <= 3)
	{
		ft_write_999(ft_atoin((nbrstr), ft_str_len(nbrstr)),
			word_arr, nbr_arr);
	}
	else
	{
		ft_write_1000(nbrstr, word_arr, nbr_arr);
	}
	write(1, "\n", 1);
}
