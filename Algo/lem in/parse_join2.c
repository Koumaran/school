#include "lemin.h"

char	**check_line(t_lem *lem, char *line, int len)
{
	char	*str;
	int	i;
	int	j;
	t_room	*r1;
	t_room	*r2;

	i = -1;
	j = 0;
	r1 = NULL;
	r2 = NULL;
	while (++i < len)
	{
		if (line[i] == '-' || i + 1 == len)
		{
			i = (i + 1 == len) ? len : i;
			str = ft_strsub(line, j, i - j);
			if (str)
			{
				if (!r1)
				{
					r1 = check_room_name(lem, str);
					j = (r1) ? i + 1 : 0;
				}
				else
				{
					if (!(r2 = check_room_name(lem, str)) && i == len)
					{
						i = ft_strlen(r1->name);
						r1 = NULL;
						j = 0;
					}
				}
			}
			ft_strdel(&str);
		}
	}
	if (r1 && r2)
	{
		line[j - 1] = '+';
		return (ft_strsplit(line, '+'));
	}
	return (NULL);
}
