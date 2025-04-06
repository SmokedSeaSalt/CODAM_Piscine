/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:05:29 by egrisel           #+#    #+#             */
/*   Updated: 2025/03/12 16:05:48 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define I_EMPTY_CHAR 0
#define I_OBSTACLE_CHAR 1
#define I_FILL_CHAR 2

char	**matrix_fill(char *buff, int num_rows, int num_cols);
int		**count_matrix_allocate(int num_rows, int num_cols);
void	printf_bsq(char **map_matrix, int num_rows);
void	free_sub_int_lists(int **matrix, int num_rows);
void	free_sub_char_lists(char **matrix, int num_rows);
int		*allocate_bsq_coordinate(void);
void	set_bsq_coordinate(int i_row, int i_col, int cur_max,
			int bsq_coordinate[3]);

// gets the smallest neighbour up, left , left up and adds one.
// set cur_min to up, then check left , then up left.
// return cur_min + 1
int	fill_empty_count_value(int **count_matrix, int i_row, int i_col)
{
	int	cur_min;

	if (i_row == 0 || i_col == 0)
	{
		return (1);
	}
	cur_min = count_matrix[i_row - 1][i_col];
	if (count_matrix[i_row][i_col - 1] < cur_min)
	{
		cur_min = count_matrix[i_row][i_col - 1];
	}
	if (count_matrix[i_row - 1][i_col - 1] < cur_min)
	{
		cur_min = count_matrix[i_row - 1][i_col - 1];
	}
	return (cur_min + 1);
}

void	fill_count_matrix(char **map_matrix, int **count_matrix,
	char *chars, int *row_col_num_arr)
{
	int	i_row;
	int	i_col;
	int	num_rows;
	int	num_cols;

	i_row = 0;
	num_rows = row_col_num_arr[0];
	num_cols = row_col_num_arr[1];
	while (i_row < num_rows)
	{
		i_col = 0;
		while (i_col < num_cols)
		{
			if (map_matrix[i_row][i_col] == chars[I_EMPTY_CHAR])
			{
				count_matrix[i_row][i_col]
					= fill_empty_count_value(count_matrix, i_row, i_col);
			}
			else if (map_matrix[i_row][i_col] == chars[I_OBSTACLE_CHAR])
				count_matrix[i_row][i_col] = 0;
			i_col++;
		}
		i_row++;
	}
}

int	*find_btm_right_corner(int **count_matrix, int num_rows, int num_cols)
{
	int	cur_max;
	int	i_row;
	int	i_col;
	int	*bsq_coordinate;

	cur_max = 0;
	i_row = 0;
	bsq_coordinate = allocate_bsq_coordinate();
	if (!bsq_coordinate)
		return (NULL);
	while (i_row < num_rows)
	{
		i_col = 0;
		while (i_col < num_cols)
		{
			if (count_matrix[i_row][i_col] > cur_max)
			{
				cur_max = count_matrix[i_row][i_col];
				set_bsq_coordinate(i_row, i_col, cur_max, bsq_coordinate);
			}
			i_col++;
		}
		i_row++;
	}
	return (bsq_coordinate);
}

void	set_bsq(char **map_matrix, char *chars, int *bsq_coordinate)
{
	int	i_row;
	int	i_col;

	i_row = bsq_coordinate[0] - bsq_coordinate[2] + 1;
	while (i_row <= bsq_coordinate[0])
	{
		i_col = bsq_coordinate[1] - bsq_coordinate[2] + 1;
		while (i_col <= bsq_coordinate[1])
		{
			map_matrix[i_row][i_col] = chars[I_FILL_CHAR];
			i_col++;
		}
		i_row++;
	}
}

void	find_bsq(char *buff, int num_rows, int num_cols, char *chars)
{
	char	**map_matrix;
	int		**count_matrix;
	int		row_col_num_arr[2];
	int		*bsq_coordinate;

	map_matrix = matrix_fill(buff, num_rows, num_cols);
	if (!map_matrix)
		return ;
	count_matrix = count_matrix_allocate(num_rows, num_cols);
	if (!count_matrix)
		return ;
	row_col_num_arr[0] = num_rows;
	row_col_num_arr[1] = num_cols;
	fill_count_matrix(map_matrix, count_matrix, chars, row_col_num_arr);
	bsq_coordinate = find_btm_right_corner(count_matrix, num_rows, num_cols);
	if (!bsq_coordinate)
		return ;
	set_bsq(map_matrix, chars, bsq_coordinate);
	printf_bsq(map_matrix, num_rows);
	free_sub_char_lists(map_matrix, num_rows);
	free(map_matrix);
	free_sub_int_lists(count_matrix, num_rows);
	free(count_matrix);
	free(bsq_coordinate);
}
