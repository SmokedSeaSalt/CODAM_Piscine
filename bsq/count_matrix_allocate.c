/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_matrix_allocate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:45:13 by egrisel           #+#    #+#             */
/*   Updated: 2025/03/12 13:50:33 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**allocate_int_matrix(int num_rows, int num_cols)
{
	int	**matrix;
	int	i_row;

	matrix = malloc(sizeof(int *) * (num_rows));
	if (!matrix)
		return (NULL);
	i_row = 0;
	while (i_row < num_rows)
	{
		matrix[i_row] = malloc(sizeof(int) * (num_cols));
		if (!matrix[i_row])
		{
			free(matrix);
			return (NULL);
		}
		i_row++;
	}
	return (matrix);
}

void	assign_zero_int_matrix(int **matrix, int num_rows, int num_cols)
{
	int	i_buff;
	int	i_rows;
	int	i_cols;

	i_rows = 0;
	i_buff = 0;
	while (i_rows < num_rows)
	{
		i_cols = 0;
		while (i_cols < num_cols)
		{
			matrix[i_rows][i_cols] = 0;
			i_cols++;
		}
		i_rows++;
	}
}

// receives dimensions of the map and creates a matrix full of zeros with
// one more col and one more row.
int	**count_matrix_allocate(int num_rows, int num_cols)
{
	int	**matrix;

	matrix = NULL;
	matrix = allocate_int_matrix(num_rows, num_cols);
	if (!matrix)
		return (NULL);
	assign_zero_int_matrix(matrix, num_rows, num_cols);
	return (matrix);
}
