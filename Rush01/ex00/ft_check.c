/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbakker <dbakker@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:40:49 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/02 17:06:26 by dbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check if row is correct according to input.
//check increases compared to highest one already seen left to right
//if it does not match rowxleft return -1
//if passes everything return 1
int	ft_check_row_ltor(int row_nbr, int matrix[4][4], int *input)
{
	int	index;
	int	currentmax;
	int	n_increased;

	index = 0;
	currentmax = 0;
	n_increased = 0;
	while (index < 4)
	{
		if (matrix[row_nbr][index] > currentmax)
		{
			currentmax = matrix[row_nbr][index];
			n_increased++;
		}
		index++;
	}
	if (n_increased != input[8 + row_nbr])
		return (-1);
	return (1);
}

//check increases compared to highest one already seen right to left
//if it does not match rowxrigt return -1
//if passes everything return 1
int	ft_check_row_rtol(int row_nbr, int matrix[4][4], int *input)
{
	int	index;
	int	currentmax;
	int	n_increased;

	index = 3;
	currentmax = 0;
	n_increased = 0;
	while (index >= 0)
	{
		if (matrix[row_nbr][index] > currentmax)
		{
			currentmax = matrix[row_nbr][index];
			n_increased++;
		}
		index--;
	}
	if (n_increased != input[12 + row_nbr])
		return (-1);
	return (1);
}

//check increases compared to highest one already seen up to down
//if it does not match colxup return -1
//if passes everything return 1
int	ft_check_col_utod(int col_nbr, int matrix[4][4], int *input)
{
	int	index;
	int	currentmax;
	int	n_increased;

	index = 0;
	currentmax = 0;
	n_increased = 0;
	while (index < 4)
	{
		if (matrix[index][col_nbr] > currentmax)
		{
			currentmax = matrix[index][col_nbr];
			n_increased++;
		}
		index++;
	}
	if (n_increased != input[col_nbr])
		return (-1);
	return (1);
}

//check increases compared to highest one already seen down to up
//if it does not match colxdown return -1
//if passes everything return 1
int	ft_check_col_dtou(int col_nbr, int matrix[4][4], int *input)
{
	int	index;
	int	currentmax;
	int	n_increased;

	index = 3;
	currentmax = 0;
	n_increased = 0;
	while (index >= 0)
	{
		if (matrix[index][col_nbr] > currentmax)
		{
			currentmax = matrix[index][col_nbr];
			n_increased++;
		}
		index--;
	}
	if (n_increased != input[4 + col_nbr])
		return (-1);
	return (1);
}
