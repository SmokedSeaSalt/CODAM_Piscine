/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:24:35 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/02/25 13:35:49 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //to use printf

char	*ft_strcat(char *dest, char *src)
{
	int		dest_index;
	int		src_index;

	dest_index = 0;
	src_index = 0;
	while (dest[dest_index] != '\0')
	{
		dest_index++;
	}
	while (src[src_index] != '\0')
	{
		dest[dest_index] = src[src_index];
		dest_index++;
		src_index++;
	}
	dest[dest_index] = '\0';
	return (dest);
}
