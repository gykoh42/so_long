/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:35:26 by gykoh             #+#    #+#             */
/*   Updated: 2023/10/10 18:26:16 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game_info *game)
{
	if (game->map[game->player_y - 1][game->player_x] == '1')
		return ;
	else if (game->map[game->player_y - 1][game->player_x] == 'E' \
													&& game->collect_cnt == 0)
	{
		game->move_cnt++;
		ft_printf("move_cnt: %d\n", game->move_cnt);
		close_window(game);
	}
	else if (game->map[game->player_y - 1][game->player_x] == 'C')
		game->collect_cnt--;
	if (game->player_x == game->exit_x \
									&& game->player_y == game->exit_y)
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y - 1][game->player_x] = 'P';
	game->player_y--;
	game->move_cnt++;
}

void	move_down(t_game_info *game)
{
	if (game->map[game->player_y + 1][game->player_x] == '1')
		return ;
	else if (game->map[game->player_y + 1][game->player_x] == 'E' \
													&& game->collect_cnt == 0)
	{
		game->move_cnt++;
		close_window(game);
	}
	else if (game->map[game->player_y + 1][game->player_x] == 'C')
		game->collect_cnt--;
	if (game->player_x == game->exit_x \
									&& game->player_y == game->exit_y)
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y + 1][game->player_x] = 'P';
	game->player_y++;
	game->move_cnt++;
}

void	move_left(t_game_info *game)
{
	if (game->map[game->player_y][game->player_x - 1] == '1')
		return ;
	else if (game->map[game->player_y][game->player_x - 1] == 'E' \
													&& game->collect_cnt == 0)
	{
		game->move_cnt++;
		ft_printf("move_cnt: %d\n", game->move_cnt);
		close_window(game);
	}
	else if (game->map[game->player_y][game->player_x - 1] == 'C')
		game->collect_cnt--;
	if (game->player_x == game->exit_x \
									&& game->player_y == game->exit_y)
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y][game->player_x - 1] = 'P';
	game->player_x--;
	game->move_cnt++;
}

void	move_right(t_game_info *game)
{
	if (game->map[game->player_y][game->player_x + 1] == '1')
		return ;
	else if (game->map[game->player_y][game->player_x + 1] == 'E' \
													&& game->collect_cnt == 0)
	{
		game->move_cnt++;
		ft_printf("move_cnt: %d\n", game->move_cnt);
		close_window(game);
	}
	else if (game->map[game->player_y][game->player_x + 1] == 'C')
		game->collect_cnt--;
	if (game->player_x == game->exit_x \
									&& game->player_y == game->exit_y)
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y][game->player_x + 1] = 'P';
	game->player_x++;
	game->move_cnt++;
}

int	key_press(int keycode, t_game_info *game)
{
	if (keycode == 53)
		close_window(game);
	else if (keycode == 13)
		move_up(game);
	else if (keycode == 1)
		move_down(game);
	else if (keycode == 0)
		move_left(game);
	else if (keycode == 2)
		move_right(game);
	draw_map(game);
	ft_printf("move_cnt: %d\n", game->move_cnt);
	return (0);
}
