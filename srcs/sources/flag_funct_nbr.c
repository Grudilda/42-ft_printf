/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_funct_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-b <abonte-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:13:35 by grudilda          #+#    #+#             */
/*   Updated: 2024/05/29 12:13:27 by abonte-b         ###   ########.fr       */
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

void	flag_uint(va_list ap, t_infos *infos)
{
	arg2str_uint(va_arg(ap, unsigned int), infos);
}

void	flag_int(va_list ap, t_infos *infos)
{
	arg2str_int(va_arg(ap, int), infos);
}

void	flag_hexa(va_list ap, t_infos *infos)
{
	arg2str_hexa(va_arg(ap, unsigned long), infos);
}
