/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   occlusion.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 14:09:20 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/15 22:45:54 by mmosk         ########   odam.nl         */
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
