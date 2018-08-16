/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:59:20 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/16 17:37:14 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static const char g_base_hexa[] = "0123456789abcdef";
static const size_t g_size_memory = sizeof(intptr_t);

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

char	*ft_print_line(char *addr)
{
	int	i;
	int pinned;

	i = 0;
	pinned = -1;
	while (i < 16)
	{
		if (addr[i] && pinned == -1)
		{
			ft_putchar(g_base_hexa[addr[i] / 16]);
			ft_putchar(g_base_hexa[addr[i] % 16]);
		}
		else
		{
			pinned = i;
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2 == 1)
			ft_putchar(' ');
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

	next_addr = addr;
	size = 0;
	addr_int = (intptr_t)addr;
	ft_print_addr(addr_int, 0);
	ft_putchar(':');
	ft_putchar(' ');
	ft_print_line(addr);
	ft_putchar(' ');
	i = 0;
	while (next_addr[i] && i < 16)
	{
		ft_putchar(next_addr[i]);
		i++;
	}
	return (addr);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		ft_print_memory(argv[1], 0);
	return (0);
}
