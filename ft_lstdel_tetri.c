/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:49:52 by nolivier          #+#    #+#             */
/*   Updated: 2016/12/08 11:01:42 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void		ft_lstdel_tetri(t_tetri *data)
{
	t_tetri		*tmp;
	t_tetri		*next;

	if (data)
	{
		tmp = data;
		while (tmp)
		{
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
	}
}
