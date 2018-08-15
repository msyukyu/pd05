/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:28:58 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/15 20:18:06 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		pinned;

	i = 0;
	while (dest[i] != '\0')
		i++;
	pinned = i;
	i = 0;
	while (src[i] != '\0')
	{
		dest[pinned + i] = src[i];
		i++;
	}
	dest[pinned + i] = '\0';
	return (dest);
}
