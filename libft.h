/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:20:51 by nolivier          #+#    #+#             */
/*   Updated: 2016/12/07 15:09:53 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

struct	s_tetri
{
	char			num;
	int				width;
	int				tab[4];
	struct s_tetri	*next;
};

typedef struct s_tetri	t_tetri;
t_tetri	*ft_purchase(char *buf);
t_tetri *ft_compare(char *buf);
void	ft_resolve(t_tetri *data);
int		ft_place_tetri(t_tetri *data, char *result, int side);
void	ft_lstdel_tetri(t_tetri *data);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
size_t	ft_strlen(const char *s);

#endif
