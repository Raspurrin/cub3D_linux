/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:07:01 by emomkus           #+#    #+#             */
/*   Updated: 2022/10/21 12:11:30 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef __linux__
static void	control_hooks(t_data *data)
{
	long	x;
	long	y;

	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;
	mlx_hook(data->mlx.win, 2, (1L<<0), player_action, data); // keydown
	mlx_hook(data->mlx.win, 3, (1L<<1), player_stop_movement, data); //keyup 
	mlx_hook(data->mlx.win, 17, 0L, red_x_win, data);
	mlx_hook(data->mlx.win, 6, (1L << 6), player_mouse_action, data);
	mlx_mouse_move(data->mlx.ptr, data->mlx.win, x, y);
	mlx_mouse_hide(data->mlx.ptr, data->mlx.win);
}
#elif __APPLE__
static void	control_hooks(t_data *data)
{
	long	x;
	long	y;

	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;
	mlx_hook(data->mlx.win, 2, 0, player_action, data);
	mlx_hook(data->mlx.win, 3, 0, player_stop_movement, data);
	mlx_hook(data->mlx.win, 17, 0L, red_x_win, data);
	mlx_hook(data->mlx.win, 6, (1L << 6), player_mouse_action, data);
	mlx_mouse_move(data->mlx.win, (void *)x, y, 0);
	mlx_mouse_hide(data->mlx.win, 0);
}
#endif

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong input\n", 1);
		return (0);
	}
	constructor(&data, argv);
	control_hooks(&data);
	play_audio(data.util.soundtrack, 1);
	mlx_loop_hook(data.mlx.ptr, engine, (void *)&data);
	mlx_loop(data.mlx.ptr);
	return (0);
}
