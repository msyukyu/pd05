/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:24:21 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/15 15:24:23 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int cmp;

	i = 0;
	cmp = 0;
	while (*(s1 + i) != '\0' && *(s2 + i) != '\0' && cmp == 0)
	{
		cmp = *(s1 + i) - *(s2 + i);
		i++;
	}
	if (cmp == 0)
	{
		if (*(s1 + i) == '\0' && *(s2 + i) != '\0')
		{
			cmp = -1;
		}
		else if (*(s2 + i) == '\0' && *(s1 + i) != '\0')
		{
			cmp = 1;
		}
	}
	return (cmp);
}
