/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:20:19 by egrisel           #+#    #+#             */
/*   Updated: 2025/03/12 15:19:31 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_sub_int_lists(int **matrix, int num_rows)
{
	int	i;

	i = 0;
	while (i < num_rows)
	{
		free(matrix[i]);
		i++;
	}
}

void	free_sub_char_lists(char **matrix, int num_rows)
{
	int	i;

	i = 0;
	while (i < num_rows)
	{
		free(matrix[i]);
		i++;
	}
}

int	*allocate_bsq_coordinate(void)
{
	int	*bsq_coordinate;

	bsq_coordinate = malloc(3 * sizeof(int));
	bsq_coordinate[0] = -1;
	bsq_coordinate[1] = -1;
	bsq_coordinate[2] = -1;
	return (bsq_coordinate);
}

void	set_bsq_coordinate(int i_row, int i_col,
			int cur_max, int bsq_coordinate[3])
{
	bsq_coordinate[0] = i_row;
	bsq_coordinate[1] = i_col;
	bsq_coordinate[2] = cur_max;
}
