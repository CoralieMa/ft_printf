/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:25:42 by cmartino          #+#    #+#             */
/*   Updated: 2022/10/26 16:09:59 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd, int cpt)
{
	char	c;
	int		neg;

	neg = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		neg = 1;
	}
	if (n >= 10)
	{
		cpt += ft_putnbr_fd(n / 10, fd, cpt);
	}
	c = n % 10 + '0';
	write(fd, &c, 1);
	cpt++;
	return (cpt + neg);
}
