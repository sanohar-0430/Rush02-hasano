/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_to_eng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenkato <kenkato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:31:38 by hasano            #+#    #+#             */
/*   Updated: 2024/02/24 21:34:48 by hasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*test(char *dict_name);
int		int_in(int ac, char **argv)
int		nb_to_eng(char *dict, int *array, int array_size);

int	main(int argc, char* argv[])
{
	char	*dict_data;
	int		array_size;

	if (argc > 3 || argc < 2)
	{
		write(1, "Error\n" 7);
		return (0);
	}
	if (argc == 3)
	{
		array_size = int_in(2, argv[3]);
		test(argv[2]);
	}
	else
	{
		array_size = int_in(2, argv[2]);
		dict_data = test("numbers.dict");
	}
	nb_to_eng(dict_data, , array_size);
	return (0);
}