/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:03:35 by oel-mest          #+#    #+#             */
/*   Updated: 2024/11/06 17:03:35 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	print_type(va_list args, char type);
int	check_supported(char s);
int	check_valid(const char *str);
int	ft_printf(const char *str, ...);
int	print_p(void *ptr);
int	print_x(unsigned int d, char type);
int	print_u(unsigned int d);
int	print_d(int d);
int	print_s(char *str);
int	print_c(int c);
int	check_fails(int c);

#endif