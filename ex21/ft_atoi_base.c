/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:09:54 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/18 19:13:07 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RESULT var[0]
#define SIGN var[1]
#define VAR_I var[2]
#define SIZE var[3]
#define BASE_VALUE var[4]

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < ' ' || base[i] > '~')
			return (0);
		j = -1;
		while (++j < i)
			if (base[i] == base[j])
				return (0);
		i++;
	}
	return ((i < 2) ? 0 : i);
}

int		ft_search_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		var[5];

	SIZE = ft_check_base(base);
	if (SIZE < 2)
		return (0);
	RESULT = 0;
	VAR_I = 0;
	SIGN = 1;
	while (str[VAR_I] == ' ' || str[VAR_I] == '\t' || str[VAR_I] == '\n' ||
			str[VAR_I] == '\r' || str[VAR_I] == '\v' || str[VAR_I] == '\f')
		VAR_I++;
	if (str[VAR_I] == '+')
		VAR_I++;
	else if (str[VAR_I] == '-')
	{
		VAR_I++;
		SIGN = -1;
	}
	BASE_VALUE = ft_search_base(str[VAR_I], base);
	while (BASE_VALUE != -1)
	{
		RESULT = RESULT * SIZE + SIGN * (BASE_VALUE);
		BASE_VALUE = ft_search_base(str[++VAR_I], base);
	}
	return ((BASE_VALUE == -1 && !(str[VAR_I] == '\0')) ? 0 : RESULT);
}
