/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   occlusion.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 14:09:20 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/12 15:57:00 by mmosk         ########   odam.nl         */
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

inline unsigned int	blend_sub(t_complex z, t_complex prev, int end)
{
	const unsigned int	r = (unsigned int) (255.0 * (z.real - prev.real));
	const unsigned int	g = (unsigned int) (255.0 * (z.imgn - prev.imgn));
	const unsigned int	b = (r + g) / 2;
	const unsigned int	color = r << 24 | g << 16 | b << 8 | 0xFF;

	if (end)
		return (color ^ 0xFFFFFF00);
	return (color);
}

unsigned int	occ_sub(t_complex z, unsigned long i, long depth)
{
	static t_complex	prev;

	if (i == 0)
	{
		prev.imgn = 0;
		prev.real = 0;
	}
	if (i > (unsigned long) depth)
		return (blend_sub(z, prev, 1));
	if (z.real * z.real + z.imgn * z.imgn > 4)
		return (blend_sub(z, prev, 0));
	prev = z;
	return (0);
}

inline unsigned int	blend_angle(t_complex z, t_complex prev, int end)
{
	const double	radius = pow(z.real - prev.real, 2) + pow(z.imgn - prev.imgn, 2);
	const unsigned int	r = CHAR_2PI * acos((z.real - prev.real) / radius);
	const unsigned int	g = CHAR_2PI * asin((z.imgn - prev.imgn) / radius);
	const unsigned int	b = CHAR_2PI * atan((z.imgn - prev.imgn) / (z.real - prev.real));
	const unsigned int	color = r << 24 | g << 16 | b << 8 | 0xFF;

	if (end)
		return (color ^ 0xFFFFFF00);
	return (color);
}

unsigned int	occ_angle(t_complex z, unsigned long i, long depth)
{
	static t_complex	prev;

	if (i == 0)
	{
		prev.imgn = 0;
		prev.real = 0;
	}
	if (i > (unsigned long) depth)
		return (blend_angle(z, prev, 1));
	if (z.real * z.real + z.imgn * z.imgn > 4)
		return (blend_angle(z, prev, 0));
	prev = z;
	return (0);
}
