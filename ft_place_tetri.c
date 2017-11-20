/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:19:17 by nolivier          #+#    #+#             */
/*   Updated: 2016/12/08 11:12:35 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_clear_result(char *result, char del)
{
	int			i;

	i = 0;
	while (result[i])
	{
		if (result[i] >= del && result[i] <= 'Z')
			result[i] = '.';
		i++;
	}
}

int			ft_put_tetri(t_tetri *data, char *result, int side, int i)
{
	int			j;

	j = 0;
	while (j < 4)
	{
		if (result[i + (data->tab[j] / data->width) * (side + 1)
				+ data->tab[j] % data->width] != '.')
			return (0);
		j++;
	}
	j = 0;
	while (j < 4)
	{
		result[i + (data->tab[j] / data->width) * (side + 1)
			+ data->tab[j] % data->width] = data->num;
		j++;
	}
	return (1);
}

int			ft_place_tetri(t_tetri *data, char *result, int side)
{
	int			i;

	i = 0;
	while (result[i] && i < (side * (side + 1)
				- (data->tab[3] / data->width) * (side + 1) - data->width))
	{
		if (ft_put_tetri(data, result, side, i))
		{
			if (data->next == NULL)
				return (1);
			if (ft_place_tetri(data->next, result, side) == 0)
				ft_clear_result(result, data->num);
			else
				return (1);
		}
		i++;
	}
	return (0);
}
