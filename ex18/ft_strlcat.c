/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:30:00 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/21 12:42:59 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	l;
	unsigned int	result;
	unsigned int	pinned;

	l = 0;
	while (dest[l] != '\0' && l < size)
		l++;
	pinned = l;
	result = l;
	if (result == size)
	{
		l = 0;
		while (src[l] != '\0')
			l++;
		return (result += l);
	}
	l = 0;
	while (src[l] != '\0')
	{
		if (pinned + l < size - 1)
			dest[pinned + l] = src[l];
		l++;
	}
	dest[pinned + l] = '\0';
	return (result + l);
}

int		main(void)
{
	char dest[] = "truuc\0a123456789";
	char src[] = "go";
	char dest2[] = "truuc\0a123456789";
	char src2[] = "go";

	printf("%d", ft_strlcat(dest, src, 0));
	printf("%lu", strlcat(dest2, src2, 0));
	printf("%s", dest);
	printf("%s", dest2);
	return (0);
}
