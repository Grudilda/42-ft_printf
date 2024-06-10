/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_funct_ascii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-b <abonte-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:06:41 by grudilda          #+#    #+#             */
/*   Updated: 2024/05/29 12:13:28 by abonte-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* these functions are all using the same template. They
just pass the right argument with the right type to the 
right function.
** INPUT **
va_list ap = structure which stores parameters 
t_infos infos =	structure which has all useful informations
** OUTPUT **
[![VOID]!] */

void	flag_percent(va_list ap, t_infos *infos)
{
	(void)ap;
	ft_putchar('%', infos);
}

void	flag_char(va_list ap, t_infos *infos)
{
	ft_putchar(va_arg(ap, int), infos);
}

void	flag_string(va_list ap, t_infos *infos)
{
	ft_putstr(va_arg(ap, char *), infos);
}
