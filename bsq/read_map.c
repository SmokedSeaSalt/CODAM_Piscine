/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:08:21 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/12 16:12:03 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h> //to use open
#include <fcntl.h> //to use open
#include <unistd.h> //to use close, read
#define MEM_SIZE 1024

int	file_open_read(char *file_name, char **file)
{
	int	file_dest;
	int	mem_inc;
	int	read_size;

	read_size = 0;
	mem_inc = 0;
	while (read_size == (MEM_SIZE) * mem_inc)
	{
		if (mem_inc != 0)
			free(*file);
		mem_inc++;
		file_dest = open(file_name, O_RDONLY);
		if (file_dest <= -1)
			return (-1);
		*file = malloc(MEM_SIZE * mem_inc * sizeof(char));
		if (*file == (void *)0)
			return (-1);
		read_size = read(file_dest, *file, (MEM_SIZE) * mem_inc);
		if (read_size <= -1)
			return (-1);
		if (close(file_dest) == -1)
			return (-1);
	}
	(*file)[read_size] = '\0';
	return (1);
}
