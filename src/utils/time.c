/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:06:37 by emomkus           #+#    #+#             */
/*   Updated: 2022/10/20 19:41:22 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long long	set_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec);
}
