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
	while (line[++i])
	{
		if (line[i] == '-')
		{

			str = ft_strsub(line, j, i);
			if (tmp && ft_strcmp(str, tmp) == 0)
			{
				ft_strdel(&str);
				ft_strdel(&tmp);
			}
			if (i == ft_strlen(line) - 1 && !r1)
				break ;
			if (str)
			{	
				if (!r1)
				{
					r1 = check_room_name(lem, str);
					j = (r1) ? i : 0;
				}
				else
				{
					if (!(r2 = check_room_name(lem, str)) && !line[i + 1])
					{
						r1 = NULL;
						j = 0;
						i = -1;
						tmp = ft_strdup(r1->name);
					}
				}
				ft_strdel(&str);
			}
		}
	}
	if (r1 && r2)
	{
		line[j] = '+';
		return (ft_strsplit(line, '+'));
	}
	return (NULL);
}
