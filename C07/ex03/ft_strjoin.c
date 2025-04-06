/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:17:48 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/05 13:12:09 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_str_len(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

void	ft_append_sep(int *ret_index, char *ret, char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		ret[*ret_index] = sep[i];
		i++;
		(*ret_index)++;
	}
}

void	ft_fill_ret(int size, char **strs, char *sep, char *ret)
{
	int	ret_index;
	int	size_index;
	int	i;

	ret_index = 0;
	size_index = 0;
	i = 0;
	while (size_index < size)
	{
		while (strs[size_index][i] != '\0')
		{
			ret[ret_index] = strs[size_index][i];
			i++;
			ret_index++;
		}
		i = 0;
		if (size_index != (size - 1))
			ft_append_sep(&ret_index, ret, sep);
		size_index++;
	}
	ret[ret_index] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		sep_size;
	int		strs_size;
	int		i;

	i = 0;
	strs_size = 0;
	while (i < size)
	{
		strs_size += ft_str_len(strs[i]);
		i++;
	}
	sep_size = ft_str_len(sep);
	ret = malloc(strs_size + (sep_size * (size - 1)) + 1);
	if (ret == ((void *)0))
		return (0);
	ft_fill_ret(size, strs, sep, ret);
	if (size <= 0)
	{
		ret = malloc(1 * sizeof(char));
		ret[0] = '\0';
		return (ret);
	}
	return (ret);
}
