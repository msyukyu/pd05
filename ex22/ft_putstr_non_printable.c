/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:13:52 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/16 11:14:44 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static const char c_base_hexa = "0123456789abcdef";

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_print_hexa(char c)
{
	char	hexa[17];
	int		i;

	i = 0;
	while (i < 10)
	{
		
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			ft_putchar('\\');
			ft_print_hexa(str[i]);
