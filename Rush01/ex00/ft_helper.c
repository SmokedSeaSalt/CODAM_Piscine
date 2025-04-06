/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbakker <dbakker@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:08:55 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/02 16:31:03 by dbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_row_ltor(int row_nbr, int matrix[4][4], int *input);
int	ft_check_row_rtol(int row_nbr, int matrix[4][4], int *input);
int	ft_check_col_utod(int col_nbr, int matrix[4][4], int *input);
int	ft_check_col_dtou(int col_nbr, int matrix[4][4], int *input);

void	ft_fill_row(int matrix[4][4], int grab[24][4], int row_index, int row)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		matrix[row][i] = grab [row_index][i];
		i++;
	}
}

int	ft_check_unique_col(int matrix[4][4], int col_nbr)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (matrix[i][col_nbr] == matrix[j][col_nbr])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_all(int matrix[4][4], int input[16])
{
	int	rowcol_nbr[2];
	int	false_flag;

	false_flag = 1;
	rowcol_nbr[0] = 0;
	rowcol_nbr[1] = 0;
	while (rowcol_nbr[0] < 4)
	{
		if (ft_check_row_ltor(rowcol_nbr[0], matrix, input) != 1)
			false_flag = -1;
		if (ft_check_row_rtol(rowcol_nbr[0], matrix, input) != 1)
			false_flag = -1;
		rowcol_nbr[0]++;
	}
	while (rowcol_nbr[1] < 4)
	{
		if (ft_check_unique_col(matrix, rowcol_nbr[1]) != 1)
			false_flag = -1;
		if (ft_check_col_utod(rowcol_nbr[1], matrix, input) != 1)
			false_flag = -1;
		if (ft_check_col_dtou(rowcol_nbr[1], matrix, input) != 1)
			false_flag = -1;
		rowcol_nbr[1]++;
	}
	return (false_flag);
}
