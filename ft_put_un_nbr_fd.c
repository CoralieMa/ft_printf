/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_un_nbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:08:14 by cmartino          #+#    #+#             */
/*   Updated: 2022/10/27 08:35:50 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_un_nbr_fd(unsigned int n, int fd, int cpt)
{
	char	c;

	if (n >= 10)
	{
		cpt += ft_put_un_nbr_fd(n / 10, fd, cpt);
	}
	c = n % 10 + '0';
	write(fd, &c, 1);
	cpt++;
	return (cpt);
}
