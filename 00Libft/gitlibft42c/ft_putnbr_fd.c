/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:00:21 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/21 15:02:13 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			num = '-';
			n = -n;
			write(fd, &num, 1);
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		num = '0' + n % 10;
		write(fd, &num, 1);
	}
}

/*int main(void)
{
	int fd;

	fd = open("myfile.txt", O_WRONLY);
	ft_putnbr_fd(1996, fd);
	return 0;
}*/