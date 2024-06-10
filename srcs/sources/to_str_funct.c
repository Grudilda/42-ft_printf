/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_str_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-b <abonte-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:13:51 by grudi             #+#    #+#             */
/*   Updated: 2024/05/29 12:13:22 by abonte-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* Send the number to __ft_itoa__ to convert it in (char *) and
then send the string to __ft_putstr__ to print it.
** INPUT **
unsigned int num = integer to turn into a string
t_infos infos =	structure which has all useful informations
** OUTPUT **
[![VOID]!] */

void	arg2str_uint(unsigned int num, t_infos *infos)
{
	char	str2print[11];
	int		i;

	i = 0;
	i = ft_itoa(num, str2print, i);
	ft_putstr(str2print, infos);
}
/* the function first handles the negative, if needed .Then send
the number to __ft_itoa__ to convert it in (char *) and
then send the string to __ft_putstr__ to print it.
** INPUT **
int num = integer to turn into a string
t_infos infos =	structure which has all useful informations
** OUTPUT **
[![VOID]!] */

void	arg2str_int(int num, t_infos *infos)
{
	char	str2print[11];
	int		i;

	i = 0;
	if (num < 0)
	{
		ft_putchar('-', infos);
		num *= -1;
	}
	i = ft_itoa((unsigned int)num, str2print, i);
	ft_putstr(str2print, infos);
}

/* put the prefixe of an address (when printing it).
** INPUT **
char *str = the string in which we save the
		printable version of the number
** OUTPUT **
[![VOID]!] */

static void	init_str_point(char *str)
{
	str[0] = '0';
	str[1] = 'x';
	str[2] = '\0';
}

/* The function first handles  all the special cases
and then send the number to __ft_htoa_(min/maj)__ 
to convert it in (char *) and then send the string
to __ft_putstr__ to print it.
** INPUT **
unsigned int num = integer to turn into a string
t_infos infos =	structure which has all useful informations
** OUTPUT **
[![VOID]!] */

void	arg2str_hexa(unsigned long num, t_infos *infos)
{
	int		i;
	char	str[18];
	char	*nil_point;

	i = 0;
	nil_point = "(nil)";
	if (infos->type == 'p' && num != 0)
	{
		init_str_point(str);
		i = 2;
		i = ft_htoa_min(num, str, i);
	}
	else if (infos->type == 'x')
		i = ft_htoa_min((unsigned int)num, str, i);
	else if (infos->type == 'X')
		i = ft_htoa_maj((unsigned int)num, str, i);
	str[i] = '\0';
	if (infos->type == 'p' && num == '\0')
		ft_putstr(nil_point, infos);
	else
		ft_putstr(str, infos);
}
