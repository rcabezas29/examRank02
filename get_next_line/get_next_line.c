#include "get_next_line.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char *ft_strdup(char *s)
{
    char *dest;
    int i;

    i = 0;
    dest = malloc(ft_strlen(s) + 1);
    while (s[i] != '\0')
    {
        dest[i] = s[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_strjoin(char *s, char c)
{
    char *dest;
    int i;

    i = 0;
    dest = malloc(ft_strlen(s) + 2);
    while (s[i] != '\0')
    {
        dest[i] = s[i];
        i++;
    }
    dest[i] = c;
    dest[i + 1] = '\0';
    free(s);
    return (dest);
}

int get_next_line(char **line)
{
    int ret;
    char *buf;

    ret = 0;
    buf = malloc(2);
    if (line == '\0' || !(*line = ft_strdup("")))
        return (-1);
    while (read(0, buf, 1))
    {
        if (buf[0] == '\n')
        {
            ret = 1;
            break ;
        }
        *line = ft_strjoin(*line, buf[0]);
    }
    free(buf);
    return (ret);
}
