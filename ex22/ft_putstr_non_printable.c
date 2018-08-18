/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:54:02 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/18 19:29:42 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const char g_base_hexa[] = "0123456789abcdef";

int		ft_putchar(char c);

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			ft_putchar('\\');
			ft_putchar(g_base_hexa[str[i] / 16]);
			ft_putchar(g_base_hexa[str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
