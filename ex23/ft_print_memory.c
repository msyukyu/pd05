/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:59:20 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/16 19:18:52 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static const char g_base_hexa[] = "0123456789abcdef";
static const size_t g_size_memory = sizeof(intptr_t);

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ft_print_char(char *addr, int i)
{
	int		pinned;

	pinned = -1;
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

char	*ft_print_line(char *addr)
{
	int	i;
	int pinned;

	i = 0;
	pinned = -1;
	while (i < 16)
	{
		pinned = ft_print_char(addr, i);
		i++;
	}
	return ((pinned != -1) ? addr + pinned : addr + i);
}

void	ft_print_addr(intptr_t addr, int count)
{
	if (addr < 16)
	{
		while (count++ < (int)(2 * g_size_memory) - 1)
			ft_putchar('0');
		ft_putchar(g_base_hexa[addr]);
		return ;
	}
	ft_print_addr(addr / 16, count + 1);
	ft_putchar(g_base_hexa[addr % 16]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	intptr_t	addr_int;
	char		*next_addr;
	int			i;
	int			line;

	next_addr = addr;
	line = 0;
	while (line < (int)((size / 16) + ((size % 16) != 0)))
	{
		addr_int = (intptr_t)next_addr;
		ft_print_addr(addr_int, 0);
		ft_putchar(':');
		ft_putchar(' ');
		ft_print_line(next_addr);
		ft_putchar(' ');
		i = 0;
		while (next_addr[i] && i < 16)
		{
			if (next_addr[i] < ' ' || next_addr[i] > '~')
				ft_putchar('.');
			else
				ft_putchar(next_addr[i]);
			i++;
		}
		line++;
		if (next_addr[i] == '\0')
		{
			ft_putchar('.');
			ft_putchar('\n');
			break ;
		}
		ft_putchar('\n');
		next_addr = next_addr + i;
	}
	return (addr);
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
		ft_print_memory(argv[1], atoi(argv[2]));
	ft_print_memory("\n\t\ftrlukjlk\n\\", 19);
	return (0);
}
