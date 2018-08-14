/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 08:19:02 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/14 17:22:19 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_atoi(char *str)
{
	int		result;
	int		sign;
	int		i;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + sign * (str[i] - '0');
		i++;
	}
	return (result);
}

int		main(int argc, char *argv[])
{
	int c;

	if (argc == 2)
	{
		c = atoi(argv[1]);
		printf("%d\n", c);
		c = ft_atoi(argv[1]);
		printf("%d\n", c);
	}
	return (0);
}
