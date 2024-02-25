/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenkato <kenkato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:16:43 by kenkato           #+#    #+#             */
/*   Updated: 2024/02/25 16:30:43 by kenkato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096 

char **ft_split(char *str, char *charset);
int	ft_str_is_numeric(char *str);

char *test() 
{
    int fd; // ファイルディスクリプタを格納する変数
    char buffer[BUFFER_SIZE]; // 読み込んだデータを格納するバッファ
    ssize_t bytes_read; // 読み込んだバイト数を格納する変数
    char *charset;
    char **numbers_dict;
    char *dict;

    // "numbers.dict"を読み取り専用で開く
    fd = open("numbers.dict", O_RDONLY);

    if (fd == -1) 
    {
        write(1, "Error\n", 6);
        return 1;
    }
    bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytes_read == -1) 
    {
        write(1, "Error\n", 6);
        close(fd); 
        return 1;
    }

    // ヌル終端文字を追加してバッファを文字列として扱う
    buffer[bytes_read] = '\0';

    charset = " ";
    numbers_dict = ft_split(buffer, charset);

    dict = (char *)malloc(sizeof(char) * (bytes_read) + 1);
    
    int i = 0;
    int j;
    int len = 0;
    while (numbers_dict[i] != '\0')
    {
        j = 0;
        while (numbers_dict[i][j] != '\0')
        {
            dict[len] = numbers_dict[i][j];
            j++;
            len++;
        }
        i++;
    }   
    
    if (ft_str_is_numeric(dict))
    {
        write(2, "Dict Error\n", 11);
        return 1;
    }

    // printf("%s", dict);
    
    // close(fd);

    return dict;
}