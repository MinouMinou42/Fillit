/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:30:15 by nolivier          #+#    #+#             */
/*   Updated: 2016/12/06 11:45:23 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			ft_links(char *buf, int i)
{
	int				links;

	links = 0;
	if (i >= 1 && buf[i - 1] == '#')
		links++;
	if (i <= 18 && buf[i + 1] == '#')
		links++;
	if (i >= 5 && buf[i - 5] == '#')
		links++;
	if (i <= 13 && buf[i + 5] == '#')
		links++;
	return (links);
}

int			ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int			ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_tetri		*ft_set_tetri(t_tetri *elem)
{
	int		start;
	int		min;
	int		max;
	int		i;

	min = ft_min(ft_min(elem->tab[0] % 5, elem->tab[1] % 5),
			ft_min(elem->tab[2] % 5, elem->tab[3] % 5));
	max = ft_max(ft_max(elem->tab[0] % 5, elem->tab[1] % 5),
			ft_max(elem->tab[2] % 5, elem->tab[3] % 5));
	start = (elem->tab[0] / 5) * 5 + min;
	elem->width = max - min + 1;
	i = 0;
	while (i < 4)
	{
		elem->tab[i] = (elem->tab[i] - start) % 5 +
			(elem->tab[i] - start) / 5 * elem->width;
		i++;
	}
	return (elem);
}

t_tetri		*ft_compare(char *buf)
{
	t_tetri			*elem;
	int				i;
	int				j;
	int				links;

	links = 0;
	if (!(elem = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	j = 0;
	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			links += ft_links(buf, i);
			elem->tab[j] = i;
			j++;
		}
		i++;
	}
	if (links >= 6)
		return (ft_set_tetri(elem));
	return (NULL);
}
