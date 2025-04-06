/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:21:06 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/12 09:23:22 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //to use write

int	main(int argc, char *argv[])
{
	int	arg_index;

	arg_index = argc - 1;
	while (arg_index > 0)
	{
		while (*argv[arg_index] != '\0')
		{
			write(1, &*argv[arg_index], 1);
			argv[arg_index]++;
		}
		write(1, "\n", 1);
		arg_index--;
	}
}
