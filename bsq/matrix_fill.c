/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:21:36 by egrisel           #+#    #+#             */
/*   Updated: 2025/03/12 15:05:10 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**allocate_char_matrix(int num_rows, int num_cols)
{
	char	**matrix;
	int		i_row;

	matrix = malloc(sizeof(char *) * (num_rows));
	if (!matrix)
		return (NULL);
	i_row = 0;
	while (i_row < num_rows)
	{
		matrix[i_row] = malloc(sizeof(char) * (num_cols + 1));
		if (!matrix[i_row])
		{
			free(matrix);
			return (NULL);
		}
		i_row++;
	}
	return (matrix);
}

void	assign_matrix(char *buff, char **matrix, int num_rows)
{
	int	i_buff;
	int	i_rows;
	int	i_cols;

	i_rows = 0;
	i_cols = 0;
	i_buff = 0;
	while (buff[i_buff] != '\0' && i_rows < num_rows)
	{
		if (buff[i_buff] == '\n')
		{
			matrix[i_rows][i_cols] = '\0';
			i_rows++;
			i_cols = 0;
		}
		else
		{
			matrix[i_rows][i_cols] = buff[i_buff];
			i_cols++;
		}
		i_buff++;
	}
}

char	**matrix_fill(char *buff, int num_rows, int num_cols)
{
	int		i_buff;
	char	**matrix;

	matrix = NULL;
	i_buff = 0;
	while (buff[i_buff] != '\n')
		i_buff++;
	i_buff++;
	matrix = allocate_char_matrix(num_rows, num_cols);
	if (!matrix)
		return (NULL);
	assign_matrix(&buff[i_buff], matrix, num_rows);
	return (matrix);
}
