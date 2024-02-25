/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenkato <kenkato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:59:19 by ktsubaki          #+#    #+#             */
/*   Updated: 2024/02/25 16:55:13 by kenkato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int				ft_strlen(char *src);
int				ft_atoi(char *str);
int				block_in(int nb, int num);
int				ft_isspace(char *str);
long long int	ft_power_pos(int base, int exp);
int				ft_count_digits(long long int nb);

// ここは3桁区切りのブロックを返す関数？
int	int_in(int ac, char **argv)
{
	unsigned long long int	num;
	unsigned long long int	i;
	unsigned long long int	length;

	i = 0;
	length = ft_strlen(argv[1]); /* = block_in(nb)のnb*/
	if (ac != 2)
	{
		write(1, "PLEASE WRITE ONE_NUMBER", 23);
		return (0);
	}
	num = ft_atoi(argv[1]); /*block_inにこのnumを渡す*/
	// block_in(length, num); // これは何のために必要？？
	return (block_in(length));
}

// ain't fix
int	block_in(int nb /*int num*/)
{
	int	i;

	i = nb / 3; /* +1は５の時とか割り切れなかった時に必要*/
	if (nb % 3 == 0)
		return (i);
	i++;
	return (i)
	// int block;
	// block = 0;
	// int A[(nb / 3) + 1];
	// while (num  > 0)
	// {
	// 	block = num % 1000;
	// 	A[i] = block;
	// 	i ++;
	// 	num = (num - block) / 1000;
	// }
}

int	sannchan_in(int ac, char **argv)
{
	unsigned long long int	length;
	unsigned long long int	gyou;
	unsigned long long int	**matrix;
	unsigned long long int	i;

	i = 0;
	length = ft_strlen(argv[1]);
	gyou = block_in(length);                       /*行の長さ*/
	matrix = (int **)malloc(gyou * sizeof(int *)); /*一旦行のマロックを確保*/
	if (matrix == NULL)
		return (NULL);
	while (i < gyou)
	{
		matrix[i] = (int *)malloc(3 * sizeof(int));
		i++;
	}
	if (matrix[i])
		return (NULL);
	return (matrix);
}

int	sanninsert(int ac, char **argv)
{
	unsigned long long int	tate;
	unsigned long long int	yoko;
	unsigned long long int	**martix;
	unsigned long long int	block;

	block = 0; /*初期化いりますか？*/
	martix = sunnchan_in(int ac, char **argv);
	tate = 0;
	while (martix[tate])
	{
		yoko = 0;
		while (martix[yoko])
		{
			block = num % 1000;
			martix[tate][yoko] = block;
			yoko++;
			num = (num - block) / 1000;
		}
		tate++;
	}
	return (martix[tate][yoko]);
}

int	ft_isspace(char *str)
{
	if (*str <= 13 && *str >= 9)
		return (1);
	if (*str == 32)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	count;
	int	num;

	count = 0;
	num = 0;
	while (ft_isspace(str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			count++;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (count % 2 != 0)
	{
		write(1, "PLEASE WRITE POSITIVE NUMBER", 28);
		return (0);
	}
	return (num);
}

int	ft_strlen(char *src)
{
	int						i;
	int						i;
	unsigned long long int	n;
	int						i;
	long long int			src_num;
	int						ac;
	char					*av[2] = {"a.out", "100000"};
	int						i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	i--;
	return (i);
} /*iはヌル文字が入った分なのでひく*/

// long long int	ft_power_pos(int base, int exp)
// {
// 	i = 1;
// 	n = base;
// 	if (exp < 0)
// 		return (-1);
// 	else if (exp == 0)
// 		return (1);
// 	else if (base < 0)
// 		return (-1);
// 	while (i < exp)
// 	{
// 		n *= base;
// 		i++;
// 	}
// 	return (n);
// } /*べき乗を出す関数で桁数出すために必要なので描いてる*/

// int	ft_count_digits(long long int nb)
// {
// 	i = 1;
// 	src_num = nb;
// 	if (src_num < 0)
// 		src_num *= -1;
// 	while (1)
// 	{
// 		if ((ft_power_pos(10, i)) > src_num)
// 			return (i);
// 		else
// 			i++;
// 	}
// 	return (i);
// } /*桁数を出す関数*/

// #include <stdio.h>

// int	main(void)
// {
// 	ac = 2;
// 	i = int_in(ac, av);
// 	printf("%d\n", i);
// }
