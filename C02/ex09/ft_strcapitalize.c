/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:07:08 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/02/23 10:21:26 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_checkcapitalize(char *str, int i)
{
	if (!((str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			|| (str[i - 1] >= 'a' && str[i - 1] <= 'z')
			|| (str[i - 1] >= '0' && str[i - 1] <= '9'))
		&& (str[i] >= 'a' && str[i] <= 'z'))
	{
		str[i] = str[i] - 32;
	}
}

void	ft_checkdecapitalize(char *str, int i)
{
	if (((str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			|| (str[i - 1] >= 'a' && str[i - 1] <= 'z')
			|| (str[i - 1] >= '0' && str[i - 1] <= '9'))
		&& (str[i] >= 'A' && str[i] <= 'Z'))
	{
		str[i] = str[i] + 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if ((str[i] >= 'a' && str[i] <= 'z'))
	{
		str[i] = str[i] - 32;
	}
	i++;
	while (str[i] != '\0')
	{
		ft_checkcapitalize(str, i);
		ft_checkdecapitalize(str, i);
		i++;
	}
	return (str);
}
