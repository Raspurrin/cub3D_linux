/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:06:52 by emomkus           #+#    #+#             */
/*   Updated: 2022/10/20 20:43:09 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef BONUS

void	play_audio(char *audioo, int loudness)
{
	int		pid;
	char	**argv;
	(void)loudness;

	argv = ft_calloc(3, sizeof(char *));
	argv[0] = ft_strdup(AUDIO);
	argv[1] = ft_strdup(audioo);
	argv[2] = NULL;
	// argv[1] = ft_strdup("-v");
	// argv[2] = ft_itoa(loudness);
	
	pid = fork();
	if (!pid)
	{
		execve(AUDIO, argv, NULL);
		exit(0);
	}
	free(argv[0]);
	free(argv[1]);
	free(argv[2]);
	// free(argv[3]);
	free(argv);
}

void	end_audio(void)
{
	int		pid;
	char	**argv;

	argv = ft_calloc(3, sizeof(char *));
	argv[0] = ft_strdup("killall");
	argv[1] = ft_strdup(PLAY);
	pid = fork();
	if (!pid)
	{
		execve("/usr/bin/killall", argv, NULL);
		exit(0);
	}
	free(argv[0]);
	free(argv[1]);
	free(argv);
}

#else

void	play_audio(char *audio, int loudness)
{
	(void) audio;
	loudness++;
}

void	end_audio(void)
{
}
#endif