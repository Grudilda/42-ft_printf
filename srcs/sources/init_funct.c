/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-b <abonte-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:58:44 by grudilda          #+#    #+#             */
/*   Updated: 2024/05/29 12:13:24 by abonte-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* Initialise the values for each one of the <element> of the 
t_infos structure.
** INPUT **
t_infos infos =	structure which has all useful informations
** OUTPUT **
[![VOID]!] */

void	init_struct(t_infos *infos)
{
	infos->type = 0;
	infos->index = 0;
	infos->counter = 0;
	infos->write_error = FALSE;
}

/* Initialise the values for each one of the [element] of the 
t_func array.
** INPUT **
t_func *func_tab = array that store all the flags functions 
		(empty at the start of this function)
** OUTPUT **
[![VOID]!] */

void	init_tab(t_func *func_tab)
{
	func_tab[0] = (t_func){&flag_percent, '%'};
	func_tab[1] = (t_func){&flag_char, 'c'};
	func_tab[2] = (t_func){&flag_string, 's'};
	func_tab[3] = (t_func){&flag_uint, 'u'};
	func_tab[4] = (t_func){&flag_int, 'i'};
	func_tab[5] = (t_func){&flag_int, 'd'};
	func_tab[6] = (t_func){&flag_hexa, 'x'};
	func_tab[7] = (t_func){&flag_hexa, 'X'};
	func_tab[8] = (t_func){&flag_hexa, 'p'};
	func_tab[9] = (t_func){NULL, -1};
}
