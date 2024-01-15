/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   blend.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 15:50:31 by mmosk         #+#    #+#                 */
/*   Updated: 2024/01/15 22:45:59 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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
