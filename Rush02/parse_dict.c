/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:03:15 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/09 12:24:19 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h> //to use open
#include <sys/stat.h> //to use open
#include <fcntl.h> //to use open
#include <unistd.h> //to use close, read

//opens file -> reads file to big malloc -> close file.
//returns -1 when error occured.
int	file_open_read(char *str, char **file)
{
	int	file_dest;
	int	file_size;

	file_dest = open(str, O_RDONLY);
	if (file_dest == -1)
		return (-1);
	*file = malloc(1024 * sizeof(char));
	if (*file == (void *)0)
		return (-1);
	file_size = read(file_dest, *file, 1024);
	if (close(file_dest) == -1)
		return (-1);
	return (1);
}

//copies all the chars(exept spaces) before the ':' into nbr_arr
void	fill_nbr_arr(char *file, char nbr_arr[41][40])
{
	int	nbr_index;
	int	index;

	nbr_index = 0;
	index = 0;
	while (*file != '\0')
	{
		while (*file != ':')
		{
			if (*file != ' ')
			{
				nbr_arr[nbr_index][index] = *file;
				index++;
			}
			file++;
		}
		while (*file != '\n')
			file++;
		nbr_arr[nbr_index][index] = '\0';
		nbr_index++;
		index = 0;
		file++;
	}
}

//copies all the chars(exept spaces) after the ':' into word_arr
void	fill_word_arr(char *file, char word_arr[41][40])
{
	int	word_index;
	int	index;

	word_index = 0;
	index = 0;
	while (*file != '\0')
	{
		while (*file != ':')
			file++;
		file++;
		while (*file != '\n')
		{
			if (*file != ' ')
			{
				word_arr[word_index][index] = *file;
				index++;
			}
			file++;
		}
		word_arr[word_index][index] = '\0';
		word_index++;
		index = 0;
		file++;
	}
}
