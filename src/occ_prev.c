/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   occ_prev.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 15:50:31 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/19 15:51:17 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

inline unsigned int	blend_sub(t_threadstate thread *, t_complex z, t_complex prev, double mag, int end)
{
	const unsigned int	r = (unsigned int)(255.0 * (z.real - prev.real));
	const unsigned int	g = (unsigned int)(255.0 * (z.imgn - prev.imgn));
	const unsigned int	b = (unsigned int)(255.0 * mag / 8.0);
	const unsigned int	color = r << 24 | g << 16 | b << 8 | 0xFF;

	if (end)
		return (color ^ 0xFFFFFF00);
	return (color);
}

unsigned int	occ_sub(t_threadstate thread *, t_complex z, unsigned long i, long depth)
{
	static t_complex	prev[4];
	const double		magnitude = z.real * z.real + z.imgn * z.imgn;

	if (i == 0)
	{
		prev[thread->identity].imgn = 0;
		prev[thread->identity].real = 0;
	}
	if (i > (unsigned long) depth)
		return (blend_sub(z, prev[thread->identity], magnitude, 1));
	if (magnitude > 4)
		return (blend_sub(z, prev[thread->identity], magnitude, 0));
	prev[thread->identity] = z;
	return (0);
}

inline unsigned int	blend_angle(t_threadstate thread *, t_complex z, t_complex prev, int end)
{
	const double		radius = pow(z.real - prev.real, 2)
		+ pow(z.imgn - prev.imgn, 2);
	const unsigned int	r = CHAR_2PI * acos((z.real - prev.real) / radius);
	const unsigned int	g = CHAR_2PI * asin((z.imgn - prev.imgn) / radius);
	const unsigned int	b = CHAR_2PI
		* atan2((z.imgn - prev.imgn), (z.real - prev.real));
	const unsigned int	color = r << 24 | g << 16 | b << 8 | 0xFF;

	if (end)
		return (color ^ 0xFFFFFF00);
	return (color);
}

unsigned int	occ_angle(t_threadstate thread *, t_complex z, unsigned long i, long depth)
{
	static t_complex	prev[4];

	if (i == 0)
	{
		prev[thread->identity].imgn = 0;
		prev[thread->identity].real = 0;
	}
	if (i > (unsigned long) depth)
		return (blend_angle(z, prev[thread->identity], 1));
	if (z.real * z.real + z.imgn * z.imgn > 4)
		return (blend_angle(z, prev[thread->identity], 0));
	prev[thread->identity] = z;
	return (0);
}

unsigned int	occ_curse(t_threadstate thread *, t_complex z, unsigned long i, long depth)
{
	(void)thread;
	t_fractal	host;

	host.depth = depth / 4;
	if (i > (unsigned long) depth)
		return (0x000000FF);
	if (gc_b_2(z, &occ_cutoff, host) == 0xFFFFFFFF)
		return (0xFFFFFFFF);
	return (0);
}
