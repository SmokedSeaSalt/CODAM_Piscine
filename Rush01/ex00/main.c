/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbakker <dbakker@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:12:06 by dbakker           #+#    #+#             */
/*   Updated: 2025/03/02 17:07:53 by dbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
int		ft_input_parsing(char *str, int *input);
void	ft_print_output(int *matrix);
void	ft_fill_row(int matrix[4][4], int grab[24][4], int row_index, int row);
int		ft_check_all(int matrix[4][4], int input[16]);
void	ft_generate_grab(int grab[24][4]);

int	ft_loop_all_2(int matrix[4][4], int input[16], int grab[24][4])
{
	int	row2_index;
	int	row3_index;

	row2_index = 0;
	row3_index = 0;
	while (row2_index < 24)
	{
		ft_fill_row(matrix, grab, row2_index, 2);
		while (row3_index < 24)
		{
			ft_fill_row(matrix, grab, row3_index, 3);
			if (ft_check_all(matrix, input) == 1)
			{
				ft_print_output(*matrix);
				return (1);
			}
			row3_index++;
		}
		row3_index = 0;
		row2_index++;
	}
	row2_index = 0;
	return (-1);
}

//return 1 after printing correct output
//return -1 after printing error nothing could be found
int	ft_loop_all_1(int matrix[4][4], int input[16], int grab[24][4])
{
	int	row0_index;
	int	row1_index;

	row0_index = 0;
	row1_index = 0;
	while (row0_index < 24)
	{
		ft_fill_row(matrix, grab, row0_index, 0);
		while (row1_index < 24)
		{
			ft_fill_row(matrix, grab, row1_index, 1);
			if (ft_loop_all_2(matrix, input, grab) == 1)
				return (1);
			row1_index++;
		}
		row1_index = 0;
		row0_index++;
	}
	return (-1);
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		input[16];
	int		matrix[4][4];
	int		grab[24][4];

	ft_generate_grab(grab);
	str = argv[1];
	if (argc != 2)
	{
		ft_putstr("Error");
		return (-1);
	}
	if (ft_input_parsing(str, input) != 1)
	{
		ft_putstr("Error");
		return (-1);
	}
	if (ft_loop_all_1(matrix, input, grab) != 1)
	{
		ft_putstr("Error");
		return (-1);
	}
}
