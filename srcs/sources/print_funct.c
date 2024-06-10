/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-b <abonte-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:10:02 by grudi             #+#    #+#             */
/*   Updated: 2024/05/29 12:13:23 by abonte-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*writes the character <c> and check if write return or not 
an error.
** INPUT **
char c = the charater to print
t_infos infos =	structure which has all useful informations
** OUTPUT **
[![VOID]!] */

void	ft_putchar(char c, t_infos *infos)
{
	int	ret_val;

	ret_val = 0;
	ret_val = write(1, &c, 1);
	if (ret_val == -1)
	{
		infos->write_error = TRUE;
		return ;
	}
	else
		infos->counter += ret_val;
}

/* send the character to print to __ft_putchar__ and check 
if write returned or not an error, if not it continues to
browse the string ; otherwise it stops and return.
It moves in the string via an index.
** INPUT **
char *str = the string to print
t_infos infos =	structure which has all useful informations
** OUTPUT **
[![VOID]!] */

void	ft_putstr(char *str, t_infos *infos)
{
	int	index;

	index = 0;
	if (str == NULL)
		str = "(null)";
	while (str[index])
	{
		ft_putchar(str[index], infos);
		if (infos->write_error == TRUE)
			return ;
		index++;
	}
}
