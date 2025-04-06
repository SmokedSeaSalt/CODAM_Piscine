/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:43:41 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/02/25 17:50:38 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_getstrsize(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_index;
	unsigned int	src_index;
	unsigned int	total_len;

	dest_index = 0;
	src_index = 0;
	total_len = ft_getstrsize(dest) + ft_getstrsize(src);
	while (dest[dest_index] != '\0' && dest_index < size)
	{
		dest_index++;
	}
	if (dest_index == size)
	{
		return (size + ft_getstrsize(src));
	}
	while (src[src_index] != '\0' && dest_index < size - 1)
	{
		dest[dest_index] = src[src_index];
		dest_index++;
		src_index++;
	}
	dest[dest_index] = '\0';
	return (total_len);
}
