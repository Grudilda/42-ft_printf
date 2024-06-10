/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_funct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-b <abonte-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:55:02 by grudi             #+#    #+#             */
/*   Updated: 2024/05/29 12:13:31 by abonte-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* Turn the integer received as argument into a string.
This function does not handle negatives. It only handles 
a decimal base.
** INPUT **
unsigned int n = integer to turn into a string
char *str = the string where the tranform integer will be saved
int i = index to move in the string 
** OUTPUT **
The function return the current index. */

int	ft_itoa(unsigned int num, char *str, int i)
{
	if (num >= 10)
		i = ft_itoa((num / 10), str, i);
	str[i] = num % 10 + 48;
	i++;
	str[i] = '\0';
	return (i);
}

/* Turn the integer received as argument into a string.
This function does not handle negatives. It only handles 
an hexadecimal base (lowercase).
** INPUT **
unsigned long n = integer to turn into a string
char *str = the string where the tranform integer will be saved
int i = index to move in the string 
** OUTPUT **
The function return the current index. */

int	ft_htoa_min(unsigned long num, char *str, int i)
{
	if (num >= 16)
		i = ft_htoa_min((num / 16), str, i);
	if ((num % 16) < 10)
		str[i] = num % 16 + 48;
	else
		str[i] = num % 16 + 87;
	i++;
	return (i);
}

/* Turn the integer received as argument into a string.
This function does not handle negatives. It only handles 
an hexadecimal base (uppercase).
** INPUT **
unsigned int n = integer to turn into a string
char *str = the string where the tranform integer will be saved
int i = index to move in the string 
** OUTPUT **
The function return the current index. */

int	ft_htoa_maj(unsigned int num, char *str, int i)
{
	if (num >= 16)
		i = ft_htoa_maj((num / 16), str, i);
	if ((num % 16) < 10)
		str[i] = num % 16 + 48;
	else
		str[i] = num % 16 + 55;
	i++;
	return (i);
}
