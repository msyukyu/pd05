/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:11:10 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/18 17:30:34 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	noword;

	i = 0;
	noword = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z' && noword)
		{
			noword = 0;
			str[i] = str[i] + 'A' - 'a';
		}
		else if ((str[i] >= 'A' && str[i] <= 'Z' && noword) || (str[i] >= '0' &&
				str[i] <= '9'))
			noword = 0;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 'a' - 'A';
		else if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' &&
						str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
			noword = 1;
		i++;
	}
	return (str);
}
