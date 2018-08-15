#include <stdio.h>

char	*ft_strcpy(char *dest, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

int		main(int argc, char *argv[])
{
	char	dest[8];
	char	str[8];
	if (argc == 2)
	{
		ft_strcpy(str,  argv[1]);
		printf("%s", ft_strcpy(dest, str));
	}
	return (0);
}
