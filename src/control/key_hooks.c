/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:04:31 by emomkus           #+#    #+#             */
/*   Updated: 2022/10/20 20:25:22 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

static void	*get_action_function(int keycode, t_data *data)
{
	if (keycode == A)
		data->keys.key_a[0] = 1;
	if (keycode == D)
		data->keys.key_d[0] = 1;
	if (keycode == S || keycode == S2)
		data->keys.key_s[0] = 1;
	if (keycode == W || keycode == W2)
		data->keys.key_w[0] = 1;
	if (keycode == E)
		return (&toggle_door);
	if (keycode == SPACE)
		data->keys.key_space[0] = 1;
	if (keycode == LEFT)
		return (&rotate_player_left);
	if (keycode == RIGHT)
		return (&rotate_player_right);
	if (keycode == TAB)
		return (&pop_minimap);
	if (keycode == P)
		return (&menu_pop);
	if (keycode == ESC)
		return (&close_win);
	return (NULL);
}

int	player_action(int keycode, t_data *data)
{
	void	(*action)(t_data *);

	action = get_action_function(keycode, data);
	if (action)
		action(data);
	return (0);
}

/*
	Subtract from movement acording to dir
*/
int	player_stop_movement(int keycode, t_data *data)
{
	if (keycode == A)
		data->keys.key_a[0] = 0;
	if (keycode == D)
		data->keys.key_d[0] = 0;
	if (keycode == S || keycode == S2)
		data->keys.key_s[0] = 0;
	if (keycode == W || keycode == W2)
		data->keys.key_w[0] = 0;
	if (keycode == SPACE)
	{
		data->keys.key_space[1] = 0;
		data->keys.key_space[0] = 0;
	}
	return (0);
}

int	player_mouse_action(int x, int y, t_data *data)
{
	long	mouse_x;
	long	mouse_y;

	mouse_x = SCREEN_WIDTH / 2;
	mouse_y = SCREEN_HEIGHT / 2;
	y++;
	rotate_player(data, x - mouse_x);
	mlx_mouse_move(data->mlx.ptr, data->mlx.win, mouse_x, mouse_y);
	return (0);
}

int	player_mouse_action_stop(int x, int y, t_data *data)
{
	(void) data;
	x++;
	y++;
	return (0);
}
