/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenkato <kenkato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:32:04 by kenkato           #+#    #+#             */
/*   Updated: 2024/02/25 16:19:33 by kenkato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	sepstr_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !check_charset(str[i], charset))
		i++;
	return (i);
}

int	cnt_str(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_charset(str[i], charset))
			i++;
		if (str[i] != '\0')
			cnt++;
		while (str[i] != '\0' && !check_charset(str[i], charset))
			i++;
	}
	return (cnt);
}

char	*get_sepstr(char *str, char *charset)
{
	int		i;
	int		len;
	char	*sepstr;

	i = 0;
	len = sepstr_len(str, charset);
	sepstr = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		sepstr[i] = str[i];
		i++;
	}
	sepstr[i] = '\0';
	return (sepstr);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**string;

	i = 0;
	string = (char **)malloc(sizeof(char *) * cnt_str(str, charset) + 1);
	while (*str != '\0')
	{
		while (*str != '\0' && check_charset(*str, charset))
			str++;
		if (*str != '\0')
		{
			string[i] = get_sepstr(str, charset);
			i++;
		}
		while (*str != '\0' && !check_charset(*str, charset))
			str++;
	}
	string[i] = 0;
	return (string);
}
