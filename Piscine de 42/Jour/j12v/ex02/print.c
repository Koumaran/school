#include "libft.h"

void	ft_putstr(char *str, char *name_file, int	error)
{
	if (error == 2)
	{
		write (2, "cat: ", 5);
		if (name_file)
		{
			write (2, name_file, ft_strlen(name_file));
			write (2, ": ", 2);
		}
		write (2, str, ft_strlen(str));
	}
	if (error == 1)
		write (1, str, ft_strlen(str));
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdump(char *str)
{
	int		i;
	char	*dest;

	i = -1;
	dest = (char*)malloc((sizeof(char) + 1) * ft_strlen(str));
	while (str[++i])
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}
