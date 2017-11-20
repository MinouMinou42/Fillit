/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_purchase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:42:22 by nolivier          #+#    #+#             */
/*   Updated: 2016/12/08 10:55:39 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_verif_tetri(char *buf, int *i, int *count)
{
	int				j;
	int				k;

	k = 0;
	while (k < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (buf[*i + j] != '.' && buf[*i + j] != '#')
				return (0);
			if (buf[*i + j] == '#')
				*count = *count + 1;
			j++;
		}
		if (buf[*i + j] == '\n')
			j++;
		else
			return (0);
		*i += j;
		k++;
	}
	return (1);
}

int				ft_verif(char *buf)
{
	int				i;
	int				count;

	count = 0;
	i = 0;
	while (buf[i])
	{
		if (!(ft_verif_tetri(buf, &i, &count)))
			return (0);
		if (buf[i] == '\n' && buf[i + 1] != '\0' && count == 4)
		{
			count = 0;
			i++;
		}
		else
			return ((buf[i] == '\0' && count == 4) ? 1 : 0);
	}
	return (1);
}

t_tetri			*ft_purchase(char *buf)
{
	t_tetri			*first;
	t_tetri			*data;
	int				i;

	if (!(ft_verif(buf)))
		return (NULL);
	if (!(first = ft_compare(buf)))
		return (NULL);
	data = first;
	data->num = 'A';
	i = 21;
	while (buf[i])
	{
		if (!(data->next = ft_compare(buf + i)))
		{
			ft_lstdel_tetri(first);
			return (NULL);
		}
		data->next->num = data->num + 1;
		data = data->next;
		i += 21;
	}
	data->next = NULL;
	return (first);
}
