/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:15:43 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/09 15:59:40 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    path_dfs(t_game_info *game, int row, int col)
{
    if (row < 0 || col < 0 || row >= game->map_height - 1
		|| col >= game->map_width - 1 || game->map[row][col] == '1'
		|| game->map[row][col] == 'x')
		return ;
    if (game->map[row][col] == 'C')
        game->C_route_cnt++;
	game->map[row][col] = 'x';
	path_dfs(game, row + 1, col);
	path_dfs(game, row - 1, col);
	path_dfs(game, row, col + 1);
	path_dfs(game, row, col - 1);
}

void    path_check(t_game_info *game)
{
    int i;
    int j;

    i = 0;
    path_dfs(game, game->P_idx_y, game->P_idx_x);
    if (game->C_cnt != game->C_route_cnt)
        error_exit("Error: C_cnt != C_route_cnt");
    while (game->map[i] != NULL)
    {
        j = 0;
        while (game->map[i][j] != '\0')
        {
            if (game->map[i][j] == 'E')
                error_exit("Error: P can't go E");
            j++;
        }
        i++;
    }
}