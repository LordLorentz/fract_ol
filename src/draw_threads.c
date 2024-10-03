/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_threads.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/30 20:21:35 by mmosk         #+#    #+#                 */
/*   Updated: 2024/09/30 21:01:09 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	initialize_threadstate(t_screenstate *screen)
{
	int	i;

	i = 0;
	while (i < THREAD_MAX)
	{
		screen->threadstate[i].identity = i;
		screen->threadstate[i].screen = screen;
		i++;
	}
}

void	create_draw_threads(t_screenstate *screen)
{
	int				i;
	t_threadstate	*current;

	blank_image(screen->img);
	screen->continue_drawing = true;
	i = 0;
	while (i < THREAD_MAX)
	{
		current = &screen->threadstate[i];
		pthread_create(&current->thread *, NULL, (t_sr)draw_fract, current);
		i++;
	}
}

void	join_draw_threads(t_screenstate *screen)
{
	int				i;
	t_threadstate	*current;

	screen->continue_drawing = false;
	i = 0;
	while (i < THREAD_MAX)
	{
		current = &screen->threadstate[i];
		pthread_join(current->thread *, NULL);
		i++;
	}
}

void	draw_cycle(t_screenstate *screen)
{
	join_draw_threads(screen);
	create_draw_threads(screen);
}
