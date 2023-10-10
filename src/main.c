/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:12:03 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/10 18:46:56 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game_info *game)
{
	game->mlx = 0;
	game->win = 0;
	game->collect_cnt = 0;
	game->collect_route_cnt = 0;
	game->player_cnt = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_cnt = 0;
	game->map = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->move_cnt = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->img.collect = 0;
	game->img.exit = 0;
	game->img.ground = 0;
	game->img.player = 0;
	game->img.wall = 0;
}

void	error_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

int	close_window(t_game_info *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

void	check_arg(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		error_exit("Error: argc wrong");
	i = ft_strlen(argv[1]);
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e' \
		|| argv[1][i - 3] != 'b' || argv[1][i - 4] != '.')
		error_exit("Error: file name wrong");
}

int	main(int argc, char **argv)
{
	t_game_info	game;

	if (argc != 2)
		error_exit("Error: argc != 2");
	init_game(&game);
	init_map(argv[1], &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map_width * 32, \
								game.map_height * 32, "so_long");
	convert_and_draw(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 1L << 17, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
