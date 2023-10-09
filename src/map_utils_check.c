/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:36:04 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/09 12:39:29 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_check(struct s_game *game)
{
    int i;
    
    i = 0;
    while (game->map[0][game->map_width] != '\0')
        game->map_width++;
    while (game->map[game->map_height] != '\0')
        game->map_height++;
    while (i < game->map_height)
    {
        if ((int)ft_strlen(game->map[i]) != game->map_width)
            error_exit("Error");
        i++;
    }
}

void	wall_check(struct s_game *game)
{
    int i;
    int j;
    
    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j] != '\0')
        {
            if ((i == 0 || i == game->map_height - 1 || j == 0 || j == game->map_width - 1) && game->map[i][j] != '1')
                error_exit("Error");
            j++;
        }
        i++;
    }
}

void	component_check(struct s_game *game)
{
    int	i;
    int	j;

    i = 0;
    while (game->map[i] != '\0')
    {
        j = 0;
        while (game->map[i][j] != '\0')
        {   
            if (game->map[i][j] != '0' && game->map[i][j] != '1' && game->map[i][j] != 'C'
                && game->map[i][j] != 'P' && game->map[i][j] != 'E')
                error_exit("Error");
            j++;
        }
        i++;
    }
}

void	component_cnt_check(struct s_game *game)
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
                game->C_cnt++;
            if (game->map[i][j] == 'P')
            {
                game->P_cnt++;
                game->P_idx_x = j;
                game->P_idx_y = i;
            }
            if (game->map[i][j] == 'E')
                game->E_cnt++;
            j++;
        }
        i++;
    }
    if (!(game->C_cnt >= 1 && game->P_cnt == 1 && game->E_cnt == 1))
        error_exit("Error");
}

