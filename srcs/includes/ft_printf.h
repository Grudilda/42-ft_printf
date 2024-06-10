/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-b <abonte-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:48:50 by grudi             #+#    #+#             */
/*   Updated: 2024/05/29 12:13:32 by abonte-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ************************************************************************** */
/*                                INCLUDES                                    */
/* ************************************************************************** */

/*********************/
/*     LIBRARIES     */
/*********************/
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/*********************/
/*      DEFINES      */
/*********************/
# define TRUE 1
# define FALSE 0
# define TAB_SIZE 10

/* ************************************************************************** */
/*                                TYPEDEF                                     */
/* ************************************************************************** */

/*********************/
/*     STRUCTURES    */
/*********************/
typedef struct s_infos
{
	char	type;
	int		index;
	int		counter;
	int		write_error;
}				t_infos;

typedef struct s_func
{
	void	(*f)(va_list, t_infos *);
	char	key;
}				t_func;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/*********************/
/* GENERAL FUNCTIONS */
/*********************/
int		ft_printf(const char *format, ...);
void	general_dispatch(va_list ap, t_infos *infos, t_func *func_tab);

/******************/
/* INIT FUNCTIONS */
/******************/
void	init_struct(t_infos *infos);
void	init_tab(t_func *func_tab);

/*************************/
/* 1ST CONVERS FUNCTIONS */
/*************************/
void	arg2str_int(int num, t_infos *infos);
void	arg2str_uint(unsigned int num, t_infos *infos);
void	arg2str_hexa(unsigned long num, t_infos *infos);

/************************/
/* CONVERSION FUNCTIONS */
/************************/
int		ft_itoa(unsigned int num, char *str, int i);
int		ft_htoa_min(unsigned long num, char *str, int i);
int		ft_htoa_maj(unsigned int num, char *str, int i);

/*******************/
/* PRINT FUNCTIONS */
/*******************/
void	ft_putchar(char c, t_infos *infos);
void	ft_putstr(char *str, t_infos *infos);

/******************/
/* FLAG FUNCTIONS */
/******************/
void	flag_percent(va_list ap, t_infos *infos);
void	flag_char(va_list ap, t_infos *infos);
void	flag_string(va_list ap, t_infos *infos);
void	flag_uint(va_list ap, t_infos *infos);
void	flag_int(va_list ap, t_infos *infos);
void	flag_hexa(va_list ap, t_infos *infos);

#endif