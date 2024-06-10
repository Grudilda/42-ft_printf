/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-b <abonte-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:41:13 by grudi             #+#    #+#             */
/*   Updated: 2024/05/29 12:13:26 by abonte-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* this function is functionnal as a (virtual) part of 
the ft_printf function. It browses into format to either send
to dispatch function or print directly the character.
It moves in the string via an <index> from t_infos.
** INPUT **
va_list ap = structure which stores parameters 
const char *format = string with the directives (if any) for the 
		printing output
t_infos infos =	structure which has all useful informations
t_func *func_tab = array that store all the flags functions 
** OUTPUT **
[![VOID]!] */

static void	format_browsing(va_list ap, const char *format, t_infos *infos,
						t_func *func_tab)
{
	if (format[infos->index] == '%' && format[infos->index + 1] != '\0')
	{
		while (format[infos->index + 1] >= '0'
			&& format[infos->index + 1] <= '9')
			infos->index++;
		infos->type = format[infos->index + 1];
		general_dispatch(ap, infos, func_tab);
		infos->index++;
	}
	else
		ft_putchar(format[infos->index], infos);
}

/* this function is the main function of {libfprintf.a}
it checks if <format> exists, initialise the argument structure <ap>
and then launch the initialisation of the t_infos structure and of
the t_func array.
After all the initialisations, it send them to the format browsing
function.
In the it checks if everything was printed without any error (if any
return [-1]) and then return the number of charater which were printed.
** INPUT **
const char *format = string with the directives (if any) for the 
		printing output
** OUTPUT **
the number of characters which were printed. */

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_infos	infos;
	t_func	func_tab[TAB_SIZE];

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	init_struct(&infos);
	init_tab(func_tab);
	while (format[infos.index])
	{
		format_browsing(ap, format, &infos, func_tab);
		if (infos.write_error == TRUE)
			return (-1);
		infos.index++;
	}
	va_end(ap);
	return (infos.counter);
}
