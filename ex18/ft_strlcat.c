/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:30:00 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/15 21:35:43 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	l;
	unsigned int	pinned;

	l = 0;
	while (dest[l] != '\0' && l < size - 1)
		l++;
	pinned = l;
	l = 0;
	while (src[l] != '\0' && l + pinned < size)
	{
		dest[pinned + l] = src[l];
		l++;
	}
	if (l + pinned < size)
		dest[pinned + l] = '\0';
	return (l + pinned + 1);
}
