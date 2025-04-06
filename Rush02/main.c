/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgroos <mgroos@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:27:57 by mgroos            #+#    #+#             */
/*   Updated: 2025/03/09 16:56:54 by mgroos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str);
int		file_open_read(char *str, char **file);
void	spell_number(char *nbrstr, char word_arr[41][40], char nbr_arr[41][40]);
void	fill_nbr_arr(char *file, char nbr_arr[41][40]);
void	fill_word_arr(char *file, char word_arr[41][40]);
char	*str_numeric_length(char *str);

int	ft_arg_check(int argc, char *argv[], char **nbr, char **file)
{
	int		check_err;

	check_err = 0;
	if (argc < 2)
		return (-1);
	else if (argc == 2)
	{
		*nbr = argv[1];
		check_err = file_open_read("dict_file/numbers.dict", file);
	}
	else
	{
		*nbr = argv[2];
		check_err = file_open_read(argv[1], file);
	}
	if (check_err == -1)
		return (-2);
	return (1);
}

void	print_error(int check_err)
{
	if (check_err == -1)
	{
		ft_putstr("Error\n");
	}
	if (check_err == -2)
	{
		ft_putstr("Dict Error\n");
	}
}

int	main(int argc, char *argv[])
{
	char	*nbr;
	char	*file;
	char	word_arr[41][40];
	char	nbr_arr[41][40];
	int		check_err;

	file = (void *)0;
	check_err = ft_arg_check (argc, argv, &nbr, &file);
	print_error(check_err);
	if (check_err < 0)
		return (0);
	fill_nbr_arr(file, nbr_arr);
	fill_word_arr(file, word_arr);
	nbr = str_numeric_length(nbr);
	if (nbr[0] == '\0')
	{
		ft_putstr("Error\n");
		return (0);
	}
	spell_number(nbr, word_arr, nbr_arr);
	free(file);
}
