/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:49:38 by cmartino          #+#    #+#             */
/*   Updated: 2022/10/27 08:35:04 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(ap, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 1));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(ap, unsigned long int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), 1, 0));
	else if (c == 'u')
		return (ft_put_un_nbr_fd(va_arg(ap, unsigned int), 1, 0));
	else if (c == 'x')
		return (ft_base_hexa(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_base_hexa(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (-1);
}
