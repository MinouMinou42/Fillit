/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:16:22 by nolivier          #+#    #+#             */
/*   Updated: 2016/12/08 11:30:05 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

#define BUF_SIZE 1000

int				ft_usage(void)
{
	ft_putstr("usage: fillit input_file\n");
	return (0);
}

int				ft_error(void)
{
	ft_putstr("error\n");
	return (0);
}

int				main(int argc, char **argv)
{
	t_tetri			*data;
	int				fd;
	int				ret;
	char			buf[BUF_SIZE + 1];

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (ft_usage());
	if (fd == -1)
		return (ft_error());
	if ((ret = read(fd, buf, BUF_SIZE + 1)))
		buf[ret] = '\0';
	if (ft_strlen(buf) > 546)
		return (ft_error());
	if ((data = ft_purchase(buf)))
		ft_resolve(data);
	else
		return (ft_error());
	if (close(fd) == -1)
		return (ft_error());
	return (1);
}
