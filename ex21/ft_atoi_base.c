/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:09:54 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/20 18:38:01 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_check_sign(char *str, int *sign)
{
	int	var_i;

	var_i = 0;
	while (str[var_i] == ' ' || str[var_i] == '\t' || str[var_i] == '\n' ||
			str[var_i] == '\r' || str[var_i] == '\v' || str[var_i] == '\f')
		var_i++;
	if (str[var_i] == '+')
		var_i++;
	else if (str[var_i] == '-')
	{
		var_i++;
		*sign = -1;
	}
	return (var_i);
}

int		ft_atoi_base(char *str, char *base)
{
	int		result;
	int		sign;
	int		var_i;
	int		size;
	int		base_value;

	size = ft_check_base(base);
	if (size < 2)
		return (0);
	result = 0;
	sign = 1;
	var_i = ft_check_sign(str, &sign);
	base_value = ft_search_base(str[var_i], base);
	while (base_value != -1)
	{
		result = result * size + sign * (base_value);
		base_value = ft_search_base(str[++var_i], base);
	}
	return ((base_value == -1 && !(str[var_i] == '\0') && str[var_i] != '-' &&
				str[var_i] != '+') ? 0 : result);
}
