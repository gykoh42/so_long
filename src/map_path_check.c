/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:15:43 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/09 12:15:57 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    path_dfs(struct s_game *game, int row, int col)
{
    if (row < 0 || col < 0 || row >= game->map_height - 1
		|| col >= game->map_width - 1 || game->map[row][col] == '1'
		|| game->map[row][col] == 'x')
		return ;
    if (game->map[row][col] == 'C')
        game->C_route_cnt++;
	game->map[row][col] = 'x';
	path_dfs(row + 1, col, game);
	path_dfs(row - 1, col, game);
	path_dfs(row, col + 1, game);
	path_dfs(row, col - 1, game);
}

void    path_check(struct s_game *game)
{
    int i;
    int j;

    i = 0;
    path_dfs(game, game->P_idx_y, game->P_idx_x);
    if (game->C_cnt != game->C_route_cnt)
        error("Error");
    while (game->map[i] != '\0')
    {
        j = 0;
        while (game->map[i][j] != '\0')
        {
            if (game->map[i][j] == 'E')
                error("Error");
            j++;
        }
        i++;
    }
}