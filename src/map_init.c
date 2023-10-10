/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:39:45 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/10 17:51:47 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game_info *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	get_map(char *argv, t_game_info *game)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*total_line;
	char	**result;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_exit("Error: fd < 0");
	line = get_next_line(fd);
	total_line = ft_strdup("");
	while (line != NULL)
	{
		if (ft_strchr(line, '\n') == line)
			error_exit("Error: newline is in line");
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

void	init_map(char *argv, t_game_info *game)
{
	get_map(argv, game);
	map_total_check(game);
	free_map(game);
	get_map(argv, game);
}
