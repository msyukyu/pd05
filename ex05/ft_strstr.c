/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:04:40 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/18 17:13:12 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;

	if (to_find[0] == '\0')
		return (str);
	while (*str != '\0')
	{
		while (*str != *to_find && *str != '\0')
			str++;
		if (*str == *to_find)
		{
			i = 0;
			while (str[i] != '\0' || (str[i] == '\0' && to_find[i] == '\0'))
			{
				if (to_find[i] == '\0')
					return (str);
				if (to_find[i] == str[i])
					i++;
				else
					break ;
			}
			str++;
		}
	}
	return ((void*)0);
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%s", ft_strstr(argv[1], argv[2]));
	}
	return (0);
}
