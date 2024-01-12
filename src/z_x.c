/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   z_x.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/09 15:32:18 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/12 16:51:39 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static inline t_complex	iterate_z_xmath(t_complex z, t_complex *c, double symmetry)
{
	const double	radius = sqrt(pow(z.real, 2) + pow(z.imgn, 2));
	const double	angle = tan(z.imgn / z.real) * symmetry;

	z.real = radius * asin(angle) + c->real;
	z.imgn = radius * acos(angle) + c->imgn;
	return (z);
}

uint32_t	gc_j_x(t_complex z, t_occ *occlusion, t_fractal fractal)
{
	unsigned long	i;
	unsigned int	color;

	i = 0;
	color = 0;
	while (color == 0)
	{
		z = iterate_z_xmath(z, &fractal.c, fractal.symmetry);
		color = occlusion(z, i, fractal.depth);
		i++;
	}
	return (color);
}

uint32_t	gc_b_x(t_complex z, t_occ *occlusion, t_fractal fractal)
{
	unsigned long	i;
	unsigned int	color;

	fractal.c = z;
	i = 0;
	color = 0;
	while (color == 0)
	{
		z = iterate_z_xmath(z, &fractal.c, fractal.symmetry);
		color = occlusion(z, i, fractal.depth);
		i++;
	}
	return (color);
}
