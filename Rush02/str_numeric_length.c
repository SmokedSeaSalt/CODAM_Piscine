/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_numeric_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:42:56 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/09 14:56:03 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// function to return the start of the digits
// CAN start with whitespace
// adds '\0' after last digit
char	*str_numeric_length(char *str)
{
	int	i;
	int	ret_index;

	ret_index = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
		i++;
	}
	ret_index = i;
	if (str[i] < '0' || str[i] > '9')
		str[i] = '\0';
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] < '0' || str[i] > '9')
			str[i] = '\0';
	}
	return (&str[ret_index]);
}
