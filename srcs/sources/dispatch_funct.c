/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-b <abonte-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:18:16 by grudilda          #+#    #+#             */
/*   Updated: 2024/05/29 12:13:29 by abonte-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* Dispatch each type into the right convert function via
an array of pointer to function.
It checks if the t_infos structure <type> match or not with
the t_func array <key>.
It moves in the array via an index.
** INPUT **
va_list ap = structure which stores parameters 
t_infos infos =	structure which has all useful informations
t_func *func_tab = array that store all the flags functions 
** OUTPUT**
[![VOID]!] */

void	general_dispatch(va_list ap, t_infos *infos, t_func *func_tab)
{
	int	index;

	index = 0;
	while (func_tab[index].key != -1)
	{
		if (func_tab[index].key == infos->type)
			func_tab[index].f(ap, infos);
		index++;
	}
}
