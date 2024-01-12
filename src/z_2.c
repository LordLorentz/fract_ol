/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   z_2.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 22:08:44 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/12 16:51:39 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static inline t_complex	iterate_z(t_complex z, t_complex *c)
{
	t_complex	next_z;

	next_z.real = pow(z.real, 2) - pow(z.imgn, 2) + c->real;
	next_z.imgn = 2 * z.real * z.imgn + c->imgn;
	return (next_z);
}

uint32_t	gc_j_2(t_complex z, t_occ *occlusion, t_fractal fractal)
{
	unsigned long	i;
	unsigned int	color;

	i = 0;
	color = 0;
	while (color == 0)
	{
		z = iterate_z(z, &fractal.c);
		color = occlusion(z, i, fractal.depth);
		i++;
	}
	return (color);
}

uint32_t	gc_b_2(t_complex z, t_occ *occlusion, t_fractal fractal)
{
	unsigned long	i;
	unsigned int	color;

	fractal.c = z;
	i = 0;
	color = 0;
	while (color == 0)
	{
		z = iterate_z(z, &fractal.c);
		color = occlusion(z, i, fractal.depth);
		i++;
	}
	return (color);
}
