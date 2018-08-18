/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:59:20 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/18 13:41:10 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static const char g_base_hexa[] = "0123456789abcdef";

int		ft_putchar(char c);

int		ft_print_char(char *addr, int i, int pinned)
{
	if (addr[i] && pinned == -1)
	{
		ft_putchar(g_base_hexa[addr[i] / 16]);
		ft_putchar(g_base_hexa[addr[i] % 16]);
	}
	else
	{
		if (pinned == -1)
		{
			ft_putchar('0');
			ft_putchar('0');
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		pinned = i;
	}
	if (i % 2 == 1)
		ft_putchar(' ');
	return (pinned);
}

char	*ft_print_line(char *addr, unsigned int total, unsigned int size)
{
	int	i;
	int pinned;

	i = 0;
	pinned = -1;
	while (i < 16)
	{
		if (total < size)
			pinned = ft_print_char(addr, i, -1);
		else
			pinned = ft_print_char(addr, i, 0);
		i++;
		total++;
	}
	return ((pinned != -1) ? addr + pinned : addr + i);
}

void	ft_print_addr(int addr, int count)
{
	if (addr < 16)
	{
		while (count++ < (int)(sizeof(char*)) - 1)
			ft_putchar('0');
		ft_putchar(g_base_hexa[addr]);
		return ;
	}
	ft_print_addr(addr / 16, count + 1);
	ft_putchar(g_base_hexa[addr % 16]);
}

char	*ft_print_content(char *next_addr, int *line, unsigned int *total,
		unsigned int size)
{
	int i;

	i = 0;
	while (i < 16 && *total < size)
	{
		if (next_addr[i] < ' ' || next_addr[i] > '~')
			ft_putchar('.');
		else
			ft_putchar(next_addr[i]);
		i++;
		*total += 1;
	}
	*line += 1;
	ft_putchar('\n');
	next_addr = next_addr + i;
	return (next_addr);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				addr_int;
	char			*next_addr;
	int				line;
	unsigned int	total;

	next_addr = addr;
	line = 0;
	total = 0;
	while (line < (int)((size / 16) + ((size % 16) != 0)))
	{
		addr_int = (int)next_addr;
		ft_print_addr((int)(next_addr), 0);
		ft_putchar(':');
		ft_putchar(' ');
		ft_print_line(next_addr, total, size);
		ft_putchar(' ');
		next_addr = ft_print_content(next_addr, &line, &total, size);
	}
	return (addr);
}
