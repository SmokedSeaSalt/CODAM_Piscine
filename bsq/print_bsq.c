/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:03:38 by egrisel           #+#    #+#             */
/*   Updated: 2025/03/12 13:37:55 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// loop through the rows and print each char of each row untill \0;
void	printf_bsq(char **map_matrix, int num_rows)
{
	int	i_row;
	int	i_col;

	i_row = 0;
	i_col = 0;
	while (i_row < num_rows)
	{
		i_col = 0;
		while (map_matrix[i_row][i_col])
		{
			write(1, &map_matrix[i_row][i_col], 1);
			i_col++;
		}
		write(1, "\n", 1);
		i_row++;
	}
}
