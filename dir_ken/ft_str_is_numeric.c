/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenkato <kenkato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:32:42 by kenkato           #+#    #+#             */
/*   Updated: 2024/02/24 21:32:58 by kenkato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (str[i] == 10)
		{
			flag = 1;
			i++;
		}
		while (flag && str[i] != ':' && str[i] != '\0' && str[i] != 10)
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (1);
			i++;
		}
		flag = 0;
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main()
// {
//     char *str = "0:zero\n\n10:un\n";
//     if (ft_str_is_numeric(str))
//     {
//         printf("NO\n");
//         return (1);
//     }
//     printf("YES\n");
// }
