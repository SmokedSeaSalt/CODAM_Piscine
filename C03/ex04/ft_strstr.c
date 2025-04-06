/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:53:40 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/02/27 15:40:11 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_to_findcmp(char *offsetstr, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i] != '\0')
	{
		if (offsetstr[i] != to_find[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	str_index;

	str_index = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[str_index] != '\0')
	{
		if (str[str_index] == to_find[0])
		{
			if (ft_to_findcmp(&str[str_index], to_find) == 0)
			{
				return (&str[str_index]);
			}
		}
		str_index++;
	}
	return (0);
}
