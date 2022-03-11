#include "checker.h"

static char *read_to_tmp(int fd, char *tmp);
static char *tmp_to_line(char *tmp);
static char *purge_line_from_tmp(char *tmp, char *line);
static char *find_line_break(char *s);

char    *gnl(int fd)
{
    static char *tmp;
    char        *line;

    line = NULL;
    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    tmp = read_to_tmp(fd, tmp);
    line = tmp_to_line(tmp);
    tmp = purge_line_from_tmp(tmp, line);
    return (line);
}

static char *read_to_tmp(int fd, char *tmp)
{
    char    buf[BUFFER_SIZE + 1];
    int     bytes;
    char    *new;

    bytes = 1;
    while (!find_line_break(tmp) && bytes > 0)
    {
        bytes = read(fd, buf, BUFFER_SIZE);
        if ((bytes == 0 && !tmp) || bytes == -1)
            return (NULL);
        buf[bytes] = '\0';
        if (!tmp)
        {
            tmp = malloc(1);
            tmp[0] = '\0';
        }
        new = ft_strjoin(tmp, buf);
        free(tmp);
    }
    return (new);
}

static char *tmp_to_line(char *tmp)
{
    char *new;

    if (find_line_break(tmp))
        new = ft_substr(tmp, 0, ft_strlen(tmp) - ft_strlen(find_line_break(tmp) + 1));
    else
        new = ft_substr(tmp, 0, ft_strlen(tmp));
    return (new);
}

static char *purge_line_from_tmp(char *tmp, char *line)
{
    char *new;

    if (!find_line_break(tmp))
    {
        free(tmp);
        return (NULL);
    }
    new = ft_substr(tmp, ft_strlen(line), ft_strlen(tmp) - ft_strlen(line));
    free(tmp);
    return (new);
}

static char *find_line_break(char *s)
{
    int i;

    i = 0;
    if (!s)
        return (NULL);
    while (s[i])
    {
        if (s[i] == '\n')
            return (&s[i]);
        i++;
    } 
    return (NULL);
}
