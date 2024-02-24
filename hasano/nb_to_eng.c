/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_to_eng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasano <hasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:53:38 by hasano            #+#    #+#             */
/*   Updated: 2024/02/24 17:58:25 by hasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_power_pos(int base, int exp);
int	ft_count_digits(long long int nb);

int	ft_strlen(char *str)
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
		s[i] = ((nb / ft_power_pos(10, 2 - i)) % 10) + '0';
		i ++;
	}
	return (str);
}

int	nb_to_eng(char *dict, int *array, int array_size)
{
	int				i;
	int				j;
	unsigned char	array_mem[3];
	char			*p;
	int				str_size;

	i = 0;
	while (i++ < array_size)
	{
		itoa_three_digits(array[i], &array_mem[0]);
		j = 0;
		while (j < 3)
		if (array_mem[j] != 0)
		{
			p = ft_strstr(dict, &array_mem[0]);
			p += ft_count_digits(array_mem[0]) + 1;
			str_size = ft_strlen(p);
			write (1, p, str_size);
			p = ft_strstr(dict, ft_itoa(ft_power_pos(10, 2 - j)));
		}
	}
}
