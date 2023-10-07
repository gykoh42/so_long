/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:36:04 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/07 22:25:26 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_check(struct s_game *game, char **map)
{
	int	i;
	int	j;

	while (map[0][game->map_width] != '\0')
		game->map_width++;
	while (map[game->map_height] != '\0')
		game->map_height++;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == game->map_height - 1) && map[i][j] != '1')
				error("Error");
			if ((j == 0 || j == game->map_width - 1) && map[i][j] != '1')
				error("Error");
			j++;
		}
		i++;
	}
}

void	component_check(struct s_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{	
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'P' && map[i][j] != 'E')
				error("Error");
			j++;
		}
		i++;
	}
}

void	component_cnt_check(struct s_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{	
			if (map[i][j] == 'C')
				game->C_cnt++;
			if (map[i][j] == 'P')
			{
				game->P_cnt++;
				game->P_idx_x = j;
				game->P_idx_y = i;
			}
			if (map[i][j] == 'E')
				game->E_cnt++;
			j++;
		}
		i++;
	}
	if (!(game->C_cnt >= 1 && game->P_cnt == 1 && game->E_cnt == 1))
		error("Error");
}
