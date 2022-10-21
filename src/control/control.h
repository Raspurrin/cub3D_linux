/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:04:28 by emomkus           #+#    #+#             */
/*   Updated: 2022/10/20 20:43:01 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
# define CONTROL_H

# include "../cub3d.h"

typedef struct s_vect		t_vect;
typedef struct s_color		t_color;
typedef struct s_data		t_data;
typedef struct s_map		t_map;
typedef struct s_textures	t_textures;
typedef struct s_video		t_video;
typedef struct s_mlx		t_mlx;

# if __linux__
#  define W 119
#  define W2 119
#  define A 97
#  define S 115
#  define S2 115
#  define D 100
#  define P 112
#  define TAB 65289
#  define ESC 65307
#  define SPACE 32
#  define E 101
#  define LEFT 65361
#  define RIGHT 65363
#  define AUDIO "/usr/bin/aplay"
#  define PLAY "aplay"

# elif __APPLE__
#  define W 13
#  define W2 126
#  define A 0
#  define S 1
#  define S2 125
#  define D 2
#  define P 35
#  define TAB 48
#  define ESC 53
#  define SPACE 49
#  define E 14
#  define LEFT 123
#  define RIGHT 124
#  define AUDIO "/usr/bin/afplay", "--volume", "1"
#  define PLAY "afplay"
#
# endif

int		player_action(int keycode, t_data *data);
int		red_x_win(t_data *data);
int		player_mouse_action(int x, int y, t_data *data);
int		player_mouse_action_stop(int x, int y, t_data *data);
int		player_stop_movement(int keycode, t_data *data);

/*
	Move player functions
*/
void	move_forward(t_data *data);
void	move_backwards(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

/*
	Rotate player
*/
void	rotate_player_left(t_data *data);
void	rotate_player_right(t_data *data);
void	rotate_player(t_data *data, int x);

/*
	More
*/
void	pop_minimap(t_data *data);
void	close_win(t_data *data);
void	menu_pop(t_data *data);
void	toggle_door(t_data *data);

#endif