/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:41:26 by cmartino          #+#    #+#             */
/*   Updated: 2022/10/26 14:11:37 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		a;

	va_start (ap, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			a = ft_type(ap, *str);
			if (a < 0)
				return (-1);
			len += a;
		}
		else
		{
			write(1, str, 1);
			len++;
		}
		str++;
	}
	va_end (ap);
	return (len);
}
