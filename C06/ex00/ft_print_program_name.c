/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:12:19 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/12 09:19:03 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //to use write

int	main(int argc, char *argv[])
{
	(void)argc;
	while (*argv[0] != '\0')
	{
		write(1, &*argv[0], 1);
		argv[0]++;
	}
	write(1, "\n", 1);
}
