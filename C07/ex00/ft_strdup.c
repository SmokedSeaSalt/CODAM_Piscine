/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:17:37 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/05 10:04:56 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		str_size;
	char	*ret;

	str_size = 0;
	while (src[str_size] != '\0')
	{
		str_size++;
	}
	ret = malloc((str_size + 1) * sizeof(char));
	if (ret == (void *)0)
		return (0);
	str_size = 0;
	while (src[str_size] != '\0')
	{
		ret[str_size] = src[str_size];
		str_size++;
	}
	ret[str_size + 1] = '\0';
	return (ret);
}
