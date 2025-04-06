/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-rij <mvan-rij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:11:35 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/02/20 15:41:48 by mvan-rij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	x;

	x = *a;
	*a = *b;
	*b = x;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = size - 1;
	j = i;
	while (j > 0)
	{
		while (i > 0)
		{
			if ((tab[i - 1] > tab[i]) && (i >= 1))
			{
				ft_swap(&tab[i], &tab[i - 1]);
			}
			i--;
		}
		j--;
		i = size - 1;
	}
}
