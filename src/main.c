/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:12:03 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/09 12:34:36 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_game(struct s_game *game)
{
    game->mlx = 0;
    game->win = 0;
    game->C_cnt = 0;
    game->C_route_cnt = 0;
    game->P_cnt = 0;
    game->P_idx_x = 0;
    game->P_idx_y = 0;
    game->E_cnt = 0;
    game->map = 0;
    game->map_width = 0;
    game->map_height = 0;
    game->move_cnt = 0;
}

void    error_exit(char *str)
{
    ft_printf("%s\n", str);
    exit(1);
}

int main(int argc, char **argv)
{
    struct  s_game game;
    
    if (argc != 2)
        error_exit("Error");
    init_game(&game);
    init_map(argv[1], &game);
    
    return (0);
}