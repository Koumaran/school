#include "libft.h"

int		main(void)
{
	char *line = NULL;

	while (get_next_line(0, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
	return (0);
}
