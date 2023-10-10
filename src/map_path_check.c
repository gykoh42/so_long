/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:15:43 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/10 16:46:03 by gykoh            ###   ########.fr       */
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
        game->collect_route_cnt++;
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
    path_dfs(game, game->player_idx_y, game->player_idx_x);
    while (game->map[i] != NULL)
    {
        j = 0;
        while (game->map[i][j] != '\0')
        {
            if (game->map[i][j] == 'E')
                error_exit("Error: P can't go E");
            else if (game->collect_cnt != game->collect_route_cnt)
                error_exit("Error : C 못머금");
            j++;
        }
        i++;
    }
}