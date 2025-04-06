/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbakker <dbakker@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:31:32 by dbakker           #+#    #+#             */
/*   Updated: 2025/03/02 17:03:26 by dbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_input_parsing(char *str, int *input)
{
	int	nbr_counter;
	int	i;

	nbr_counter = 0;
	i = 0;
	while (*str)
	{
		if ((str[i] >= '1' && str[i] <= '4')
			&& (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			input[nbr_counter] = str[i] - '0';
			nbr_counter++;
			str++;
		}
		else
			return (-1);
		while (str[i] == ' ')
			str++;
	}
	if (nbr_counter != 16)
		return (-1);
	return (1);
}
