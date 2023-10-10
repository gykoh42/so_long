/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:36:04 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/10 18:26:16 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_check(t_game_info *game)
{
	int	i;

	i = 0;
	if (*game->map == NULL)
		error_exit("Error: empty file");
	while (game->map[0][i] != '\0')
	{
		game->map_width++;
		i++;
	}
	i = 0;
	while (game->map[i] != NULL)
	{
		game->map_height++;
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if ((int)ft_strlen(game->map[i]) != game->map_width)
			error_exit("Error: map width different");
		i++;
	}
}

void	wall_check(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if ((i == 0 || i == game->map_height - 1 || j == 0 \
				|| j == game->map_width - 1) && game->map[i][j] != '1')
				error_exit("Error: wall != 1");
			j++;
		}
		i++;
	}
}

void	component_check(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' \
				&& game->map[i][j] != 'C' && game->map[i][j] != 'P' \
				&& game->map[i][j] != 'E')
				error_exit("Error: different component");
			j++;
		}
		i++;
	}
}

void	component_cnt_check(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				game->collect_cnt++;
			if (game->map[i][j] == 'P')
				game->player_cnt++;
			if (game->map[i][j] == 'E')
				game->exit_cnt++;
			j++;
		}
		i++;
	}
	if (!(game->collect_cnt >= 1 && game->player_cnt == 1 \
		&& game->exit_cnt == 1))
		error_exit("Error: wrong component count");
}

void	component_idx_check(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			if (game->map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
			}
			j++;
		}
		i++;
	}
}
