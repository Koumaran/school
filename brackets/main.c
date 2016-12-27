/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 10:05:21 by exam              #+#    #+#             */
/*   Updated: 2016/12/20 15:01:43 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int			crochet(char *str, int i, int *par, int *acc, int *cro, int len);
int			accolade(char *str, int i, int *par, int *acc, int *cro, int len);
int			parenthese(char *str, int i, int *par, int *acc, int *cro, int len);


int		crochet(char *str, int i, int *par, int *acc, int *cro, int len)
{
	*cro += (i < len && str[i] == '[') ? 1 : 0;
	*cro -= (i < len && str[i++] == ']') ? 1 : 0;
	while (i < len && *cro)
	{
		if (str[i] == '}' && !*acc)
			return (len);
		if (str[i] == ')' && !*par)
			return (len);
		if (str[i] == ']')
			*cro = *cro - 1;
		if (str[i] == '[')
			*cro = *cro + 1;
		if (str[i] == '{' || str[i] == '}')
			i = (accolade(str, i, par, acc, cro, len));
		else if (str[i] == '(' || str[i] == ')')
			i = (parenthese(str, i, par, acc, cro, len));
		else
			i++;
	}
	return (i);
}

int			accolade(char *str, int i, int *par, int *acc, int *cro, int len)
{
	*acc += (i < len && str[i] == '{') ? 1 : 0;
	*acc -= (i < len && str[i++] == '}') ? 1 : 0;
	while (i < len && *acc)
	{
		if (str[i] == ')' && !*par)
			return (len);
		if (str[i] == ']' && !*cro)
			return (len);
		if (str[i] == '}')
			*acc -= 1;
		if (str[i] == '{')
			*acc += 1;
		if (str[i] == '(' || str[i] == ')')
			i = (parenthese(str, i, par, acc, cro, len));
		else if (str[i] == '[' || str[i] == ']')
			i =  (crochet(str, i, par, acc, cro, len));
		else
			i++;
	}
	return (i);
}


int			parenthese(char *str, int i, int *par, int *acc, int *cro, int len)
{
	*par += (i < len && str[i] == '(') ? 1 : 0;
	*par -= (i < len && str[i++] == ')') ? 1 : 0;
	while (i < len && *par)
	{
		if (str[i] == '}' && !*acc)
			return (len);
		if (str[i] == ']' && !*cro)
			return (len);
		if (str[i] == ')')
			*par -= 1;
		if (str[i] == '(')
			*par += 1;
		if (str[i] == '{' || str[i] == '}')
			i =  (accolade(str, i, par, acc, cro, len));
		else if (str[i] == '[' || str[i] == ']')
			i =  (crochet(str, i, par, acc, cro, len));
		else 
			i++;
	}
	return (i);
}

int			brackets(char *str)
{
	int		par;
	int		cro;
	int		acc;
	int		i;
	int		len;

	par = 0;
	i = 0;
	len = 0;
	acc = 0;
	cro = 0;
	while (str[len])
		len++;
	while (i < len)
	{
		if (str[i] == ')' && !par)
			return (0);
		if (str[i] == '}' && !acc)
			return (0);
		if (str[i] == ']' && !cro)
			return (0);
		if (str[i] == '(')
			i = parenthese(str, i, &par, &acc, &cro, len);
		else if (str[i] == '{')
			i = accolade(str, i, &par, &acc, &cro, len);
		else if (str[i] == '[')
			i = crochet(str, i, &par, &acc, &cro, len);
		else
			i++;
	}
	if (par)
		return (0);
	if (acc)
		return (0);
	if (cro)
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	int		i;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			if (brackets(av[i++]))
				write (1, "OK\n", 3);
			else
				write (1, "Error\n", 6);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
