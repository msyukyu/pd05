/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:37:06 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/15 21:54:29 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (dest[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
		if (src[i - 1] == '\0')
			return (i);
	}
	dest[i] = '\0';
	return (i + 1);
}
