/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbakker <dbakker@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:56:19 by dbakker           #+#    #+#             */
/*   Updated: 2025/03/01 15:53:41 by dbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb);
void	ft_putstr(char *str);

void	ft_print_output(int *matrix)
{
	int	i;
	int	j;
	int	k;
	int	print_matrix[4][4];

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			print_matrix[i][j] = matrix[k++];
			ft_putnbr(print_matrix[i][j]);
			j++;
			if (j < 4)
				ft_putstr(" ");
		}
		i++;
		ft_putstr("\n");
		j = 0;
	}
}
