/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 22:01:07 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/15 22:01:09 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < ' ' || base[i] > '~')
			return (0);
		j = -1;
		while (++j < i)
			if (base[i] == base[j])
				return (0);
		i++;
	}
	return ((i < 2) ? 0 : i);
}

void	ft_recursive_print_digit(int nbr, char *base, int size)
{
	int	sign;

	sign = 1;
	if (nbr < 0)
		sign = -1;
	if (nbr < size && nbr > -size)
	{
		if (sign == -1)
			ft_putchar('-');
	}
	else
		ft_recursive_print_digit(nbr / size, base, size);
	ft_putchar(base[(nbr % size) * sign]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	size = ft_check_base(base);
	if (size == 0)
		return ;
	ft_recursive_print_digit(nbr, base, size);
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
		ft_putnbr_base(atoi(argv[1]), argv[2]);
	return (0);
}
