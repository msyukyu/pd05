/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:21:21 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/15 20:24:16 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		i;
	int		pinned;

	i = 0;
	while (dest[i] != '\0')
		i++;
	pinned = i;
	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		dest[pinned + i] = src[i];
		i++;
	}
	dest[pinned + i] = '\0';
	return (dest);
}
