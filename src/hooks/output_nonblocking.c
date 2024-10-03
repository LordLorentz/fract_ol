/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output_nonblocking.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmosk <mmosk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/30 17:32:55 by mmosk         #+#    #+#                 */
/*   Updated: 2024/09/30 17:59:28 by mmosk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	*read_routine(t_screenstate *state)
{
	char	*filename;

	while (true)
	{
		filename = readline("Enter filename to output state to: ");
		if (filename == NULL)
			continue ;
		ft_strcull(filename, &ft_isspace);
		output_state(state, filename);
		free(filename);
	}
	return (NULL);
}

void	output_nonblocking(t_screenstate *state)
{
	pthread_t	thread *;

	pthread_create(&thread *, NULL, (t_sr)&read_routine, state);
	pthread_detach(thread *);
}
