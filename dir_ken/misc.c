/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenkato <kenkato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:26:48 by hasano            #+#    #+#             */
/*   Updated: 2024/02/25 16:52:04 by kenkato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_power_pos(int base, int exp)
{
	int			i;
	long long int	n;

	i = 1;
	n = base;
	if (exp < 0)
		return (-1);
	else if (exp == 0)
		return (1);
	else if (base < 0)
		return (-1);
	while (i < exp)
	{
		n *= base;
		i++;
	}
	return (n);
}

int	ft_count_digits(long long int nb)
{
	int			i;
	long long int	src_num;

	i = 1;
	src_num = nb;
	if (src_num < 0)
		src_num *= -1;
	while (1)
	{
		if ((ft_power_pos(10, i)) > src_num)
			return (i);
		else
			i ++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		i++;
	return ((int)(s1[i] - s2[i]));
}

char	*ft_strstr(char *haystack, char *needle)
{
	char	*p;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(haystack);
	if (ft_strlen(needle) == 0)
		return (haystack);
	while (i < len)
	{
		p = &haystack[i];
		if (ft_strncmp(p, needle, ft_strlen(needle)) == 0)
			return (p);
		i ++;
	}
	return ((void *)0);
}

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i ++;
	}
	return ;
}