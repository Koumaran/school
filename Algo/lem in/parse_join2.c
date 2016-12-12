#include "lemin.h"

char	**check_line(t_lem *lem, char *line)
{
	char	*str;
	char	*tmp;
	int	i;
	int	j;
	t_room	*r1;
	t_room	*r2;

	i = -1;
	j = 0;
	tmp = NULL;
	r1 = NULL;
	r2 = NULL;
	while (line[++i])
	{
		if (line[i] == '-' || !line[i + 1])
		{

			str = ft_strsub(line, j, i - j);
			if (tmp && ft_strcmp(str, tmp) == 0)
			{
				dprintf(1, "tmp=%s\n", tmp);
				ft_strdel(&str);
				ft_strdel(&tmp);
			}
			dprintf(1, "str=%s i=%d, j=%d\n", str, i, j);
			if (str)
			{	
				if (!r1)
				{
					r1 = check_room_name(lem, str);
					j = (r1) ? i + 1 : 0;
					dprintf(1, "name r1==>%s\n", r1->name);
				}
				else
				{
					if (!(r2 = check_room_name(lem, str)) && !line[i + 1])
					{
						r1 = NULL;
						j = 0;
						i = (i == ft_strlen(line) -1) ? -1 : i;
						tmp = ft_strdup(r1->name);
						dprintf(1, "end i=%d, tmp=%s\n", i, tmp);
					}
				}
			}
			ft_strdel(&str);
		}
	}
	if (r1 && r2)
	{
		line[j] = '+';
		return (ft_strsplit(line, '+'));
	}
	return (NULL);
}
