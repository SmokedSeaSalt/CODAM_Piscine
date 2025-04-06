/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_grab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbakker <dbakker@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:34:01 by mvan-rij          #+#    #+#             */
/*   Updated: 2025/03/02 16:41:01 by dbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_unique_row(int grab[24][4], int row_nbr)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (grab[row_nbr][i] == grab[row_nbr][j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_fill_grab(int grab[24][4], int nbr, int i)
{
	grab[i][3] = ((nbr % 4) + 1);
	nbr /= 4;
	grab[i][2] = ((nbr % 4) + 1);
	nbr /= 4;
	grab[i][1] = ((nbr % 4) + 1);
	nbr /= 4;
	grab[i][0] = ((nbr) + 1);
}

void	ft_generate_grab(int grab[24][4])
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (i < 24)
	{
		nbr++;
		ft_fill_grab(grab, nbr, i);
		while (ft_check_unique_row(grab, i) != 1)
		{
			nbr++;
			ft_fill_grab(grab, nbr, i);
		}
		i++;
	}
}
