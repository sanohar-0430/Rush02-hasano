/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_to_eng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasano <hasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:53:38 by hasano            #+#    #+#             */
/*   Updated: 2024/02/24 16:46:41 by hasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_power_pos(int base, int exp);
int	ft_count_digits(long long int nb);

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

unsigned char	*itoa_three_digits(int nb, unsigned char *s)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		s[i] = ((nb / ft_power_pos(10, 2 - i)) % 10) + '0';
		i ++;
	}
	return (&s[0]);
}

int	nb_to_eng(char *dict, char *dest, int *array, int array_size)
{
	int				i;
	unsigned char	array_mem[3];
	char			*p;

	i = 0;
	while (i++ < array_size)
	{
		itoa_three_digits(array[i], &array_mem[0]);
		if (array_mem[i] != 0)
		{
			p = ft_strstr(dict, &array_mem[0]);
			p += ft_count_digits(array_mem[0]) + 1;
			while ()
		}
	}
}
