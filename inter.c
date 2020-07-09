/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:18:31 by rcabezas          #+#    #+#             */
/*   Updated: 2020/07/07 08:46:05 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char    *ft_strchr(char *s, int c)
{
    while (*s++ != c)
    {
        if (*s == '\n')
            retur(NULL);
    }
    return (s);
}

int     main(int argc, char **argv)
{
    int used[255];
    int x;

    x = 0;
    if (argc == 3)
    {
        while (x++ < 255)
            used[x] = 0;
        x = 0;
        while (argv[1][x])
        {
            if (!used[(unsigned char)argv[1][x]] && ft_strchr(argv[2], argv[1][x]))
            {
                used[(unsigned char)argv[1][x]] = 1;
                write(1, &argv[1][x], 1);
            }
            x++;
        }
        write (1, "\n", 1);
    }
    return (0);
}
