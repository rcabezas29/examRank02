/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 08:43:07 by rcabezas          #+#    #+#             */
/*   Updated: 2020/07/07 08:53:14 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     main(int argc, char **argv)
{
    int used[255];
    int i;
    int j;

    if (argc == 3)
    {
        i = 0;
        while (i++ < 255)
            used[i] = 0;
        i = 1;
        while (i < 3)
        {
            j  = 0;
            while(argv[i][j])
            {
                if (!used[(unsigned char)argv[i][j]])
                {
                    used[((unsigned char)argv[i][j])] = 1;
                    write(1, &argv[i][j], 1);
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
