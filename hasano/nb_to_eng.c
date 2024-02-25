/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_to_eng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenkato <kenkato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:53:38 by hasano            #+#    #+#             */
/*   Updated: 2024/02/25 16:09:44 by kenkato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	return (i);
}

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

int	ft_strlen_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i ++;
	return (i);
}

int	ft_strncmp(char *s1, unsigned char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		i ++;
	return ((int)(s1[i] - s2[i]));
}

char	*ft_strstr(char *haystack, unsigned char *needle)
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

unsigned char	*ft_itoa(int nb)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	n = ft_count_digits(nb);
	while (i < n)
	{
		str[i] = ((nb / ft_power_pos(10, 2 - i)) % 10) + '0';
		i ++;
	}
	return (str);
}

int	nb_to_eng(char *dict, int *array, int array_size)
{
	int				i;
	int				j;
	unsigned char	*p_array;
	unsigned char	array_mem[3];
	char			*p;
	int				str_size;

	i = 0;
	p_array = &array_mem[0];
	while (i++ < array_size)
	{
		p_array = ft_itoa(array[i]);
		j = 0;
		while (j < 3)
		if (array_mem[j] != 0)
		{
			p = ft_strstr(dict, &array_mem[j]);
			p += 2;
			str_size = ft_strlen_newline(p);
			write(1, p, str_size);
			p = ft_strstr(dict, ft_itoa(ft_power_pos(10, 2 - j)));
			p += ft_count_digits(ft_power_pos(10, 2 - j)) + 1;
			str_size = ft_strlen_newline(p);
			write(1, p, str_size);
			j ++;
		}
		p = ft_strstr(dict, ft_itoa(ft_power_pos(10, 3 * (array_size - i - 1))));
		p += ft_count_digits(ft_power_pos(10, 3 * (array_size - i - 1))) + 1;
		str_size = ft_strlen_newline(p);
		write(1, p, str_size);
	}
}
