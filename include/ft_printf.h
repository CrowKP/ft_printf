/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:56:31 by aigarcia          #+#    #+#             */
/*   Updated: 2022/08/18 15:56:33 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_putchar(int c);
int		ft_printstr(char *str);
int		ft_printptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_printnosign(unsigned int n);
int		ft_print_hex(unsigned int num, const char format);
void	ft_putstr(char *str);
void	ft_putptr(uintptr_t ptr);
int		ft_ptrlen(uintptr_t it);
char	*ft_nositoa(unsigned int n);
int		ft_numlen(unsigned int num);
void	ft_put_hex(unsigned int num, const char format);
int		ft_hexlen(unsigned int num);

#endif
