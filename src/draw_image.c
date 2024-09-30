/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 19:26:19 by mmosk         #+#    #+#                 */
/*   Updated: 2024/09/30 21:10:35 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	blank_image(t_img *img)
{
	int				i;
	unsigned int	color;
	
	color = 0x000000FF;
	i = 0;
	while ((unsigned int)i < img->height * img->width)
	{
		((unsigned int *)img->pixels)[i] = color;
		i++;
	}
}

void	*draw_fract(t_threadstate *state)
{
	t_img			*img;
	t_cam			cam;
	t_fractal		fractal;
	int				i;
	unsigned int	color;
	t_complex		position;

	img = state->screen->img;
	cam = state->screen->camera;
	fractal = state->screen->fractal;
	i = state->bias;
	while ((unsigned int)i < img->height * img->width
		&& state->screen->continue_drawing == true)
	{
		position.real = (double)(i % img->width + cam.x_offset) * cam.zoom * JUST;
		position.imgn = (double)(i / img->width + cam.y_offset) * cam.zoom * JUST;
		color = fractal.get_color(position, cam.occlusion, fractal);
		((unsigned int *)img->pixels)[i] = color;
		i += THREAD_MAX;
	}
	return (NULL);
}
