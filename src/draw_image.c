/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 19:26:19 by mmosk         #+#    #+#                 */
/*   Updated: 2024/09/30 21:16:58 by mmosk         ########   odam.nl         */
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
	i = state->identity;
	while ((unsigned int)i < img->height * img->width
		&& state->screen->finished_drawing == false)
	{
		position.real = (double)(i % img->width + cam.x_offset) * cam.zoom * JUST;
		position.imgn = (double)(i / img->width + cam.y_offset) * cam.zoom * JUST;
		color = fractal.get_color(state, position, cam.occlusion, fractal);
		mlx_put_pixel(img, i % img->width, i / img->width, color);
		// ((unsigned int *)img->pixels)[i] = color;
		i += THREAD_MAX;
	}
	return (NULL);
}
