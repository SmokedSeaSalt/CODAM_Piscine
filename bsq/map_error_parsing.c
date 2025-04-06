/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:55:55 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/12 15:52:47 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //used for write
#define I_EMPTY_CHAR 0
#define I_OBSTACLE_CHAR 1
#define I_FILL_CHAR 2

int	ft_atoin(char *file, int n);
int	ft_check_chars_unique(char *chars);
int	ft_check_numbers_n(char *str, int n);
int	ft_check_char_allowed(char c, char *chars);

//get the indexchars
//check if chars until the indexchars are only numbers.
//do atoin to get num_rows
int	get_firstrow_vals(char *file, char *chars, int *num_rows)
{
	int	file_index;
	int	char_index;

	file_index = 0;
	char_index = 1;
	if (file[file_index] == '\0')
	{
		return (-1);
	}
	while (file[file_index] != '\n')
		file_index++;
	if (file_index < 4)
		return (-1);
	chars[I_EMPTY_CHAR] = file[file_index - 3];
	chars[I_OBSTACLE_CHAR] = file[file_index - 2];
	chars[I_FILL_CHAR] = file[file_index - 1];
	if (ft_check_numbers_n(file, file_index - 3) == 1)
		*num_rows = ft_atoin(file, file_index - 3);
	else
		return (-1);
	return (1);
}

void	ft_init_count(int *file_i, int *row_i, int *row_w_i, int *first_row_w)
{
	*row_w_i = 0;
	*row_i = 0;
	*file_i = 0;
	*first_row_w = -1;
}

//return = -1 if error is found
//return = rows_counted if no error occured
int	ft_count_rows(char *file, char *chars)
{
	int	file_index;
	int	row_index;
	int	row_width_index;
	int	first_row_width;

	ft_init_count(&file_index, &row_index, &row_width_index, &first_row_width);
	while (file[file_index] != '\0')
	{
		row_width_index++;
		if (ft_check_char_allowed(file[file_index], chars) == -1)
			return (-1);
		if (file[file_index] == '\n')
		{
			row_index++;
			if (first_row_width == -1)
				first_row_width = row_width_index;
			if (row_width_index != first_row_width || row_width_index == 1)
				return (-1);
			row_width_index = 0;
		}
		file_index++;
	}
	return (row_index);
}

//checks if the number of rows are correct.
//checks if all rows are the same size
//checks if all rows only contain the allowed index chars
//return = -1 if any of the check fails
//return = 1 if all checks pass
int	ft_check_rows(char *file, char *chars, int *num_rows)
{
	int	row_index;
	int	file_index;

	file_index = 0;
	while (file[file_index] != '\n')
		file_index++;
	file_index++;
	row_index = ft_count_rows(&file[file_index], chars);
	if (row_index != *num_rows)
		return (-1);
	return (1);
}

//does all the error checks and print maperror\n in case of error
//returns = -1 when any error occured
//returns = 1 if all checks pass
int	check_map(char *file, int *num_rows, char *chars)
{
	if (get_firstrow_vals(file, chars, num_rows) == -1)
	{
		write(2, &"map error\n", 10);
		return (-1);
	}
	if (ft_check_chars_unique(chars) == -1)
	{
		write(2, "map error\n", 10);
		return (-1);
	}
	if (ft_check_rows(file, chars, num_rows) == -1)
	{
		write(2, &"map error\n", 10);
		return (-1);
	}
	return (1);
}
