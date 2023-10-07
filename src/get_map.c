#include "so_long.h"

void    get_map(char *argv, struct s_game *game)
{
    int fd;
    char *line;
    char *tmp;
    char *total_line;
    char **result;

    fd = open(argv, O_RDONLY);
    if (fd < 0)
        error("Error");
    line = get_next_line(fd);
    total_line = ft_strdup("");
    while (line != NULL)
    {
        tmp = total_line;
        total_line = ft_strjoin(total_line, line);
        free(tmp);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    result = ft_split(total_line, '\n');
    free(total_line);
    game->map = result;
}
