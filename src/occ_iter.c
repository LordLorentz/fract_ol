/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   occ_iter.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 14:09:20 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/19 15:51:45 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

unsigned int	occ_cutoff(t_complex z, unsigned long i, long depth)
{
	if (i > (unsigned long) depth)
		return (0x000000FF);
	if (z.real * z.real + z.imgn * z.imgn > 4)
		return (0xFFFFFFFF);
	return (0);
}

inline unsigned int	blend_depth(long i, double magnitude, int end)
{
	const unsigned int	r = (unsigned int)(25.5 * i);
	const unsigned int	g = (unsigned int)(255.0 - 25.5 * -i);
	const unsigned int	b = (unsigned int)(255.0 * magnitude / 8.0);
	const unsigned int	color = r << 24 | g << 16 | b << 8 | 0xFF;

	if (end)
		return (color ^ 0xFFFFFF00);
	return (color);
}

unsigned int	occ_depth(t_complex z, unsigned long i, long depth)
{
	const double	magnitude = z.real * z.real + z.imgn * z.imgn;

	if (i > (unsigned long) depth)
		return (blend_depth((long)i, magnitude, 1));
	if (magnitude > 4)
		return (blend_depth((long)i, magnitude, 0));
	return (0);
}

unsigned int	occ_plane(t_complex z, unsigned long i, long depth)
{
	const double	magnitude = z.real * z.real + z.imgn * z.imgn;

	if (i > (unsigned long) depth)
		return (blend_depth((long)i, magnitude, 1));
	if (z.imgn > 2 || z.imgn < -2)
		return (blend_depth((long)i, magnitude, 0));
	return (0);
}

unsigned int	occ_beam(t_complex z, unsigned long i, long depth)
{
	const double	magnitude = z.real * z.real + z.imgn * z.imgn;

	if (i > (unsigned long) depth)
		return (blend_depth((long)i, magnitude, 1));
	if (z.real > 2 || z.real < -2)
		return (blend_depth((long)i, magnitude, 0));
	return (0);
}
