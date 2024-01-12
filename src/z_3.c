/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   z_3.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/09 15:32:18 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/12 16:51:39 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static inline t_complex	iterate_z_bmath(t_complex z, t_complex *c)
{
	t_complex	next_z;

	next_z.real = pow(z.real, 3) - 3 * z.real * pow(z.imgn, 2) + c->real;
	next_z.imgn = 3 * pow(z.real, 2) * z.imgn - pow(z.imgn, 3) + c->imgn;
	return (next_z);
}

uint32_t	gc_j_3(t_complex z, t_occ *occlusion, t_fractal fractal)
{
	unsigned long	i;
	unsigned int	color;

	i = 0;
	color = 0;
	while (color == 0)
	{
		z = iterate_z_bmath(z, &fractal.c);
		color = occlusion(z, i, fractal.depth);
		i++;
	}
	return (color);
}

uint32_t	gc_b_3(t_complex z, t_occ *occlusion, t_fractal fractal)
{
	unsigned long	i;
	unsigned int	color;

	fractal.c = z;
	i = 0;
	color = 0;
	while (color == 0)
	{
		z = iterate_z_bmath(z, &fractal.c);
		color = occlusion(z, i, fractal.depth);
		i++;
	}
	return (color);
}
