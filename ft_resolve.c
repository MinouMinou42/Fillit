/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:30:51 by nolivier          #+#    #+#             */
/*   Updated: 2016/12/08 10:58:48 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			ft_count_tetri(t_tetri *data)
{
	int			i;

	i = 0;
	while (data)
	{
		i++;
		data = data->next;
	}
	return (i);
}

void		ft_set_result(char *result, int side)
{
	int			i;
	int			j;

	i = 0;
	while (i < side * (side + 1))
	{
		j = 0;
		while (j < side)
		{
			result[i + j] = '.';
			j++;
		}
		result[i + j] = '\n';
		i += j + 1;
	}
	result[i] = '\0';
}

void		ft_resolve(t_tetri *data)
{
	char		*result;
	int			area;
	int			side;

	area = 4 * ft_count_tetri(data);
	side = 2;
	while (area > side * side)
		side++;
	result = (char*)malloc(sizeof(char) * (side * (side + 1) + 1));
	ft_set_result(result, side);
	while (!ft_place_tetri(data, result, side))
	{
		free(result);
		side++;
		result = (char*)malloc(sizeof(char) * (side * (side + 1) + 1));
		ft_set_result(result, side);
	}
	ft_putstr(result);
	ft_lstdel_tetri(data);
	free(result);
}
