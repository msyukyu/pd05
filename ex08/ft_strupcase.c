/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:39:12 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/15 17:02:41 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] + 'A' - 'a';
	return (str);
}
