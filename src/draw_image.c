/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 19:26:19 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/19 15:25:23 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_fract(t_img *img, t_cam cam, t_fractal fractal)
{
	int				x;
	int				y;
	unsigned int	color;
	t_complex		position;

	y = 0;
	while ((unsigned int)y < img->height)
	{
		x = 0;
		while ((unsigned int)x < img->width)
		{
			position.real = (double)(x + cam.x_offset) *cam.zoom * JUST;
			position.imgn = (double)(y + cam.y_offset) *cam.zoom * JUST;
			color = fractal.get_color(position, cam.occlusion, fractal);
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}
