/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:09:13 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/10 17:14:19 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_map(t_game_info *game)
{
    int x;
    int y;

    y = 0;
    mlx_clear_window(game->mlx, game->win);
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->img.ground, x * 32, y * 32);
            else if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img.wall, x * 32, y * 32);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img.collect, x * 32, y * 32);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x * 32, y * 32);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->img.player, x * 32, y * 32);
            x++;
        }
        y++;
    }
}
void convert_and_draw(t_game_info *game)
{
    int width;
    int height;

    game->img.ground = mlx_xpm_file_to_image(game->mlx, "./img/ground.xpm", &width, &height);
    game->img.wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &width, &height);
    game->img.collect = mlx_xpm_file_to_image(game->mlx, "./img/collect.xpm", &width, &height);
    game->img.exit = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &width, &height);
    game->img.player = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &width, &height);
    draw_map(game);
}