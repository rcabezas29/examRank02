#include "get_next_line.h"

int     ft_strlen(char *str)
{
    int     i;
    i = 0;
    while (str[i] != '\0')
        i++;
    return(i);
}

char    *ft_strdup(char *str)
{
    int     i;
    char    *dest;
    if (!(dest = malloc(ft_strlen(str) + 1)))
        return(0);
    i = 0;
    while (str[i] != '\0')
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
}

char    *ft_strjoin(char *str, char *c)
{
    int     i;
    char    *dest;
    if(!(dest = malloc(ft_strlen(str) + ft_strlen(c) + 1)))
        return(0);
    i = 0;
    while (str[i] != '\0')
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = c[0];
    dest[i + 1] = '\0';
    return(dest);
}

int     get_next_line(char **line)
{
    char    buf[1];
    int     ret;

    if (line == '\0' || !(*line = ft_strdup("")))
        return(-1);
    while ((ret = read(0, buf, 1)) > 0)
    {
        if (buf[0] == '\n' || buf[0] == '\0')
        {
            buf[0] = '\0';
            break ;
        }
        *line = ft_strjoin(*line, buf);
    }
    buf[0] = '\0';
    return(ret);
}
/*
int     main(void)
{
    int        r;
    int        fd;
    char    *line;
    line = NULL;
    while ((r = get_next_line(&line)) > 0)
    {
        printf("%s\n", line);
        free(line);
        line = NULL;
    }
    printf("%s", line);
    free(line);
    line = NULL;
    system ("leaks a.out");
}*/
