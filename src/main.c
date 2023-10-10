/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:12:03 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/10 17:19:08 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_game(t_game_info *game)
{
    game->mlx = 0;
    game->win = 0;
    game->collect_cnt = 0;
    game->collect_route_cnt = 0;
    game->player_cnt = 0;
    game->player_idx_x = 0;
    game->player_idx_y = 0;
    game->exit_cnt = 0;
    game->map = 0;
    game->map_width = 0;
    game->map_height = 0;
    game->move_cnt = 0;
    game->exit_idx_x = 0;
    game->exit_idx_y = 0;
}

void    error_exit(char *str)
{
    ft_printf("%s\n", str);
    exit(1);
}

int   close_window(t_game_info *game)
{
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}

int main(int argc, char **argv)
{
    t_game_info game;

    if (argc != 2)
        error_exit("Error: argc != 2");
    init_game(&game);
    init_map(argv[1], &game);
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, game.map_width * 32, game.map_height * 32, "so_long");
    convert_and_draw(&game);
    mlx_hook(game.win, 2, 1L<<0, key_press, &game);
    mlx_hook(game.win, 17, 1L<<17, close_window, &game);
    mlx_loop(game.mlx);
    return (0);
}
