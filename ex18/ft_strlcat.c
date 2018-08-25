/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:30:00 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/25 10:08:46 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (result + l);
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
