/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:51:20 by cmartino          #+#    #+#             */
/*   Updated: 2022/10/27 08:35:28 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_type(va_list ap, char c);
int		ft_base_hexa(unsigned int nb, char *base);
int		ft_putnbr_u_fd(unsigned int n, int fd, int cpt);
int		ft_print_ptr(unsigned long int ptr);
int		ft_put_un_nbr_fd(unsigned int n, int fd, int cpt);

#endif
