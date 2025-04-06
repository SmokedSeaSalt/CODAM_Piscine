/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:15:21 by egrisel           #+#    #+#             */
/*   Updated: 2025/03/12 16:06:31 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	find_bsq(char *buff, int num_rows, int num_cols, char *chars);
int		check_map(char *file, int *num_rows, char *chars);
int		file_open_read(char *file_name, char **file);

int	get_num_cols(char *buff)
{
	int	i_buff;
	int	count;

	i_buff = 0;
	while (buff[i_buff] != '\n')
		i_buff++;
	i_buff++;
	count = 0;
	while (buff[i_buff] != '\n')
	{
		i_buff++;
		count++;
	}
	return (count);
}

void	check_read_and_print_bsq(char *file_name)
{
	char	*buff;
	int		num_rows;
	int		num_cols;
	char	chars[3];

	if (file_open_read(file_name, &buff) == -1)
	{
		write(2, "map error\n", 10);
		return ;
	}
	if (check_map(buff, &num_rows, chars) == 1)
	{
		num_cols = get_num_cols(buff);
		find_bsq(buff, num_rows, num_cols, chars);
	}
	free(buff);
}

int	main(int argc, char *argv[])
{
	int		i_argv;
	char	*current_file_name;
	char	stdin_buff[1024];
	int		read_len;

	if (argc == 1)
	{
		read_len = read(0, stdin_buff, 1024);
		stdin_buff[read_len - 1] = '\0';
		check_read_and_print_bsq(stdin_buff);
	}
	else
	{
		i_argv = 1;
		while (i_argv < argc)
		{
			current_file_name = argv[i_argv];
			check_read_and_print_bsq(current_file_name);
			if (i_argv != argc - 1)
			{
				write(1, "\n", 1);
			}
			i_argv++;
		}
	}
}
