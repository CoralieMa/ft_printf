/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:51:47 by cmartino          #+#    #+#             */
/*   Updated: 2022/10/26 14:08:13 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_size_tab(unsigned long int nb)
{
	int	len;

	len = 0;
	while (nb >= 1)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

static char	*ft_fill_tab(char *tab, char *base, unsigned long int nb, int len)
{
	if (nb == 0)
	{
		tab[0] = '0';
		len++;
	}
	tab[len] = '\0';
	len--;
	while (nb >= 1)
	{
		tab[len] = base[nb % 16];
		nb = nb / 16;
		len--;
	}
	return (tab);
}

static int	ft_convert_base_hexa2(unsigned long int nb, char *base)
{
	char	*tab;
	int		len;

	len = ft_size_tab(nb);
	tab = malloc(sizeof(tab) * (len + 1));
	if (!tab)
		return (0);
	ft_fill_tab(tab, base, nb, len);
	len = ft_putstr_fd(tab, 1);
	free(tab);
	return (len);
}

int	ft_print_ptr(unsigned long int ptr)
{
	int	len;

	ft_putstr_fd("0x", 1);
	len = ft_convert_base_hexa2(ptr, "0123456789abcdef");
	return (len + 2);
}
