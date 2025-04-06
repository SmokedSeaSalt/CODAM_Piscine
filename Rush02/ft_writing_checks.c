/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgroos <mgroos@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:36:05 by mgroos            #+#    #+#             */
/*   Updated: 2025/03/09 16:39:56 by mgroos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_999(int nbr, char word_arr[41][40], char nbr_arr[41][40]);
void	print_xillion(char word_arr[41][40], char nbr_arr[41][40], int restlen);
int		ft_str_len(char *str);

// check if it's not going to print zero accidentally
void	try_write_below_1000(int nbr_under_1000, char word_arr[41][40],
	char nbr_arr[41][40])
{
	if (nbr_under_1000 != 0)
	{
		ft_write_999(nbr_under_1000, word_arr, nbr_arr);
		write(1, " ", 1);
	}
}

// check if it's not going to print the large number when there's zero of it
void	try_write_xillion(int nbr_under_1000, char word_arr[41][40],
	char nbr_arr[41][40], char *nbrstr)
{
	if (nbr_under_1000 != 0)
		print_xillion(word_arr, nbr_arr, ft_str_len(nbrstr));
}
